from tkinter import *
import tkinter.ttk as ttk

def currency_converter():
    currency_converter = Tk()  
    currency_converter.title("URVANSH MONEY MACHINE")
    currency_converter.geometry("425x225")
    currency_converter.update_idletasks()
    w = currency_converter.winfo_screenwidth()
    h = currency_converter.winfo_screenheight()
    size = tuple(int(_) for _ in currency_converter.geometry().split('+')[0].split('x'))
    x = w/2 - size[0]/2
    y = h/2 - size[1]/2
    currency_converter.geometry("%dx%d+%d+%d" % (size + (x, y))) 
    currency_converter.rowconfigure(5, weight=1)
    currency_converter.lift()
    currency_converter.configure(background='#007780')
    def enter(event):
        UserInput = float(Currency_Input.get().replace(',', '.'))
        Currency_Output.delete(0,END)
        Currency_Output1.delete(0,END)
        Currency_Output2.delete(0,END)
        if box.get() == "EUR":            
            Currency_Output_Label.config(text="USD")
            Currency_Output.insert(0,round(UserInput*1.16,2))
            Currency_Output1_Label.config(text="GBP")
            Currency_Output1.insert(0,round(UserInput*0.91,2))
            Currency_Output2_Label.config(text="INR")
            Currency_Output2.insert(0,round(UserInput*86.35,2))
        elif box.get() == "USD":
            Currency_Output_Label.config(text="EUR")
            Currency_Output.insert(0,round(UserInput*0.86,2))
            Currency_Output1_Label.config(text="GBP")
            Currency_Output1.insert(0,round(UserInput*0.79,2))
            Currency_Output2_Label.config(text="INR")
            Currency_Output2.insert(0,round(UserInput*74.56,2))
        elif box.get() == "GBP":
            Currency_Output_Label.config(text="EUR")
            Currency_Output.insert(0,round(UserInput*1.09,2))
            Currency_Output1_Label.config(text="USD")
            Currency_Output1.insert(0,round(UserInput*1.27,2))
            Currency_Output2_Label.config(text="INR")
            Currency_Output2.insert(0,round(UserInput*94.54,2))
        elif box.get() == "INR":
            Currency_Output_Label.config(text="EUR")
            Currency_Output.insert(0,round(UserInput*0.012,2))
            Currency_Output1_Label.config(text="USD")
            Currency_Output1.insert(0,round(UserInput*0.013,2))
            Currency_Output2_Label.config(text="GBP")
            Currency_Output2.insert(0,round(UserInput*0.011,2))

    def close_currency_converter():
        currency_converter.destroy()

    Headline_Label = Label(currency_converter, text='Currency Converter', bg='#007780', fg='white',font=("Century Gothic",16))
    Headline_Label.grid(row=0,column=0, columnspan=2, padx=5, pady=5, sticky=W)

    Box_Headline_Label = Label(currency_converter, text='Which Currency?', bg='#007780', fg='white',font=("Century Gothic",11))
    Box_Headline_Label.grid(row=1,column=0, columnspan=1, padx=5, pady=5, sticky=W)

    box_value = StringVar() 
    box = ttk.Combobox(currency_converter, textvariable=box_value, width=10)
    box['values'] = ('EUR', 'USD', 'GBP', 'INR')
    box.current(0)
    box.grid(row=1,column=1, pady=5, sticky=E)

    Currency_Input = Entry(currency_converter)
    Currency_Input.grid(row=1,column=2, padx=10, pady=5, sticky=W)

    Currency_Input.bind('<Return>',enter)

    Currency_Output_Label = Label(currency_converter, text='', bg='#007780', fg='white',font=("Century Gothic",11))
    Currency_Output_Label.grid(row=2,column=1, padx=5, pady=5, sticky=W)

    Currency_Output1_Label = Label(currency_converter, text='', bg='#007780', fg='white',font=("Century Gothic",11))
    Currency_Output1_Label.grid(row=3,column=1, padx=5, pady=5, sticky=W)   

    Currency_Output2_Label = Label(currency_converter, text='', bg='#007780', fg='white',font=("Century Gothic",11))
    Currency_Output2_Label.grid(row=4,column=1, padx=5, pady=5, sticky=W)  

    Currency_Output = Entry(currency_converter)
    Currency_Output.grid(row=2,column=2, padx=10, pady=5, sticky=W)

    Currency_Output1 = Entry(currency_converter)
    Currency_Output1.grid(row=3,column=2, padx=10, pady=5, sticky=W)

    Currency_Output2 = Entry(currency_converter)
    Currency_Output2.grid(row=4,column=2, padx=10, pady=5, sticky=W)

    Button(currency_converter,text="Quit",command=close_currency_converter).grid(row=6,column=0, sticky=E+S+W, pady=5, padx=5)

    currency_converter.mainloop()

currency_converter()
