@SHNTH ASSEMBLAGE 
@COPYRIGHT SHBOBO

.macro USBX
@ cpsie i
 bx lr
.endm

@ cpsid i
 SYNTHLOAD r1, USB_ISTR
 ldrh r2, [r1]
 tst r2, 0x0400
 bne Resetus
 tst r2, 0x8000
 bne Cortran
 mov r0, 0x00 @OTHERWISE CLEAR FLAGSz
 strh r0, [r1] @R1 persistsz
 USBX

Resetus: 
 LODESTRAH USB_ISTR, 0
 LODESTRAH USB_CNTR, 0x8400
 SETUPACKETS
 ARMEP0
 ARMEP1PHIRST
 LODESTRAH USB_DADDR, 0x80 
 SYNTHLOADER r1, USB_USWSTAT
 mov r0, DEFAULT_STATE
 strb r0, [r1]
 USBX

Cortran:
 SYNTHLOAD r1, USB_ISTR
 ldr r1, [r1]
 and r2, r1, 0x000F
 cmp r2, 0x0
 beq Zerous
 cmp r2, 0x1 
 beq Unious
 USBX

Zerous: @activity on ep0
 tst r1, 0x0010
 bne Zeroutus @from host POV, RX atmine
 beq Zeroinus
 ARMEP0
 USBX

Zeroutus:
 SYNTHLOAD r1, USB_EP0R
 ldr r1, [r1]
 tst r1, 0x0800
 bne Zersetpus
 beq Zeroto
 
Zersetpus:
 SYNTHLOAD r1, USB_0_RX
 SYNTHLOADER r12, USB_report_bmRequestType
 .rept 4
 ldrb r0, [r1], 1
 strb r0, [r12], 1
 ldrb r0, [r1], 3
 strb r0, [r12], 1
 .endr

 mov r0, NO_REQUEST
 SYNTHLOADER r1, USB_dev_req
 strb r0, [r1]

 SYNTHLOADER r12, USB_report_bmRequestType
 ldrb r0, [r12]

 and r2, r0, 0x60 @bmRequestType
 cmp r2, 0x00
 beq StandardRequestus
 cmp r2, 0x20
 beq ClassRequestus
 cmp r2, 0x40
 beq VendorRequestus
 STALLEP0
 USBX

 bRequest .req r0
StandardRequestus:
 SYNTHLOADER r12, USB_report_bRequest
 ldrb r0, [r12]
 cmp bRequest, GET_STATUS
 beq GetStatus
 cmp bRequest, CLEAR_FEATURE
 beq ClearFeature
 cmp bRequest, SET_FEATURE
 beq SetFeature
 cmp bRequest, SET_ADDRESS
 beq SetAddress
 cmp bRequest, GET_DESCRIPTOR
 beq GetDescriptor
 cmp bRequest, GET_CONFIGURATION
 beq GetConfiguration
 cmp bRequest, SET_CONFIGURATION
 beq SetConfiguration
 cmp bRequest, GET_INTERFACE
 beq GetInterface
 cmp bRequest, SET_INTERFACE
 beq SetInterface
 STALLEP0
 ARMEP0
 USBX

GetStatus:
 SYNTHLOADER r12, USB_report_bmRequestType
 ldrb r0, [r12]
 and r2, r0, #0x1F
 cmp r2, #0x00
 beq GetStatusRecipientDevice
 cmp r2, #0x01
 beq GetStatusRecipientInterface
 cmp r2, #0x02
 beq GetStatusRecipientEndpoint
 @other recipients
 STALLEP0
 USBX

GetStatusRecipientDevice:
 @no remote wakeup
 LODESTRA USB_0_TX, 0
 LODESTRA USB_COUNT0_TX, 2
 ARMEP0
 USBX

GetStatusRecipientInterface:
 SYNTHLOADER r1, USB_USWSTAT
 ldrb r1, [r1]
 cmp r1, CONFIG_STATE
 beq GetStatusRecipientInterfaceConfigd
 STALLEP0
 USBX
 
GetStatusRecipientInterfaceConfigd:
 @no remote wakeup
 LODESTRA USB_0_TX, 0
 LODESTRA USB_COUNT0_TX, 2
 ARMEP0
 USBX

