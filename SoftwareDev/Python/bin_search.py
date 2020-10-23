#Python program to implement recursive binary search
#Contributed by Puranjay N Potnis


def bin_Search(arr, low, high, x):
    
    if high >= low:
        
        mid = (high+low) // 2
        
        if arr[mid] == x:
            #element is the middle element
            return mid

        elif arr[mid] > x:
            #element is smaller than mid value
            #check left sub-array
            return bin_Search(arr, low, mid-1, x)

        else:
            #element is larger than mid value
            #check right sub-array
            return bin_search(arr, mid+1, high, x)
    else:
        return -1

arr = map(int, input("Enter space separated array: ").split())
x = int(input("Enter a number to be searched: "))

result = bin_Search(arr, 0, len(arr)-1, x) 
  
if result != -1: 
    print("Element is present at index", str(result)) 
else: 
    print("Element is not present in array") 
