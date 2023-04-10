waveLength=6
totalnumneeded=(waveLength*(waveLength+1))/2
numbers="3 1 4 1 5 9 2 6"
numarr=list(map(int,numbers.split(" ")))
dx=numarr[:]
while len(numarr)<totalnumneeded:
    numarr.extend(dx)
index=0 
ans=""
ascending=True
while(waveLength>=1): 
    
    a=numarr[index:index+waveLength]
    if ascending==True:
        a.sort()
        ascending=False
    else: 
        a.sort(reverse=True)
        ascending=True
    ans+= ' '.join(str(g) for g in a)
    ans+=" "
    index+=waveLength
    waveLength-=1
    
if(len(numarr)!=0):
    x=numarr[index:]
    if(ascending==True):
        x.sort()
    else:
        x.sort(reverse=True)
    ans+= ' '.join(str(g) for g in x)
    ans+=" "  
    
print(ans)