GetStatusRecipientEndpoint:
 SYNTHLOAD r1, USB_0_TX
 SYNTHLOAD r2, USB_EP0R
 ldrh r2, [r2]
 and r2, #0x0030
 cmp r2, #0x0010 @stall on TX
 ite eq
 moveq r0, 0x01 @HALT cond
 movne r0, 0x00
 strh r0, [r1]
 LODESTRA USB_COUNT0_TX, 2
 ARMEP0 
 USBX

ClearFeature:
SetFeature:
 @SYSTICKONN
 ZILP
 ARMEP0
 USBX

SetAddress:
 SYNTHLOADER r1, USB_dev_req
 SYNTHLOADER r12, USB_report_bRequest
 ldrb r0, [r12]
 strb r0, [r1]
 SYNTHLOADER r1, USB_address_pending
 SYNTHLOADER r12, USB_report_wValue
 ldrb r0, [r12]
 strb r0, [r1]  @store addy from wval in pender
 ZILP
 ARMEP0
 USBX

wValueHigh .req r0
GetDescriptor:
 SYNTHLOADER r1, USB_dev_req
 SYNTHLOADER r12, USB_report_bRequest
 ldrb r0, [r12]
 strb r0, [r1] 
 SYNTHLOADER r12, USB_report_wValueHigh
 ldrb r0, [r12]
 SYNTHLOADER r12, USB_report_wLength
 ldrb r3, [r12]
 cmp wValueHigh, DEVICE_DESC 
 beq GetDeviceDescriptor
 cmp wValueHigh, CONFIG_DESC
 beq GetConfigurationDescriptor
 cmp wValueHigh, STRING_DESC
 beq GetStringDescriptor
 cmp wValueHigh, HID_DESC
 beq GetHIDDescriptor
 cmp wValueHigh, REPORT_DESC
 beq GetReportDescriptor
 cmp wValueHigh, 0x06
 beq GetSchwonz
 SYNTHLOADER r1, USB_dev_req
 mov r2, NO_REQUEST
 strb r2, [r1] 
 STALLEP0 
 USBX

@r3 is wLength
GetSchwonz:
 ldr r0, =Device_Qualifier
 SYNTHLOADER r1, USB_desc_ptr
 str r0, [r1]
 ldrb r2, [r0] @whatis len, th'first byte
 cmp r2, r3 @cmp my len aganst wLen
 it gt @if gt, 
 movgt r2, r3 @mov wLen to r2
 SYNTHLOADER r1, USB_bytes_left
 strb r2, [r1]
 b SendDescriptorPacket

GetDeviceDescriptor:
 ldr r0, =Device
 SYNTHLOADER r1, USB_desc_ptr
 str r0, [r1]
 ldrb r2, [r0] @whatis len, th'first byte
 cmp r2, r3 @cmp my len aganst wLen
 it gt @if gt, 
 movgt r2, r3 @mov wLen to r2
 SYNTHLOADER r1, USB_bytes_left
 strb r2, [r1]
 b SendDescriptorPacket

GetConfigurationDescriptor:
 SYNTHLOADER r12, USB_report_wValue
 ldrb r0, [r12]
 cmp r0,0
 beq GetConfigurationDescriptorSend
 STALLEP0 @otherwise
 USBX

GetConfigurationDescriptorSend:
 ldr r0, =Configuration1
 SYNTHLOADER r1, USB_desc_ptr
 str r0, [r1]
 ldrb r2, [r0, 2]
 mov r2, 0x29
 cmp r2, r3
 it gt @if gt, 
 movgt r2, r3 
 SYNTHLOADER r1, USB_bytes_left
 strb r2, [r1]
 b SendDescriptorPacket

GetStringDescriptor:
 SYNTHLOADER r12, USB_report_wValue
 ldrb r0, [r12]
 cmp r0, 0
 itt eq
 ldreq r1, = String0
 beq GetStringDescriptorSend
 cmp r0, 1
 itt eq
 ldreq r1, = String1
 beq GetStringDescriptorSend
 cmp r0, 2
 itt eq
 ldreq r1, = String2
 beq GetStringDescriptorSend
 STALLEP0 @otherwise
 USBX

@r3 should still be wLength
GetStringDescriptorSend:
 SYNTHLOADER r2, USB_desc_ptr
 str r1, [r2]
 ldrb r2, [r1]
 cmp r2, r3
 it gt @if gt, 
 movgt r2, r3 @mov wvalue to r2
 SYNTHLOADER r1, USB_bytes_left
 strb r2, [r1]
 b SendDescriptorPacket

