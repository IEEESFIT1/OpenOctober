x=int(input('''enter number for the process you want to run
1.Addition
2.subtration
3.Division
4.multiplication
5.Remainder
6.factorial
7.square 
8.Cube
9.Average  '''))

#no 1 addition
add=0


if(x==1):
    while True:
        y=input("enter as many numbers as you want to add. Enter 'DONE' when you finish entering  ")
        if(y=="done"):
            break
        else:
            try:
                l=int(y)
                add=add+l
            except:
                print("Invalid Input")
                continue
    print('addition of the numbers is ' + str(add))


#no 2 subtraction
sub=0

if(x==2):
    while True:
        mm = input("enter as many numbers as you want to subtract. Enter 'DONE' when you finish entering  ")
        if (mm == "done"):
            break
        else:
            try:
                s = int(mm)
                sub=s-sub
            except:
                print("Invalid Input")
                continue
    print('subtraction of the numbers is ' + str(sub))



#no 3 division
div=1

if(x==3):
    while True:
        nn = input("enter as many numbers as you want to divide. Enter 'DONE' when you finish entering  ")
        if (nn == "done"):
            break
        else:
            try:
                lm = int(nn)
                div = lm/div
            except:
                print("Invalid Input")
                continue
    print('division of the numbers is ' + str(div))


#no 4 multiplication
mult=1

if(x==4):
    while True:
        ym = input("enter as many numbers as you want to add. Enter 'DONE' when you finish entering  ")
        if (ym == "done"):
            break
        elif(ym=="0"):
            print('Invalid input')
            continue
        else:
            try:
                ln = int(ym)
                mult = mult*ln
            except:
                print("Invalid Input")
                continue
    print('multiplication of the numbers is ' + str(mult))


#no 5 remainder

if(x==5):
    while True:
        q=int(input("enter 1st number "))
        w=int(input("enter 2nd number "))

        if(q==0 or w==0):
            print("enter the number again")
            continue
        else:
            rem=q%w
            break
    print("remainder is " + str(rem))


#no 6 factorial

fact=1

if(x==6):
    e=int(input('enter a number you want the factorial of '))
    if(e==0):
        print("invalid input")
        e=int(input("enter the correct number "))

    for i in range(1,e+1):
        fact=fact*i

    print("factorial of the number is " + str(fact))


#no 7 square
if(x==7):
    r=int(input('enter the number you want the square of '))
    def squ(t):
        sq=t*t
        return sq

    while True:
        print("the square of the number is " + str(squ(r)))
        break



#no 8 cube

if(x==8):
    ro=int(input('enter the number you want the cube of '))
    def cube(j):
        cu=j*j*j
        return cu

    while True:
        print("the cube of the number is " + str(cube(ro)))
        break



#no 9 average


addi=0
ctr=0

if(x==9):

    while True:
        yll = input("enter as many numbers as you want to have average. Enter 'DONE' when you finish entering  ")
        if (yll == "done"):
            break
        else:
            try:
                lmm = int(yll)
                addi = addi + lmm
                ctr+=1
            except:
                print("Invalid Input")
                continue
    print('average of the numbers is ' + str(float(addi/ctr)))







