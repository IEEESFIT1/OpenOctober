import numpy as np
import math

y = []

n = int(input("Enter number of elements : "))
print("Enter the elements")

for i in range(0, n):
    e = int(input())
    y.append(e)
y.sort()
print(y)

m=int(input("Enter number of bins:"))

v=int(n/m)
def divide_chunks(l,n,v):
      
    for i in range(0, n, v): 
        yield l[i:i + v]

bin1= list(divide_chunks(y,n,v))
print (bin1)


bin2=np.zeros((m,v))
bin3=np.zeros((m,v))

for i in range (0,n,v):
    k = int(i/v)
    mean = (y[i] + y[i+1] + y[i+2] + y[i+3])/v
    for j in range(v):
        bin2[k,j] = round(mean,0)
print("Bin Mean: \n",bin2)

for i in range (0,n,v):
    k = int(i/v)
    for j in range (v):
        if (y[i+j] - y[i]) < (y[i+3] - y[i+j]):
            bin3[k,j] = y[i]
        else:
            bin3[k,j] = y[i+3]
print("Bin Boundaries: \n",bin3)
