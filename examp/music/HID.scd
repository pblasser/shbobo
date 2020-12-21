
HID.findAvailable;
HID.postAvailable;
~myhid = HID.open( 26214, 30583 );
~myhid = HID.open( 26214, 26214 );
(
var ww = true;
w = Window(bounds:Rect(700,200,200,200));
v = VLayout(h);
w.layout =  v;
w.front;
w.alwaysOnTop = true;
w.onClose({ww = false;});
a = Array.fill(4, { arg i;
	k = Slider();
	v.add(k);
	k.value_(0.5);
	k.orientation = \horizontal;
	k
});
h = HLayout();
b = Array.fill(32, {arg i;
	k = CheckBox();
	h.add(k);
	k
});
v.add(h);
l=StaticText();
v.add(l);
r = Routine({
	inf.do({
		var frets;
		var lz;
        0.05.yield;
		frets = 0;
		a.do{arg ii, k; ii.value = ~myhid.elements[k].value};
		4.do{arg ii;  frets = frets | ((255&~myhid.elements[ii+4].rawValue)<<(ii*8))};

		b.do{arg ii, k; ii.value = (frets>>k) & 1; };
		lz = 0;
		{(frets!=0)&&(lz<32)}.while({lz = lz+1; frets = frets>>1; });
		l.string=lz;
	});
});
AppClock.play(r);
w.onClose({AppClock.clear});
)

Plug