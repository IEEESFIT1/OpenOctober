#countdown timer in python
import time 
def countdown(t): 
    while t: 
        mins, secs = divmod(t, 60) 
        timer = '{:02d}:{:02d}'.format(mins, secs) 
        print(timer, end="\r") 
        time.sleep(1) 
        t -= 1
    print('Times UP!!') 
tm,ts = input("Enter the time in MM:SS Format ").split(":") 
t = (int(tm)*60) + int(ts)
countdown(t) 
