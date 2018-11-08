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
        max = fun(sec)
        # if(fun(fir)>fun(sec)):
        #     min, max = max, min
        left += min*(sec-fir)
        right += max*(sec-fir)
        fir =sec 
    
    print(left)
    print(right)

def sqr(x):
    return math.sin(x)

p = (8+4*i for i in range(4))
calu(sqr,*p)