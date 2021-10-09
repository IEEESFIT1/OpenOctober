age = ('young','young','middle','old','old','old','middle','young','young','old','young','middle','middle','old')
income = ('high','high','high','medium','low','low','low','medium','low','medium','medium','medium','high','medium')
student = ('no','no','no','no','yes','yes','yes','no','yes','yes','yes','no','yes','no')
credit_rating = ('fair','good','fair','fair','fair','good','good','fair','fair','fair','good','good','fair','good')
buys_computer = ('no','no','yes','yes','yes','no','yes','no','yes','yes','yes','yes','yes','no')

w = input("Enter age: ")
x = input("Enter income: ")
y = input("Enter if student or not: ")
z = input("Enter credit Rating: ")

j=0
k=0
l=0
m=0

for i in range(14):
    if age[i]==w and buys_computer[i]=='yes':
        j+=1
    if income[i]==x and buys_computer[i]=='yes':
        k+=1
    if student[i]==y and buys_computer[i]=='yes':
        l+=1
    if credit_rating[i]==z and buys_computer[i]=='yes':
        m+=1

c = buys_computer.count("yes")
print("Age is ",w ,"and buys computer",j/c)
print("Income is ",x,"and buys computer",k/c)
print("Student=",y,"and buys computer",l/c)
print("Rating is ",z,"and buys computer",m/c)
p = float(j/c)*float(k/c)*float(l/c)*float(m/c)*float(int(c)/14)
print("Student buys computer",p)

j=0
k=0
l=0
m=0
for i in range(14):
    if age[i]==w and buys_computer[i]=='no':
        j+=1
    if income[i]==x and buys_computer[i]=='no':
        k+=1
    if student[i]==y and buys_computer[i]=='no':
        l+=1
    if credit_rating[i]==z and buys_computer[i]=='no':
        m+=1
c = buys_computer.count("no")
pn = float(j/c)*float(k/c)*float(l/c)*float(m/c)*float(int(c)/14)
print("\nAge is ",w ,"and does not buy computer",j/c)
print("Income is ",x,"and does not buy computer",k/c)
print("Student=",y,"and does not buy computer",l/c)
print("Rating is ",z,"and does not buy computer",m/c)
print("Student does not buy coumpter",pn)

if p>pn :
    print("\nThe student buys the computer")
else:
    print("\nThe student does not buy computer")
