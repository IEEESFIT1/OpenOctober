# Find a triplet that sum to a given value in array

def find3Numbers(A, arr_size, sum):
	for i in range( 0, arr_size-2):
		for j in range(i + 1, arr_size-1):
			for k in range(j + 1, arr_size):
				if A[i] + A[j] + A[k] == sum:
					print("Triplet is", A[i],
						", ", A[j], ", ", A[k])
					return True
	return False
A = [1, 4, 45, 6, 10, 8]
sum = 22
arr_size = len(A)
find3Numbers(A, arr_size, sum)
