

(
// a SynthDef
SynthDef(\test, { | out, rat = 440, amp = 1, nharms = 10, pan = 0, gate = 1 |
	var gorq = 495/8;
var r = 2.0**(rat/17);
    var audio = Blip.ar(gorq*r, nharms, amp);
    var env = Linen.kr(gate, doneAction: 2);

   Out.ar(out, audio*env);
}).add;

 SynthDef(
	\Mog,
	{ |oscType =0, oscType2 = 1, pan = 0, level = 0.5, cutoff = 500, gain = 3.3, attack = 0.1, decay = 0.1, sust = 0.7, rel = 0.2, attackf = 0.1, decayf = 0.1, sustf = 0.9, relf = 0.2, gate = 1, freq =440, lagLev = 100 |

var ampEnv = EnvGen.ar(Env.adsr(attack, decay, sust, rel), gate)/2;
var filterEnv = EnvGen.ar(Env.adsr(attackf, decayf, sustf, relf), gate);

var filter = MoogFF.ar(Saw.ar(Lag.kr(freq/2, 3), ampEnv), cutoff * filterEnv, gain);
		var comb = CombN.ar(filter, 1, 0.5, 4);
Out.ar(0,comb)

}).add;

SynthDef(\kik, { |preamp = 1, amp = 1|
    var    freq = EnvGen.kr(Env([100, 66], [0.08], -3)),
        sig = SinOsc.ar(freq, 0.5pi, preamp).distort * amp
            * EnvGen.kr(Env([0, 1, 0.8, 0], [0.01, 0.1, 0.1]/5), doneAction: 2);
    Out.ar(0, sig ! 2);
}).add;



Ppar([
Pbind(\instrument, \kik, \delta, 1, \preamp, 4.5, \amp, 0.32),

	Pbind(
    \instrument,        \test,
	\dur,                Pseq([3+(1/4), 3.0/4], inf),
	\rat,    Pseq([0,0,3,3], inf)),
Pseq([Pfindur(20,
		Pmono(\Mog, \dur, 4, \freq, Pseq([1,2,4,8,16], inf)*495*3/8)),20], inf)
],inf).play;
)
