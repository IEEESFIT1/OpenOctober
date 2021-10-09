stack = []
while True:
    print("Menu:- 1.Enqueue 2.Dequeue 3.Peek 4.Exit")
    choice = int(input(" Enter Choice: "))
    if choice == 1:
        data = input("Enter data to enqueue: ")
        stack.append(data)
        print(stack) 
    elif choice == 2:
        if stack == []:
            print("Underflow!!")
        else:
            print("Element removed is " +str(stack[0]))
            stack.pop(0) 
            print(stack)
    elif choice == 3:
        if stack == []:
            print("Underflow!!")
        else:
            print(str(stack[0]) + " is at front")
    elif choice == 4:
        break
