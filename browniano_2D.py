import numpy as np
import sys
import math
import matplotlib.pyplot as plt

n=sys.argv[1]
m=int(n)
pi=np.pi
al=np.random.random(m)

a=al*2*pi
x=[]
y=[]
r=[]
N=[]

for i in range(0,m):
    x.append(0)
    y.append(0)
    r.append(0)
    N.append(0)

for i in range(m):
    x[i]=x[i-1]+np.cos(a[i])
    y[i]=y[i-1]+np.sin(a[i])
    r[i]=r[i-1]+np.sqrt((x[i]*x[i])+(y[i]*y[i]))
    N[i]=i+1

plt.plot(N,r)
plt.show()

