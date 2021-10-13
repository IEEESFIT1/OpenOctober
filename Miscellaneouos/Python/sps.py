import random




user=0
comp=0

while True:
    x = input('''Enter
    number '1' for stone
    number"2" for paper 
    number "3" for scissors
    press"q" to exit the game ''')

    mylist = ["stone", "paper", "scissors"]
    z = random.choice(mylist)
    #print(z)


    if(x=="q"):
        break
    elif(x=="1"):
        if(z=="stone"):
            print("***it is a tie.You have selected stone and the computer has selected*** " + z)
            user+=0
            comp+=0
        elif(z=="paper"):
            print("***You lose.You have selected stone and the computer has selected*** " +z)
            user+=0
            comp+=1
        else:
            print("***You win!!.You have selected stone and the computer has selected*** " +z)
            user+=1
            comp+=0

    elif(x=="2"):
        if(z=="stone"):
            print("***You win!!.You have selected paper and the computer has selected*** " +z)
            user+=1
            comp+=0
        elif(z=="paper"):
            print("***it is a tie.You have selected paper and the computer has selected*** " + z)
            user+=0
            comp+=0
        else:
            print("***You lose.You have selected paper and the computer has selected*** " + z)
            user+=0
            comp+=1

    elif(x==3):
        if(z=="scissors"):
           print("***it is a tie.You have selected scissors and the computer has selected*** " + z)
           user+=0
           comp+=0
        elif(z=="stone"):
            print("***You lose.You have selected paper and the computer has selected*** "+ z)
            user+=0
            comp+=1
        else:
            print("***You win!!.You have selected stone and the computer has selected*** " + z)
            user+=1
            comp+=0

    else:
        print("invalid input")

print("Your score is " + str(user) + " and computers score is " + str(comp))

if(int(user)>int(comp)):
    print("You are the Winner!!!")
elif(int(user)<int(comp)):
    print("Computer is the Winner!!!")
else:
    print("It's a Tie...")







