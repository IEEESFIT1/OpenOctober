'''
Given a string, find all permutations of the string and display in lexigraphic order
'''

def permutations(s,k,n):
    if k == n:
        rs = ''
        for i in range(len(s)):
            rs += s[i]
        l.append(rs)
    else:
        for i in range(k,n):
            s[i],s[k] = s[k],s[i]
            permutations(s,k+1,n)
            s[i],s[k] = s[k],s[i]

string = list(input())
l = []

permutations(string,0,len(string))
l = list(set(l))
l.sort()
print(*l)
