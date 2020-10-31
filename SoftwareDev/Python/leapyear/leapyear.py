num = int(input("Enter the year you want to check if is leap year or not: "))

if(num%4 == 0):

   if(num%100 == 0):

       if(num%400 == 0):

           print("The year {} is a leap year".format(num))

       else:

           print("The year {} is Not a leap year".format(num))

   else:

       print("The year {} is a leap year".format(num))

else:

   print("The year {} is Not a leap year".format(num))
