# Time palindrome

def getTime(s, n) :
    hour = int(s[0 : 2])
    m = int(s[3 : 5])
    rev_hour = (hour % 10) * 10 + ((hour % 100) - (hour % 10)) // 10
    xy = ""
    res  = ""
    if (hour == 23 and m >= 32) :
        res = "-1"
    elif (m < rev_hour) :
        if (hour < 10) :
            xy = "0"
        xy = xy + str(hour)
        if (rev_hour < 10) :
            res = res + xy + ":0" + rev_hours
        else :
            res = res + xy + ":" + rev_hours
    else :
        hour += 1
        rev_hour = (hour % 10) * 10 + ((hour % 100) - (hour % 10)) //10
        rev_hours = str(rev_hour)
        if (hour < 10) :
            xy = "0"            
        xy = xy + str(hour)
        if (rev_hour < 10) :
            res = res + xy + ":0" + rev_hours
        else :
            res = res + xy + ":" + rev_hours
    return res
# Driver code
if __name__ == "__main__" :
    s = "04:45"
    n = len(s)
    print(getTime(s, n))
