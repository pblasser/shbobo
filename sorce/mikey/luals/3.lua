
function bonker(x,y)
 vl = Vibro(0,0.433)
 vr = Vibro(0,0.433)
 gr=Tooth(math.random(100)+200,vl.ref)
 gr=gr+Tooth(Tooth(math.random(4)+4,100,math.random(100)+200),vr.ref)
 gro = Vibro(gr,vl.ref+vr.ref+200,0.1)
 c = Chube(x,y,15,15,vl,vr,54,vl.ref,vl.ref)
 vl.inn = c.pux
 vr.inn = c.puy
 c.add=gro
 return c
end

function ponker(x,y)
  vl = Vibro(0,0.62,0.01)
  vr = Vibro(0,0.52,0.01)
  tr = Swoop(0,1,0.01,180,x)
  try = Swoop(0,0.5,0.01,180,y)
  gr=Bista(math.random(600,660),1,vl.ref*0.1+vr.ref*0.1)--Muler(ad,10))
 c = Chube(tr,try,40,40,vl,vr)
  vl.inn = c.pux
 vr.inn = c.puy
 tr.inn = c.pux+c.puy
 try.inn = c.pux+c.puy
 c.add=gr
 return c
end

function bistar(x,y)
  vl = Bista(1)
  tr = Swoop(0,vl.ref,0.01)
  try = Swoop(0,vl.ref,0.01)
  gr = Grass(500,Trang(0.1,200,200))
 c = Chube(vl*20+x,y,40,40,tr,try)
 tr.inn = c.pux
 try.inn = c.puy
 c.add = gr*vl.ref
 return c
end

s = Space(0,0,10000,10000)
t = Towne(1000,1000,500,500,0.8,0.8,1.0)
for i = 1,1 do --7 do
t.add = bistar(i*42,-240)
end
s.add=(t)

for i = 1,7 do
t.add=(bonker(i*42-200,10))
t.add=(ponker(math.random(100,400),math.random(100,400)))
end  
t.add=(ponker(140,140))

s.add=(t)


function golmer(x,y)
 vl = Vibro(0,4.8,0.1)
 vr = Vibro(0,4.8,0.1)
  gr=Trang(830+math.random(100),vl+vr)
 c = Golem(x,y)
  vl.inn = c.pux*0.1
 vr.inn = c.puy*0.1
 c.add=gr
 return c
end

for i = 1,14 do s.add=(golmer(math.random(100),math.random(100))) 
end

mikeyspace(s)
mikeywarp(Trang(Trang(Tooth(0.1,400,400),4302,4004),Trang(200)))

