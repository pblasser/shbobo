
   MEXPTOKE("wind","mul add","microphone",0x01,1)
  JEXPTOKE("finger","mul add","top finger fretted",0x01,1)
//MEXPTOKE("風","乘 加","return",0x01)
//MEXPTOKE("风","乘 加","return",0x01)
   MEXPTOKE("corp","mul add","antennae",0x02,2)
  JEXPTOKE("plank","mul add","all the frets' bits",0x02,2)
//MEXPTOKE("身","乘 加","return",0x2)
   MEXPTOKE("bar","mul add","barflex",0x04,4)
  JEXPTOKE("top","mul add","top knob",0x04,1)
JEXPTOKE("bot","mul add","bottom knob",0x05,1)
JEXPTOKE("heart","mul add","heart-shaped chambre",0x06,1)
JEXPTOKE("bridge","mul add","bridge of the strings",0x07,1)
//MEXPTOKE("把","乘 加","return",0x4)
   MEXPTOKE("minor","mul add","lower buttons",0x08,4)
   JEXPTOKE("brass","mul add","brass marked frets",0x08,4)
//MEXPTOKE("下","乘 加","return",0x08)
   MEXPTOKE("major","mul add","upper buttons",0x0C,4)
JEXPTOKE("steel","mul add","steel marked frets",0x0C,4)
//MEXPTOKE("上","乘 加","return",0x0C)

   MEXPTOKE("horn","nume deno mul add","triangle waveform",0x10,8)
//MEXPTOKE("角","増 限 乘 加","return",0x10)
   MEXPTOKE("saw","nume deno mul add","sawtooth waveform",0x18,8)
//MEXPTOKE("锯","増 限 乘 加","return",0x18)
//MEXPTOKE("鋸","増 限 乘 加","return",0x18)

   MEXPTOKE("toggle","trig mul add","trigger a flipflop",0x28,8)
//MEXPTOKE("对","触 乘 加","return",0x28)
//MEXPTOKE("對","触 乘 加","return",0x28)
   MEXPTOKE("togo","uptrig dntrig liszt","sequencer",0x20,8)
//MEXPTOKE("漸","触 表","return",0x20) 
//MEXPTOKE("渐","触 表","return",0x20)   

   MEXPTOKE("swoop","trig nume deno mul add","trigger a pyramid",0x30,8)
//MEXPTOKE("岡","触 増 限 乘 加","return",0x30)
//MEXPTOKE("崗","触 増 限 乘 加","return",0x30)
   MEXPTOKE("mount","nume deno mul add","slow triangle waveform",0x38,8)
//MEXPTOKE("山","増 限 乘 加","return",0x38)

   MEXPTOKE("smoke","mul add","random noise",0x40,8)
//MEXPTOKE("烟","乘 加","return",0x40)
//MEXPTOKE("煙","乘 加","return",0x40)
   MEXPTOKE("dust","speed mul add","random pulses",0x48,8)
//MEXPTOKE("塵","率 乘 加","return",0x44)
//MEXPTOKE("尘","率 乘 加","return",0x44)

   MEXPTOKE("fog","trig swnu swde honu hode mul add","trigger triangular grains",0x50,4)
//MEXPTOKE("雾","触 増 限 増 限 乘 加","return",0x50)
   MEXPTOKE("haze","trig swnu swde sanu sade mul add","trigger sawtooth grains",0x58,4)
//MEXPTOKE("岚","触 増 限 増 限 乘 加","return",0x58)
   MEXPTOKE("swamp","trig swnu swde honu hode mul add","trigger swooping grains",0x54,4)
//MEXPTOKE("沼","触 増 限 増 限 乘 加","return",0x54)

   MEXPTOKE("string","trig nume deno fb mul add","trigger a pluckd string",0x60,4) //square nume deno fb mul add
//MEXPTOKE("弦","触 増 限 乘 加","return",0x60)
   MEXPTOKE("comb","inn nume deno fb mul add","input sound to the string",0x64,4) //inn num den fb mul add
//MEXPTOKE("梳","入 増 限 乘 加","return",0x64,)
   MEXPTOKE("zither","trig deno mul add","trigger a bunch strings",0x68,4) //square dna mul add
//MEXPTOKE("琴","触 限 乘 加","return",0x68)

   MEXPTOKE("wave","inn q rate mul add","low pass filter",0x70,8)
//MEXPTOKE("波","入 声 率 乘 加","return",0x70)
   MEXPTOKE("water","trig q rate mul add","trigger a cluster of waves",0x78,4)
//MEXPTOKE("水","触 声 率 乘 加","return",0x78)
   MEXPTOKE("salt","inn q rate mul add","hi pass filter",0x7C,4)
//MEXPTOKE("塩","触 声 率 乘 加","return",0x7C)
//MEXPTOKE("盐","触 声 率 乘 加","return",0x7C)

   MEXPTOKE("horse","upnu dnnu upde dnde mul add","variable duty sawtri",0x80,4)
//MEXPTOKE("匹","昇 降 昇 降 乘 加","return",0x80)

   MEXPTOKE("slew","inn upp don mul add","filter a signal with different up and down rates",0x90,8)
//MEXPTOKE("容","入 昇 降 乘 加","return",0x90)
   MEXPTOKE("wheel","upp don mul add","input numbers to bring the value up or down",0x98,8)
//MEXPTOKE("轮","昇 降 乘 加","return",0x98)
//MEXPTOKE("輪","昇 降 乘 加","return",0x98)

   MEXPTOKE("slave","trig deno mul add","count pulses by variable integer amount",0xA0,8)
   MEXPTOKE("pulse","trig deno mul add","trigger a pulse and decay with variable height",0xA8,8)

   MEXPTOKE("sauce","per inn mul add","slow down an input by a period",0xB0,8)
