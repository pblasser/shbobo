s = Space(0,0,10000,10000)

t = Towne(1000,1000,500,500,0.2,0.5,1.0)

function ponker(x,y)
  rod = Trang(1,100,300)
  vl = Vibro(0,1,0.01)
  vl.fre = vl.fre /rod
  vr = Vibro(0,0.52,0.01)
  tr = Swoop(0,1,0.01,18,x)
  try = Swoop(0,0.5,0.01,18,y)
  gr=Bista(math.random(600,660),1,vl.ref*0.1+vr.ref*0.1)--Muler(ad,10))
 c = Chube(tr,try,rod.ref,40,vl,vr)
  vl.inn = c.pux
 vr.inn = c.puy
 tr.inn = c.pux+c.puy
 try.inn = c.pux+c.puy
 c.add=gr
 return c
end
t.add=(ponker(140,140))
t.add=(ponker(240,140))
t.add=(ponker(140,240))
t.add=(ponker(40,140))
s.add=t
function golmer(x,y)
 vl = Vibro(0,math.random()*4.8,0.1)
 vr = Vibro(0,math.random()*4.8,0.1)
  gr=Drang(830+math.random(100),830+math.random(100),Trang(0.1),vl+vr)
 c = Golem(x,y)
 c.red = 0
 c.blu = vl.ref*10
  vl.inn = c.pux*0.1
 vr.inn = c.puy*0.1
 c.add=gr
 return c
end

for i = 1,24 do 
 r = math.random(400)
 t = math.random(360)*math.pi/180
 x = math.sin(t)*r
 y = math.cos(t)*r
 print(x,y)
 s.add=(golmer(x,y)) 
end

mikeyspace(s)

mikeywarp(Trang(Trang(Tooth(0.1,400,400),4302,4004),Trang(200)))
