#Karatsuba Algorithm in Python
import math
def karatsuba(x, y):
    if x < 10 and y < 10:  
        return x*y
    n = max(len(str(x)), len(str(y)))
    m = int(math.ceil(float(n)/2))
    x_H = int(math.floor(x/10**m))  
    x_L = int(x % (10**m))  
    y_H = int(math.floor(y/10**m))  
    y_L = int(y % (10**m))  
    s1 = karatsuba(x_H, y_H)
    s2 = karatsuba(x_L, y_L)
    s3 = karatsuba(x_H+x_L, y_H+y_L)
    s4 = s3-s2-s1
    return int(s1*(10**(m*2))+s4*(10**m)+s2)
num1 = int(input())
num2 = int(input())
result = karatsuba(num1, num2)
print(result)
