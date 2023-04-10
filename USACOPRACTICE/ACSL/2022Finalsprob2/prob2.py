import itertools

time="11:55:55"
hours=int(time[0:2])
minutes=int(time[3:5])
seconds=int(time[6:8])
print(hours,minutes,seconds)
chars=["r","g","b","y","c","m","w","k"]  #red is r, blue is b, cyan is c, magenta is m, green is g, yellow is y, black is k

fib=[1,1,2,3,5]

def gettime(timestr): 
    h=0
    m=0 
    s=0
    for i in range(5):
        first=timestr[i]
        if(first=="r" or first=="y" or first=="w" or first=="m"): 
            h+=fib[i]
        if(first=="g" or first=="y" or first=="w" or first=="c"):
            m+=fib[i]*5
        if(first=="b" or first=="w" or first=="m" or first=="c"):
            s+=fib[i]*5
    while(s>=60):
        s-=60
        m+=1
    while(m>=60):
        m-=60
        h+=1
    l=[]
    l.append(h)
    l.append(m)
    l.append(s)
    if(h==hours and m==minutes and s==seconds):
        return l
    return l
print(gettime("mwmrr"))
# w=[]
# ans=""
# x=[p for p in itertools.product(chars, repeat=5)]
# for word in x:
#     z=''.join(word)
#     if(gettime(z)): 
#         w.append(z)
# w.sort()
# print(w)
