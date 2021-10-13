# Nuts and Bolts Problem

def nutboltmatch(nuts,bolts, n):
	hash1 = {}
	for i in range(n):
		hash1[nuts[i]] = i
	for i in range(n):
		if (bolts[i] in hash1):
			nuts[i] = bolts[i]
	print("matched nuts and bolts are-")
	for i in range(n):
		print(nuts[i],end = " ")
	print()
	for i in range(n):
		print(bolts[i],end = " ")
if __name__ == "__main__":
	nuts = ['$', '%', '&','^', '@', '#']
	bolts = ['@', '#', '$','%', '^', '&']
	n = len(nuts)
	nutboltmatch(nuts, bolts, n)
