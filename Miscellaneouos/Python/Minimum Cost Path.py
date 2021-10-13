# Minimum Cost Path 

import sys
def findMinprice(price,x=None,y=None):
	if not x and not y:
		x, y = len(price), len(price[0])
	if not price or not len(price):
		return 0
	if y == 0 or x == 0:
		return sys.maxsize
	if x == 1 and y == 1:
		return price[0][0]
	return min(findMinprice(price,x-1,y), findMinprice(price,x,y-1))\
		+ price[x-1][y-1]
if __name__ == '__main__':
	price = [
		[4, 7, 8, 6, 4],
		[6, 7, 3, 9, 2],
		[3, 8, 1, 2, 4],
		[7, 1, 7, 3, 7],
		[2, 9, 8, 9, 3]
	]
	print('The minimum price is : ', findMinprice(price))