GetHIDDescriptor:
 ldr r0, = HID1
 SYNTHLOADER r1, USB_desc_ptr
 str r0, [r1]
 ldrb r2, [r0]
 cmp r2, r3 @both are jus'bytes
 it gt @if gt, 
 movgt r2, r3 
 SYNTHLOADER r1, USB_bytes_left
 strb r2, [r1]
 b SendDescriptorPacket

GetReportDescriptor:
 ldr r0, =Report1
 SYNTHLOADER r1, USB_desc_ptr
 str r0, [r1]
 mov r2, (Report2 - Report1)
 @mov r2, REPOLEN
 cmp r2, r3 @both are jus'bytes
 it gt @if gt, 
 movgt r2, r3 
 SYNTHLOADER r1, USB_bytes_left
 strb r2, [r1]
 b SendDescriptorPacket

GetConfiguration:
 SYNTHLOAD r1, USB_0_TX
 SYNTHLOADER r2, USB_curr_config
 ldrb r2, [r2]
 strb r2, [r1]
 LODESTRA USB_COUNT0_TX, 1
 ARMEP0
 USBX

SetConfiguration:
 ZILP
 ARMEP0
 SYNTHLOADER r1, USB_curr_config
 SYNTHLOADER r12, USB_report_wValue
 ldrb r0, [r12]
 strb r0, [r1]
 cmp r0, 0
 bne SetConfigurationTruly
 mov r0, ADDRESS_STATE
 SYNTHLOADER r1, USB_USWSTAT
 strb r0, [r1]
 USBX

SetConfigurationTruly:
 mov r0, CONFIG_STATE
 SYNTHLOADER r1, USB_USWSTAT
 strb r0, [r1]
 GWONZULATE1 
 USBX

GetInterface:
 SYNTHLOADER r12, USB_report_wIndex
 ldrb r0, [r12]
 cmp r0, 0
 beq GetInterfaceTruly
 STALLEP0
 USBX
 
GetInterfaceTruly:
 LODESTRA USB_0_TX, 0
 @zero send back
 LODESTRA USB_COUNT0_TX, 1
 ARMEP0
 USBX

SetInterface:
 SYNTHLOADER r1, USB_USWSTAT
 ldrb r1, [r1]
 SYNTHLOADER r12, USB_report_wIndex
 ldrb r0, [r12]
 cmp r1, CONFIG_STATE
 itt eq
 cmpeq r0, 0
 beq SetInterfaceTruly
 STALLEP0
 USBX

SetInterfaceTruly:
 SYNTHLOADER r1, USB_bAlternateSetting
 SYNTHLOADER r12, USB_report_wValue
 ldrb r0, [r12]
 @strb r0, [r1]
 cmp r0, 0
 @it eq
 beq SetInterfaceTrulyZero
 STALLEP0
 USBX
 
SetInterfaceTrulyZero:
 ZILP
 @this zilp was new
 ARMEP0
 USBX

ClassRequestus:
 SYNTHLOADER r12, USB_report_bRequest
 ldrb r0, [r12]
 cmp bRequest, GET_REPORT
 beq GetReport
 cmp bRequest, SET_REPORT
 beq SetReport
 cmp bRequest, GET_PROTOCOL
 beq GetProtocol
 cmp bRequest, SET_PROTOCOL
 beq SetProtocol
 cmp bRequest, GET_IDLE
 beq GetIdle
 cmp bRequest, SET_IDLE
 beq SetIdle
 STALLEP0
 USBX

GetReport:
 @SYNTHLOADER r1, USB_dev_req
 @SYNTHLOADER r12, USB_report_bRequest
 @ldrb r0, [r12]
 @strb r0, [r1]
 @ZILP
 @ARMEP0
 SYNTHLOADER r0, USB_lisprog_loke
 mov r1, 0
 str r1, [r0]
 SYSTICKONN
 cpsie i
 @USBX
 GWONZULATE0
 ARMEP0
 USBX

SetReport:
 TURNDON
 SYNTHLOADER r1, USB_dev_req
 SYNTHLOADER r12, USB_report_bRequest
 ldrb r0, [r12]
 strb r0, [r1]
 ZILP
 @this ZILP was new
 ARMEP0
 USBX

@@@@check this getprotocol
GetProtocol:
 SYNTHLOAD r1, USB_0_TX
 SYNTHLOADER r2, USB_protocol
 mov r2, 0
 @ldrb r2, [r2]
 strb r2, [r1]
 LODESTRA USB_COUNT0_TX, 1
 @ZILP
 ARMEP0
 USBX

