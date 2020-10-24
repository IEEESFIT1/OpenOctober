#Alarm clock using Python Tkinter module by Rajkumar Selvaraj
from tkinter import *
from tkinter import ttk
import time
import os
from tkinter import messagebox

#def main():
root = Tk()
root.title("Alarm clock")
def SubmitButton():
  AlarmTime= entry1.get()
  Message1()
  #label2.config(text ="The Alarm will Ring at {} ".format(AlarmTime))  #delayed in execution
  CurrentTime = time.strftime("%H:%M")
  print("the alarm time is: {}".format(AlarmTime))
  #label2.config(text="")
  while AlarmTime != CurrentTime:
    #label2.config(text ="The Alarm will Ring at {} ".format(AlarmTime))
    CurrentTime = time.strftime("%H:%M")
    time.sleep(1)
  if AlarmTime == CurrentTime:
     print("now Alarm Musing Playing")
     os.system("alarm.mp3")
     label2.config(text = "Alarm music playing.....")
     messagebox.showinfo(title= 'Alarm Message', message= "{}".format(entry2.get()))
def Message1():
    AlarmTimeLable= entry1.get()
    label2.config(text="the Alarm time is Counting...")
    #label2.config(text= "the Alarm will ring at {}".format(AlarmTimeLable))
    messagebox.showinfo(title = 'Alarm clock', message = 'Alarm will Ring at {}'.format(AlarmTimeLable))     
frame1 = ttk.Frame(root)
frame1.pack()
frame1.config(height = 200, width = 200)

label1= ttk.Label(frame1,text = "Enter the Alarm time :")
label1.pack()


entry1 = ttk.Entry(frame1, width = 100)
entry1.pack()
entry1.insert(3," 13:15")

labelAlarmMessage= ttk.Label(frame1, text="Alarm Message:")
labelAlarmMessage.pack()

entry2= ttk.Entry(frame1, width=30)
entry2.pack()

button1= ttk.Button(frame1, text= "submit", command=SubmitButton)
button1.pack()
#this Label2 will show the Last Alarm Time
label2= ttk.Label(frame1)
label2.pack()

    
#label2.config(text="hello")

root.mainloop()
