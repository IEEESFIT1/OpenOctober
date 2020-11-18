from datetime import date

today = date.today()
date = today.strftime("%d/%m/%Y")
print("date =", date)
file = open("birthday.txt")
lst = list()
for str in file:
    str = str.strip()
    str = str.split()

    if date == str[2]:
      print("Today is " + str[0]+ str[1] + "'s birthday" + " date: " + str[2] )
    