SetProtocol:
 SYNTHLOADER r1, USB_protocol
 SYNTHLOADER r12, USB_report_wValue
 ldrb r0, [r12]
 @strb r0, [r1]
 ZILP
 ARMEP0
 USBX

GetIdle:
 SYNTHLOAD r1, USB_0_TX
 SYNTHLOADER r2, USB_idle_rate
 ldrb r2, [r2]
 strb r2, [r1]
 LODESTRA USB_COUNT0_TX, 1
 ARMEP0
 USBX

SetIdle:
 SYNTHLOADER r1, USB_idle_rate
 SYNTHLOADER r12, USB_report_wValueHigh
 ldrb r0, [r12]
 strb r0, [r1]
 ZILP
 ARMEP0
 USBX

VendorRequestus:
 ARMEP0
 USBX

Zeroinus:
 SYNTHLOADER r1, USB_dev_req
 ldrb r1, [r1]
 cmp r1, SET_ADDRESS
 beq InSetAddress
 cmp r1, GET_DESCRIPTOR
 beq SendDescriptorPacket
 @cmp r1, GET_REPORT
 @beq GetFeatureset
 ZILP
 ARMEP0
 USBX

InSetAddress:
 SYNTHLOADER r1, USB_address_pending
 ldrb r1, [r1]
 orr r2, r1, 0x80
 SYNTHLOAD r3, USB_DADDR
 strh r2, [r3]
 cmp r1, 0
 ite eq
 moveq r0, DEFAULT_STATE
 movne r0, ADDRESS_STATE
 SYNTHLOADER r1, USB_USWSTAT
 strb r0, [r1]
 ZILP
 ARMEP0
 USBX

@not used anymore
GetFeatureset:
 ZILP
 ARMEP0
 SYSTICKONN
 cpsie i
 USBX

Zeroto:
 SYNTHLOADER r1, USB_dev_req
 ldrb r1, [r1]
 cmp r1, SET_REPORT
 beq Lisprog
 ZILP
 ARMEP0
 USBX
Lisprog:
.include "usb_lisprog.s"
 
Unious:
 tst r1, 0x0010
 bne Unoutus @from host POV, RX atmine
 beq Unoinus
 ARMEP1
 USBX
Unoutus:
 ARMEP1
 USBX
Unoinus:
 GWONZULATE1
 ARMEP1
 USBX

SendDescriptorPacket:
 SYNTHLOADER r1, USB_bytes_left
 ldrb r2, [r1] 
 mov r3, 8 @r3 isz now paketlen
 cmp r2, 8
 itttt lt
 ldrlt r3, =USB_dev_req
 movlt r0, NO_REQUEST
 strblt r0, [r3]
 movlt r3, r2
 sub r2, r2, r3 
 strb r2, [r1]
 SYNTHLOAD r1, USB_COUNT0_TX
 strh r3, [r1]
 SYNTHLOADER r12, USB_desc_ptr 
 ldr r1, [r12]
 SYNTHLOAD r2, USB_0_TX
 .rept 4
  ldrh r3, [r1], 2
  strh r3, [r2], 4
 .endr
 str r1, [r12]
 ARMEP0
 USBX
.ltorg

Device_Qualifier:
.byte   0x0A, 0x06  @ bLength, bDescriptorType
 @.byte   0x00, 0x02
