s = Space(0,0,4000,4000)
s.add = Towne(500,500,100,100,0.3,0.2,0.1)
mywarp = Trang(8800,Trang(Trang(1,40,40)))+Noise(Tooth(0.5))

--mikeyspace(s)
mikeywarp(mywarp)
s = Space(0,0,4000,4000)

function golmoplaz(gon,fre,amt,x,y,w,h)
 n = Nuron(0,fre)
 nn = n
 function golmo(x,y)
  nn = Nuron(nn.ref,fre)
  c = Golem(x,y,0,0,0)
  c.add=Noise(Powor(nn,math.random(100))) 
  c.red = nn.ref + 1
  nn.inn = nn.inn + c.pux + c.puy
  return c
 end
 for i = 1,amt do
  s.add = golmo(x+w*math.cos(math.pi*i*2 / amt), y+h*math.sin(math.pi*i*2 / amt))
 end
 n.inn = nn.ref
 c = Golem(x,y,0,0,0)
 c.add=gon
 gon.mul = n 
 c.blu = n.ref+1
 s.add = c
 return n
end
nr = golmoplaz(Trang(240),4,5,-0,-0,20,30)
ng = golmoplaz(Trang(140),1,3,-200,-200,20,31)
nr.inn = nr.inn + ng.ref
nnx = golmoplaz(Trang(200),1.3,4,-600,-800,20,31)
ng.inn = ng.inn + nnx.ref
nnx.inn = nnx.inn + nr.ref

function ronker(x,y,functo)
 vl = Vibro(0,0.58,0.2)
 vr = Vibro(0,0.58,0.2)
 gr=functo(math.random(10)+100,vr.ref)
 grr = functo(gr*400+800,vl.ref)
 tt = Trang(6.444+math.random(30))
 vh = Vibro(0,0.58,0)
 c = Chube(vh+x+math.random(-30,30),vh.cos+y+math.random(-30,30),tt*8+12,10,vl,vr,vl.ref+80,0,0)
vh.inn = c.pux * 30
 vl.inn = c.pux*2
 vr.inn = c.puy*2
 c.add = grr--%tt.ref--%vl
 return c
end
--oldtown = t
t = Towne(680,680,500,500,0.3,0.2,0.3)



function introspect(x, s, k)
 if x==nil then return end
 print(s..k..tostring(x))
for k, v in pairs(x) do
 --print(s..k, v) 
 introspect(v,s.." ",k)
end
end


vl = Vibro(0,0.005)
function fourses(x,y,tab)
 function foor()
  
  if gr then
   grb = Horse(math.random(12)+20,math.random(12)+20,gr.ref)
   gr.bot = grb.ref 
  else grb = Horse(math.random(12)+20,math.random(12)+20,600) 
  end
  gr = grb
  vl = Vibro(0,200/(gr.ref+100))--math.random()*0.4+0.1,0.1)
  --introspect(gr,"","")
  if tr then
   trb = Horse(math.random(1200)+200,math.random(1200)+200,tr.ref)
   tr.bot = trb.ref 
  else trb = Horse(math.random(1200)+200,math.random(1200)+200,1) 
  end
  marco = trb + marco
  tr = trb
  tr.mul = vl
  local newtab ={}
  for k,v in pairs(tab) do 
   if type(v)=='function' then newtab[k] = v() 
   else newtab[k] = v end
  end

  c = Chube(gr+x,y,gr.ref/10,gr.ref/10,vl,vl.cos,newtab)
  vl.inn = c.pux + c.puy
  c.add = tr
  return c
 end
 tr = nil
 gr = nil
 for i = 1,8 do 
  t.add =foor()
 end  
 gr.bot = 100--600
 tr.bot = -1
end
randon = function (range) 
 return function () return math.random()*range  end 
end
marco = 0
fourses(-300,100, {red=randon(0.6)})
fourses(-300,300,{grn=randon(0.2), red=randon(0.8)})
fourses(-300,-100,{blu=randon(0.2), red=randon(0.8)})
fourses(-300,-300,{blu=randon(0.2), red=randon(0.8)})

golo = Golem(0,0)
--golo.add = marco*0.1
--s.add = golo
for i = 1,6 do 
r = ronker(82,20,Trang)
--t.add = r
end  

s.add = t


function swoper(x,y)
 vl = Swoop(0,math.random()*0.62+0.1,0.01)
 vr = Swoop(0,math.random()*0.72+0.1,0.01)
 --print(vl)
 tl = Trang(math.random(200,8000),vl.ref)
 tr = Trang((1+tl.ref)*math.random(200,8000),vr.ref)
 tl.frq = tl.frq * (1+tr.ref)
 c = Chube(x,y,20,20,vl,vr,0.4,0.2,math.random()*0.3)
 vl.inn = c.pux
 vr.inn = c.puy
 c.add=tr+tl
 return c
end
t = Towne(600,-400,600,300,0.4,0.4,0.6)

function triangleswoper(x,y,n,h,amt,func)
 local osc=0;
 local gwon = true;
 for i = 1,amt do
  t.add=func(x+i*n,y+osc)
  if gwon then osc = osc + n
  else osc = osc - n end
  if osc > (i*h) then gwon = false
  elseif osc < (-i*h) then gwon = true end
 end
end
triangleswoper(-550,0,40,6,28,swoper)


--for i = 1,14 do t.add=swoper(math.random(-200,200),math.random(-200,200)) end
s.add=(t)

function golmer(x,y,vfun,sfun,r)
 vl = vfun(0,r,0.1)
 vr = vfun(0,r,0.1)
  gr=sfun(830+math.random(100),vl+vr)
 c = Golem(x,y)
  vl.inn = c.pux*0.5
 vr.inn = c.puy*0.5
 c.add=gr
 return c
end
for i = 1,9 do 
 s.add=golmer(math.random(100)-200,math.random(400)+400,Vibro,Trang,4.8)
  s.add=golmer(math.random(100)-200,math.random(400)+1100,Vibro,Tooth,0.15)
end

function swoperoo(x,y,func)
 vl = func(0,0.42*math.random()+0.3,0.01)
 vr = func(0,0.42*math.random()+0.3,0.01)
 trg = Nuron(vl.ref+0.1,10)*Noise(0.4)
 tre = Vibro(Trigg(vr.ref-0.1),Salsa(vr.ref-0.1,Noise(),800,1000),0.01)--math.random(200,8000),0.01)
 --print(vl)
 tr = Trang(math.random(20,200),vl.ref*2.333)
 c = Chube(x,y,math.random(20,30),math.random(20,30),vl,vr,0.4,0.2,math.random()*0.3)
 vl.inn = c.pux
 vr.inn = c.puy
 c.add=tr+trg+tre
 return c
end
t = Towne(-900,100,300,800,0.1,0.1,0.3)
for i = 1,14 do t.add=swoperoo(math.random(-100,100),math.random(-400,400), Swoop) end
s.add=(t)

t = Towne(-1700,100,300,300,0.13,0.222,0.245)
for i = 1,14 do t.add=swoperoo(math.random(-100,100),math.random(-100,100), Vibro) end
s.add=(t)






mikeyspace(s)
mikeywarp(mywarp)

