import math
def calu(fun, *arg):
    p = list(arg)
    p.reverse()
    fir = p.pop()
    left, right =0,0
    while(len(p)):
        sec = p.pop()
        print(f"set{fir}and{sec} ")
        min = fun((fir+sec)/2)
        # print(f"cal{(fir+sec)/2} get last {left}")
        max = fun(fir)
        # if(fun(fir)>fun(sec)):
        #     min, max = max, min
        left += min*(sec-fir)
        right += max*(sec-fir)
        fir =sec 
    
    print(left)
    print(right)

def sqr(x):
    return math.sqrt(1+math.cos(x))

p = (4+i*0.05 for i in range(21) )
calu(sqr,*p)