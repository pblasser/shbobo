import java.util.ArrayList;
import java.util.Iterator;

public class GrubFactory {
   public ArrayList<Grub> ecole;
   GrubFactory() {
      ecole = new ArrayList<Grub>();
      make();
   }
   private void MEXPTOKE(String name,String args, String tooltip, int code, int n) {
      ecole.add(new Grub(name));
   }
   private void JEXPTOKE(String name,String args, String tooltip, int code, int n) {
      ecole.add(new Grub(name));
   }
   public ArrayList<Grub> make() {



   MEXPTOKE("wind","mul add","microphone",0x01,1);
  JEXPTOKE("finger","mul add","top finger fretted",0x01,1);
   MEXPTOKE("corp","mul add","antennae",0x02,2);
  JEXPTOKE("plank","mul add","all the frets' bits",0x02,2);
   MEXPTOKE("bar","mul add","barflex",0x04,4);
  JEXPTOKE("top","mul add","top knob",0x04,1);
JEXPTOKE("bot","mul add","bottom knob",0x05,1);
JEXPTOKE("heart","mul add","heart-shaped chambre",0x06,1);
JEXPTOKE("bridge","mul add","bridge of the strings",0x07,1);
   MEXPTOKE("minor","mul add","lower buttons",0x08,4);
   JEXPTOKE("brass","mul add","brass marked frets",0x08,4);
   MEXPTOKE("major","mul add","upper buttons",0x0C,4);
JEXPTOKE("steel","mul add","steel marked frets",0x0C,4);

   MEXPTOKE("horn","nume deno mul add","triangle waveform",0x10,8);
   MEXPTOKE("saw","nume deno mul add","sawtooth waveform",0x18,8);

   MEXPTOKE("toggle","trig mul add","trigger a flipflop",0x28,8);
   MEXPTOKE("togo","uptrig dntrig liszt","sequencer",0x20,8);

   MEXPTOKE("swoop","trig nume deno mul add","trigger a pyramid",0x30,8);
   MEXPTOKE("mount","nume deno mul add","slow triangle waveform",0x38,8);

   MEXPTOKE("smoke","mul add","random noise",0x40,8);
   MEXPTOKE("dust","speed mul add","random pulses",0x48,8);

   MEXPTOKE("fog","trig swnu swde honu hode mul add","trigger triangular grains",0x50,4);
   MEXPTOKE("haze","trig swnu swde sanu sade mul add","trigger sawtooth grains",0x58,4);
   MEXPTOKE("swamp","trig swnu swde honu hode mul add","trigger swooping grains",0x54,4);

   MEXPTOKE("string","trig nume deno fb mul add","trigger a pluckd string",0x60,4);    MEXPTOKE("comb","inn nume deno fb mul add","input sound to the string",0x64,4);    MEXPTOKE("zither","trig deno mul add","trigger a bunch strings",0x68,4); 
   MEXPTOKE("wave","inn q rate mul add","low pass filter",0x70,8);
   MEXPTOKE("water","trig q rate mul add","trigger a cluster of waves",0x78,4);
   MEXPTOKE("salt","inn q rate mul add","hi pass filter",0x7C,4);

   MEXPTOKE("horse","upnu dnnu upde dnde mul add","variable duty sawtri",0x80,4);

   MEXPTOKE("slew","inn upp don mul add","filter a signal with different up and down rates",0x90,8);
   MEXPTOKE("wheel","upp don mul add","input numbers to bring the value up or down",0x98,8);

   MEXPTOKE("gear","trig deno mul add","count pulses by variable integer amount",0xA0,8);
   MEXPTOKE("pulse","trig deno mul add","trigger a pulse and decay with variable height",0xA8,8);

   MEXPTOKE("sauce","per inn mul add","slow down an input by a period",0xB0,8);
   MEXPTOKE("salsa","trig inn mul add","selectively trigger an input",0xB8,8);


   JEXPTOKE("melody","gate inn nume skip mul add","record and repeat melodies",0xC0,4);
   JEXPTOKE("worm","inn mul add","rectify and hold an input, like an envelope generator",0xC4,4);
   JEXPTOKE("scale","inn mul add","convert frets to exponential (musical); pitch",0xC8,4);
   JEXPTOKE("ladder","inn liszt","traverse a list of 32 according to input",0xCC,4);


   MEXPTOKE("press","inn att dec thresh mul add","compressor",0xE0,4);    MEXPTOKE("leak","inn nume mul add","leak DC from a sound",0xE4,4);
   MEXPTOKE("reflect","inn oth mul add","waveshaper that reflects",0xE8,1);
   MEXPTOKE("return","inn oth mul add","waveshaper that returns",0xE8+1,1);
   MEXPTOKE("and","inn oth mul add","bitwise and of two signals",0xEA,1);
   MEXPTOKE("xor","inn oth mul add","bitwise xor of two signals",0xEB,1);

   MEXPTOKE("negwon","","return negative one",0xF2,1);
   MEXPTOKE("left","liszt","send sound out the left",0xF0,1);
   MEXPTOKE("right","liszt","send sound out the right",0xF1,1);
   MEXPTOKE("square","inn oth mul add","make an input into a square, compared against an optional other",0xF2,1);    MEXPTOKE("modo","inn mod mul add","multiply without scaling",0xF3,1);
   MEXPTOKE("srate","inn","change the sample rate!",0xF4,1);
   MEXPTOKE("mul","inn mul add","multiply scaling",0xF5,1);
   MEXPTOKE("add","liszt","add a liszt",0xF6,1);   MEXPTOKE("tar","mul add","tarbutton",0xF7,1);
   
   MEXPTOKE("bend","inn","bend through the fish soup",0xF8,1);
   MEXPTOKE("jump","trig","trigger a jump to another soup",0xF8+1,1);   
   MEXPTOKE("pan","inn place","send sound out spatialized",0xFA,1);
   MEXPTOKE("short","bigg smal","sixteen bit precision number",0xFB,1);

   MEXPTOKE("dirac","liszt","default, execute using negative numbers",0xFC,1);
   MEXPTOKE("arab","liszt","esoteric, execute using no negatives",0xFD,1);
   MEXPTOKE("lights","inn","put an input to the LEDs",0xFE,1);

   return ecole;
}
}
