
for i=-32,-1 do
 print (".hword",math.floor(math.pow(2,i/17)*256*64))
end
print("\n")
for i=0,31 do
 print (".hword",math.floor(math.pow(2,i/17)*256*64))
end
