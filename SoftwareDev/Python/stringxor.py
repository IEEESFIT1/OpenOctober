def strings_xor(s, t):
    res = ""
    for i,res in enumerate(s):
        if s[i] == t[i]:
           
            res += '0'
        else:
            res += '1'
    return res
s = input()
t = input()
print(strings_xor(s, t))
