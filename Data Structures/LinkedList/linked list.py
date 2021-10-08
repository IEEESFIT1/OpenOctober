import collections

linked_list = collections.deque()
while True:
    print("Menu:- 1.Insert   2.Delete  3.Search  4.Exit")
    choice = int(input(" Enter Choice: "))
    if choice == 1:
        pos = int(input("Enter the position where you want to insert:"))
        data = input("Enter data to insert:")
        linked_list.insert(pos,data)
        print(linked_list)

    elif choice == 2:
        if linked_list==[]:
           print("Underflow")
        else:
            dlt=input("Enter the data to be deleted: ")
            if dlt in linked_list:
                linked_list.remove(dlt)
                print(linked_list)
            else:
                print("Element not present")
    elif choice == 3:
        if linked_list == []:
            print("Linked list is empty")
        else:
            ser = input("Enter the data to be searched: ")
            if ser in linked_list:
                print("Data found at index "+str(linked_list.index(ser,0,len(linked_list))))
            else:
                print("Element not present")
    elif choice == 4:
        break