.byte 0x10, 0x01 @ bcdUSB (low byte) (high byte)
.byte 0x00, 0x00 @ bDeviceClass, bDeviceSubClass
.byte 0x00, 0x08 @ bDeviceProtocl, bMaxPacketSize
.byte 0x01, 0x00 @bNumConfigurations
Device:
.byte 0x12, DEVICE_DESC @bLength, bDescriptorType
.byte 0x10, 0x01 @bcdUSB
.byte 0x00, 0x00 @bDeviceClass,bDeviceSubClass
.byte 0x00, 0x08 @bDeviceProtocl,bMaxPacketSize
.byte 0x66, 0x66 @idVendor
.ifeq SHBOBO
.byte 0x66, 0x66 @idProduct
.else
.byte 0x77, 0x77 @idProduct
.endif
.byte 0x02, 0x00 @bcdDevice
.byte 0x01, 0x02 @iManufacturer, iProductString
.byte 0x00, 0x01 @iSerialNumber, bNumConfigs
Configuration1:
.byte 0x09, CONFIG_DESC @bLength, bDescriptorType
.byte 0x29, 0x00 @wTotalLength lohi
.byte 0x01, 0x01 @bNumInterfaces,bConfigurationValue
.byte 0x00, 0xc0 @iConfiguration (none), bmAttributes
@bmattributes bit 7 set means _default is it 80 or C0?
.byte 0x22 @bMaxPower (100 mA)
Interface1:
.byte 0x09, INTERF_DESC @ bLength, bDescriptorType
.byte 0x00, 0x00 @ bInterfaceNumber, bAlternateSetting
.byte 0x02, 0x03 @should be 1 not 2?
@bNumEndpoints (excluding EP0), bInterfaceClass(HID)
.byte 0x00, 0x00 @ bInterfaceSubClass, bInterfaceProtocol
.byte 0x00 @ iInterface (none)
HID1:
.byte 0x09, HID_DESC @ bLength, bDescriptorType
.byte 0x11, 0x01 @ bcdHID lohi was 1001
.byte 0x00, 0x01 @bCountryCode, bNumDescriptors
.byte REPORT_DESC, Report2-Report1  
@ bDescriptorType, wDescriptorLength (low byte)
.byte   0x00 @ wDescriptorLength (high byte) 
Endpoint1in:
.byte  0x07, ENDPOI_DESC @ bLength, bDescriptorType
.byte  0x81, 0x03 
@bEndpointAddress (EP1 IN), bmAttributes (Interrupt)
.byte 0x08, 0x00 
@wMaxPacketSize (low byte), wMaxPacketSize (high byte)
 .byte  0x01   @ bInterval (10 ms)
Endpoint1out:
 .byte   0x07, ENDPOI_DESC @ bLength, bDescriptorType
 .byte   0x01, 0x03 
@ bEndpointAddress (EP1 OUT), bmAttributes (Interrupt)
 .byte   0x08, 0x00 
@ wMaxPacketSize (low byte), wMaxPacketSize (high byte)
 .byte   0x01 @ bInterval
String0:
 .byte String1-String0, STRING_DESC @bLength,bType
 .byte 0x09, 0x04   @ wLANGID lohi
String1:
.byte String2-String1, STRING_DESC @bLength,bType 
.byte 'S', 0x00
.byte 'H', 0x00
.byte 'B', 0x00
.byte 'O', 0x00
.byte 'B', 0x00
.byte 'O', 0x00
String2:
.byte Report1-String2, STRING_DESC @bLength,bType
.ifeq SHBOBO
.byte 'S', 0x00
.byte 'H', 0x00
.byte 'N', 0x00
.byte 'T', 0x00
.byte 'H', 0x00
.else 
.byte 'S', 0x00
.byte 'H', 0x00
.byte 'T', 0x00
.byte 'A', 0x00
.byte 'R', 0x00
.endif


Report1:
.byte 0x05, 0x01 @ Usage Page (Generic Desktop),
.byte 0x09, 0x05 @ Usage (gamepad)
.byte 0xA1, 0x01   @ Collection (Application)
 
.ifeq SHBOBO
.byte 0x19, 0x30 @usage min      
.byte 0x29, 0x36 @usage max
.byte 0x15, 0x80 @logic min
.byte 0x25, 0x7F @logic max
.byte 0x75, 0x08 @Report Size 
.byte 0x95, 0x07 @Report Count 
.byte 0x81, 0x02 @Input (Data, Variable, Absolute)

.byte 0x05, 0x09 @Usage button  
.byte 0x19, 0x01 @usage min
.byte 0x29, 0x08 @usage max
.byte 0x15, 0x00 @logic min
.byte 0x25, 0x01 @logic max
.byte 0x75, 0x01 @Report Size 
.byte 0x95, 0x08 @Report Count
.byte 0x81, 0x02 @Input (Data, Variable, Absolute),

.else
.byte 0x19, 0x30 @usage min      
.byte 0x29, 0x37 @usage max
.byte 0x15, 0x80 @logic min
.byte 0x25, 0x7F @logic max
.byte 0x75, 0x08 @Report Size 
.byte 0x95, 0x08 @Report Count 
.byte 0x81, 0x02 @Input (Data, Variable, Absolute)
.endif

.byte 0x09, 0x01 @usage min
.byte 0x75, 0x08 @report siz 8
.byte 0x95, 0x08 @report dur 8
.byte 0xB1, 0x02 @feature DVR
 
.byte   0xC0    @ End Collection     
Report2:
.byte 0
.align
