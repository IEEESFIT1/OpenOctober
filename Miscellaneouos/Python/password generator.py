import random
print("Hello this is the program for random password generator")

x=int(input("Enter how many numbers do you want in password "))
y=int(input("Enter how many alphabets do you want in password "))
z=int(input("Enter how many characters do you want in password "))


ll=""
mm=''
nn=''

for i in range(0,x):
    l=random.randint(0,9)
    ll=ll+str(l)
    m="".join(ll)
#print(m)

for i in range(0,y):
    q=random.randint(0,25)
    w=chr(ord('a')+q)
    mm=mm+str(w)
    r=''.join(mm)
#print(mm)


for i in range(0,z):
    t=random.randint(0,9)
    a=chr(ord('!')+t)
    nn=nn+a
#print(nn)

zz=''
manav=ll+mm+nn
#print(manav)

manav=[i for i in manav]


random.shuffle(manav)
dd="".join(manav)
print( "the password is " + dd)


