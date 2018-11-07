import math
def calu(fun, *arg):
    p = list(arg)
    p.reverse()
    fir = p.pop()
    left, right =0,0
    while(len(p)):
        sec = p.pop()
        print(f"set{fir}and{sec} ")
        min = fun(fir)
        max = fun(sec)
        if(fun(fir)>fun(sec)):
            min, max = max, min
        left += min*(sec-fir)
        right += max*(sec-fir)
        fir =sec 
    
    print(left)
    print(right)

def sqr(x):
    return 2*math.exp(x)+2

p = (0+i*.1 for i in range(11))
calu(sqr,*p)