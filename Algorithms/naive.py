age = ('young','young','middle','old','old','old','middle','young','young','old','young','middle','middle','old')
income = ('high','high','high','medium','low','low','low','medium','low','medium','medium','medium','high','medium')
student = ('no','no','no','no','yes','yes','yes','no','yes','yes','yes','no','yes','no')
credit_rating = ('fair','good','fair','fair','fair','good','good','fair','fair','fair','good','good','fair','good')
buys_computer = ('no','no','yes','yes','yes','no','yes','no','yes','yes','yes','yes','yes','no')

w = input("Enter the age: ")
x = input("Enter the income: ")
y = input("Enter if student or not: ")
z = input("Enter the credit Rating: ")

#print(age[1])
j=0
k=0
l=0
m=0

# Probability to buy a computer
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
p = float(j/c)*float(k/c)*float(l/c)*float(m/c)*float(int(c)/14)


# Probability to not buy a computer
n=0
o=0
s=0
q=0
for i in range(14):
    if age[i]==w and buys_computer[i]=='no':
        n+=1
    if income[i]==x and buys_computer[i]=='no':
        o+=1
    if student[i]==y and buys_computer[i]=='no':
        s+=1
    if credit_rating[i]==z and buys_computer[i]=='no':
        q+=1
d = buys_computer.count("no")
pn = float(n/d)*float(o/d)*float(s/d)*float(q/d)*float(int(d)/14)

print("When Age is", w, "the probability that the person buys a computer is:", float(j/c))
print("When Age is", w, "the probability that the person doesnot buys a computer is:", float(n/d))

print("When Income is ", x, "the probability that the person buys a computer is:", float(k/c))
print("When Income is ", x, "the probability that the person doesnot buys a computer is:", float(o/d))

print("The probability that the person is a student and buys a computer is:", float(l/c))
print("The probability that the person is a student and not buys a computer is:", float(p/d))

print("The Probability that the Credit rating is ", z, "and buys a computer", float(m/c))
print("The Probability that the Credit rating is ", z, "and not buys a computer", float(q/d))

print("Probability that the person buys a computer:", p)
print()

print("Probability that the person does not buy a computer:", pn)
print()

if p>pn :
    print("The person buys the computer")
else:
    print("The person does not buy computer")
