num = int(input('Enter the number of houses: '))
x1=0
x2=0
position1=0
position2=0
maxi=0
house_number = []
position = []
copy_position = []
print('Enter the number of houses and position of the houses: ')
for i in range(num):
    house_number.append(int(input('House Number:')))
    position.append(int(input('Position:')))
    print('Input')
for i in range(num):
    print ('[%d,%d]' %(house_number[i], position[i]))
for i in range(num):
    copy_position.append(position[i])
    copy_position.sort()
    print(copy_position)
    maxi=0
for i in range(num-1):
    temp = (copy_position[i+1] - copy_position[i])
    if(temp > maxi):
        x1 = copy_position[i]
        x2 = copy_position[i+1]
for i in range(num):
    if x1 == position[i]:
        position1 = i
    if x2 == position[i]:
        position2 = i
print('Result: ')
if house_number[position1] > house_number[position2]:
    print ('[%d,%d]' %(house_number[position2], house_number[position1]))
else:
    print ('[%d,%d]' %(house_number[position1], house_number[position2]))