//MEXPTOKE("酱","期 入 乘 加","return",0xB0)
//MEXPTOKE("醬","期 入 乘 加","return",0xB0)
   MEXPTOKE("salsa","trig inn mul add","selectively trigger an input",0xB8,8)
//MEXPTOKE("萨","触 入 乘 加","return",0xB4)
//MEXPTOKE("薩","触 入 乘 加","return",0xB4)


   JEXPTOKE("melody","gate inn nume skip mul add","record and repeat melodies",0xC0,4)
   JEXPTOKE("worm","inn mul add","rectify and hold an input, like an envelope generator",0xC4,4)
   JEXPTOKE("scale","inn mul add","convert frets to exponential (musical) pitch",0xC8,4)
   JEXPTOKE("ladder","inn liszt","traverse a list of 32 according to input",0xCC,4)


   MEXPTOKE("press","inn att dec thresh mul add","compressor",0xE0,4) //inn att dec thresh mul add
//MEXPTOKE("圧","mul add","return",0xE0)
//MEXPTOKE("压","mul add","return",0xE0)
   MEXPTOKE("leak","inn nume mul add","leak DC from a sound",0xE4,4)
//MEXPTOKE("泄","mul add","return",0xE4)
   MEXPTOKE("reflect","inn oth mul add","waveshaper that reflects",0xE8,1)
//MEXPTOKE("暎","入 它 乘 加","return",0xE8)
//MEXPTOKE("映","入 它 乘 加","return",0xE8)
   MEXPTOKE("return","inn oth mul add","waveshaper that returns",0xE8+1,1)
//MEXPTOKE("復","入 它 乘 加","return",0xE8+1)
//MEXPTOKE("复","入 它 乘 加","return",0xE8+1)
   MEXPTOKE("and","inn oth mul add","bitwise and of two signals",0xEA,1)
//MEXPTOKE("和","入 它 乘 加","return",0xEA)
   MEXPTOKE("xor","inn oth mul add","bitwise xor of two signals",0xEB,1)
//MEXPTOKE("或","入 它 乘 加","return",0xEB)

   MEXPTOKE("negwon","","return negative one",0xF2,1)
//MEXPTOKE("阴","","return",0xF2)	
//MEXPTOKE("陰","","return",0xF2)	
   MEXPTOKE("left","liszt","send sound out the left",0xF0,1)
//MEXPTOKE("左","表","return",0xF0)
   MEXPTOKE("right","liszt","send sound out the right",0xF1,1)
//MEXPTOKE("右","表","return",0xF1)
   MEXPTOKE("square","inn oth mul add","make an input into a square, compared against an optional other",0xF2,1) //square inn ref negwon
//MEXPTOKE("方","入 它 乘 加","return",0xF2)  
   MEXPTOKE("modo","inn mod mul add","multiply without scaling",0xF3,1)
//MEXPTOKE("规","入 模 乘 加","return",0xF3)
//MEXPTOKE("規","入 模 乘 加","return",0xF3)
   MEXPTOKE("srate","inn","change the sample rate!",0xF4,1)
//MEXPTOKE("律","入","return",0xF4)
   MEXPTOKE("mul","inn mul add","multiply scaling",0xF5,1)
//MEXPTOKE("乘","入 乘 加","return",0xF5)
//MEXPTOKE("乗","入 乘 加","return",0xF5)
   MEXPTOKE("add","liszt","add a liszt",0xF6,1)//now is dirac!!!
//MEXPTOKE("加","表","return",0xF6)
   MEXPTOKE("tar","mul add","tarbutton",0xF7,1)
//MEXPTOKE("油","乘 加","return",0xF7)
   
//MEXPTOKE("橙","入","return",0xFB)
   MEXPTOKE("bend","inn","bend through the fish soup",0xF8,1)
//MEXPTOKE("曲","入",("return",0xF8))
   MEXPTOKE("jump","trig","trigger a jump to another soup",0xF8+1,1)   
//MEXPTOKE("跳","触","return",0xF8+1,1)
   MEXPTOKE("pan","inn place","send sound out spatialized",0xFA,1)
//MEXPTOKE("簫","入 所","return",0xFA)
//MEXPTOKE("箫","入 所","return",0xFA)
   MEXPTOKE("short","bigg smal","sixteen bit precision number",0xFB,1)
//MEXPTOKE("短","大 小","return",0xFB)

   MEXPTOKE("dirac","liszt","default, execute using negative numbers",0xFC,1)
//MEXPTOKE("狄","表","return",0xFC)
   MEXPTOKE("arab","liszt","esoteric, execute using no negatives",0xFD,1)
//MEXPTOKE("阿","表","return",0xFD)
   MEXPTOKE("lights","inn","put an input to the LEDs",0xFE,1)
//MEXPTOKE("光","入","return",0xFE)

//MEXPTOKE("甲","","return",0x0)
//MEXPTOKE("乙","","return",0x1)
//MEXPTOKE("丙","","return",0x2)
//MEXPTOKE("丁","","return",0x3)
//MEXPTOKE("戊","","return",0x4)
//MEXPTOKE("己","","return",0x5)
//MEXPTOKE("庚","","return",0x6)
//MEXPTOKE("辛","","return",0x6+1)
//   MEXPTOKE("a","","return",0x00)
//   MEXPTOKE("b","","return",0x01)
//   MEXPTOKE("c","","return",0x02)
//   MEXPTOKE("d","","return",0x03)
//   MEXPTOKE("e","","return",0x04)
//   MEXPTOKE("f","","return",0x05)
//   MEXPTOKE("g","","return",0x06)
//   MEXPTOKE("h","","return",0x06+1)