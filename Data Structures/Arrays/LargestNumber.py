'''

Given a list of non negative integers, arrange them such that they form the largest number.

Ex : [3, 30, 34, 5, 9], the largest formed number is 9534330.
'''

class Solution:
    def largestNumber(self, a):
        # write your method here        
        
        largestnumber =''
        for i in range(len(a)-1):
            for j in range(i+1, len(a)):
                string1 = str(a[i])+str(a[j])
                string2 = str(a[j])+str(a[i])
                if int(string2) > int(string1):
                    a[i] , a[j] = a[j] , a[i]
        for i in range(len(a)):
            largestnumber += str(a[i])
        return int(largestnumber)
