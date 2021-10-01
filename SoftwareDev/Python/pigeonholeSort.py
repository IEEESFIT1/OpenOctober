# Implementation of the pigeonhole sort using python
def pigeonhole_sort(a):
    >>> a = [8, 3, 2, 7, 4, 6, 8]
    >>> b = sorted(a)  
    >>> pigeonhole_sort(a)  
    >>> a == b
    True
    min_val = min(a)  
    max_val = max(a)  
    size = max_val - min_val + 1  
    holes = [0] * size
    for x in a:
        assert isinstance(x, int), "integers only please"
        holes[x - min_val] += 1
    i = 0
    for count in range(size):
        while holes[count] > 0:
            holes[count] -= 1
            a[i] = count + min_val
            i += 1
def main():
    pigeonhole_sort([8, 3, 2, 7, 4, 6, 8])
    print("Sorted order is: ", " ", join(a))
if __name__ == "__main__":
    main()
