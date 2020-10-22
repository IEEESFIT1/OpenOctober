from tkinter import *
import tkinter.messagebox
import database as db
import config as cfg

# Class for UI


class Product:
    def __init__(self, root):

        self.root = root

        # db object
        p = db.Database()
        p.conn()

        # Create Box
        self.root.title(cfg.app_name)
        self.root.geometry(cfg.window_size)
        self.root.config(bg=cfg.primary_bg)

        # Input Variables from user
        pId = StringVar()
        pName = StringVar()
        pPrice = StringVar()
        pQty = StringVar()
        pCompany = StringVar()
        pContact = StringVar()

        ''' db method to perform operations '''

        # Close method
        def close():
            print("Product: Close method called")
            close = tkinter.messagebox.askyesno(
                cfg.app_name, "Do you want to close System? ")
            if close > 0:
                root.destroy()
                print("Product: System Closed")
                return

        # Clear or reset data method
        def clear():
            print("Product: Clear method called")
            self.txtpId.delete(0, END)
            self.txtpName.delete(0, END)
            self.txtpPrice.delete(0, END)
            self.txtpQty.delete(0, END)
            self.txtpCompany.delete(0, END)
            self.txtpContact.delete(0, END)
            print("Product: Clear method fineshed!!\n")

        # Insert method
        def insert():
            print("Product: Insert method called")

            if(len(pId.get()) != 0 and len(pName.get()) != 0 and len(pPrice.get()) != 0 and len(pQty.get()) != 0 and len(pCompany.get()) != 0 and len(pContact.get()) != 0):
                p.insert(pId.get(), str(pName.get()), pPrice.get(),
                         pQty.get(), pCompany.get(), pContact.get())
                showlist()
                clear()
            else:
                tkinter.messagebox.showwarning(cfg.app_name,
                                               "All Fields are mandatory!!")

            print("Product: Insert method fineshed!!\n")

        # Show Data in db to product list
        def showlist():
            print("Product: Show method called")
            productList.delete(0, END)
            rows = p.show()
            if rows:
                for row in p.show():
                    productList.insert(END,row, str(""))
            else:
                productList.insert(END, "No Data available!!", str(""))
            clear()            
            print("Product: Show method fineshed!!\n")

        # Add to scroll bar
        def productRec(event):
            # called from scrollbar productlist
            print("Product: Product Rec method called")

            global pd

            searchPd = productList.curselection()[0]
            pd = productList.get(searchPd)

            self.txtpId.delete(0, END)
            self.txtpId.insert(END, pd[0])

            self.txtpName.delete(0, END)
            self.txtpName.insert(END, pd[1])

            self.txtpPrice.delete(0, END)
            self.txtpPrice.insert(END, pd[2])

            self.txtpQty.delete(0, END)
            self.txtpQty.insert(END, pd[3])

            self.txtpCompany.delete(0, END)
            self.txtpCompany.insert(END, pd[4])

            self.txtpContact.delete(0, END)
            self.txtpContact.insert(END, pd[5])

            print("Product: Product Rec method Fineshed!!\n")

        # Delete db data on button press
        def delete():
            print("Product: delete method called")
            if(len(pId.get()) != 0):
                p.delete(pId.get())
                clear()
                showlist()
            else:
                tkinter.messagebox.showwarning(cfg.app_name,
                                               "Product Id is mandatory!!")
            print("Product: delete method fineshed!!\n")

        def update():
            print("Product: update method called")
            if(len(pId.get()) != 0 or len(pName.get()) != 0 or len(pPrice.get()) != 0 or len(pQty.get()) != 0 or len(pCompany.get()) != 0 or len(pContact.get()) != 0):
                p.delete(pId.get())
                p.insert(pId.get(), str(pName.get()), pPrice.get(),
                         pQty.get(), pCompany.get(), pContact.get())
                productList.delete(0, END)
                productList.insert(END, (pId.get(), pName.get(), pPrice.get(),
                                         pQty.get(), pCompany.get(), pContact.get()), str(""))
            else:
                tkinter.messagebox.showwarning(cfg.app_name,
                                               "Enter at-lest a field!!")
            print("Product: Update method fineshed!!\n")

        def search():
            print("Product: search method called")
            if(len(pId.get()) != 0 or len(pName.get()) != 0 or len(pPrice.get()) != 0 or len(pQty.get()) != 0 or len(pCompany.get()) != 0 or len(pContact.get()) != 0):
                productList.delete(0, END)
                for row in p.search(pId.get(), pName.get(), pPrice.get(), pQty.get(), pCompany.get(), pContact.get()):
                    productList.insert(END, row, str(""))
            else:
                tkinter.messagebox.showwarning(cfg.app_name,
                                               "Enter at-lest a field!!")
            print("Product: search method fineshed!!\n")

        ''' Create a Frame '''
        MainFrame = Frame(self.root, bg=cfg.primary_bg)
        MainFrame.grid()

        # Head Frame
        HeadFrame = Frame(MainFrame, bd=cfg.borderSmall, padx=10,
                          pady=cfg.padding10, bg=cfg.primary_bg, relief=RIDGE)
        HeadFrame.pack(side=TOP)

        # Title
        self.ITitle = Label(HeadFrame, font=(cfg.fontFamily, 50, cfg.fontWeight), fg=cfg.titleColor,
                            text=cfg.title, bg=cfg.primary_bg)
        self.ITitle.grid()

        # Body

        # Parent Body Frame
        OperationFrame = Frame(MainFrame, bd=cfg.borderSmall, width=1300,
                               height=60, padx=50, pady=20, bg=cfg.primary_bg, relief=RIDGE)
        OperationFrame.pack(side=BOTTOM)

        # Child Body Frame
        BodyFrame = Frame(MainFrame, bd=cfg.borderSmall, width=cfg.bodyWidth, height=cfg.bodyHeight,
                          padx=30, pady=20, bg=cfg.primary_bg, relief=RIDGE)
        BodyFrame.pack(side=BOTTOM)

        # Left Body Frame Input Form
        LeftBodyFrame = LabelFrame(BodyFrame, bd=cfg.borderSmall, width=cfg.bodyChildWidthL, height=cfg.bodyChildHeight, padx=cfg.padding20, pady=cfg.padding10,
                                   fg=cfg.whiteColor, bg=cfg.primary_bg, relief=RIDGE, font=(cfg.fontFamily, cfg.tinyFont, cfg.fontWeight), text='Product item Details: ')
        LeftBodyFrame.pack(side=LEFT)

        # Right Body Frame Slider
        RightBodyFrame = LabelFrame(BodyFrame, bd=cfg.borderSmall, width=cfg.bodyChildWidthR, height=cfg.bodyChildHeight, padx=cfg.padding20, pady=cfg.padding10,
                                    fg=cfg.whiteColor, bg=cfg.primary_bg, relief=RIDGE, font=(cfg.fontFamily, cfg.tinyFont, cfg.fontWeight), text='Product list: ')
        RightBodyFrame.pack(side=RIGHT)

        ''' Add the Widgets to Left Body Frame '''

        # Form

        # label Id for Form
        self.labelpId = Label(LeftBodyFrame, font=(
            cfg.fontFamily, cfg.tinyFont, cfg.fontWeight), text="Enter Product Id", padx=2, pady=2, bg=cfg.primary_bg, fg=cfg.fontColor)
        self.labelpId.grid(row=0, column=0, sticky=W)

        # Input Id Variable Holder
        self.txtpId = Entry(LeftBodyFrame, font=(
            cfg.fontFamily, cfg.smallFont, cfg.fontWeight), textvariable=pId, width=cfg.inputWidth, bg=cfg.inputColor, fg=cfg.inputFontColor)
        self.txtpId.grid(row=0, column=1, sticky=W)

        # label Name for Form
        self.labelpName = Label(LeftBodyFrame, font=(
            cfg.fontFamily, cfg.tinyFont, cfg.fontWeight), text="Enter Product Name: ", padx=2, pady=2, bg=cfg.primary_bg, fg=cfg.fontColor)
        self.labelpName.grid(row=1, column=0, sticky=W)

        # Input Name Variable Holder
        self.txtpName = Entry(LeftBodyFrame, font=(
            cfg.fontFamily, cfg.smallFont, cfg.fontWeight), textvariable=pName, width=cfg.inputWidth, bg=cfg.inputColor, fg=cfg.inputFontColor)
        self.txtpName.grid(row=1, column=1, sticky=W)

        # label Price for Form
        self.labelpPrice = Label(LeftBodyFrame, font=(
            cfg.fontFamily, cfg.tinyFont, cfg.fontWeight), text="Enter Product Price: ", padx=2, pady=2, bg=cfg.primary_bg, fg=cfg.fontColor)
        self.labelpPrice.grid(row=2, column=0, sticky=W)

        # Input Price Variable Holder
        self.txtpPrice = Entry(LeftBodyFrame, font=(
            cfg.fontFamily, cfg.smallFont, cfg.fontWeight), textvariable=pPrice, width=cfg.inputWidth, bg=cfg.inputColor, fg=cfg.inputFontColor)
        self.txtpPrice.grid(row=2, column=1, sticky=W)

        # label Qty for Form
        self.labelpQty = Label(LeftBodyFrame, font=(
            cfg.fontFamily, cfg.tinyFont, cfg.fontWeight), text="Enter Product Qty: ", padx=2, pady=2, bg=cfg.primary_bg, fg=cfg.fontColor)
        self.labelpQty.grid(row=3, column=0, sticky=W)

        # Input Qty Variable Holder
        self.txtpQty = Entry(LeftBodyFrame, font=(
            cfg.fontFamily, cfg.smallFont, cfg.fontWeight), textvariable=pQty, width=cfg.inputWidth, bg=cfg.inputColor, fg=cfg.inputFontColor)
        self.txtpQty.grid(row=3, column=1, sticky=W)

        # label Company for Form
        self.labelpCompany = Label(LeftBodyFrame, font=(
            cfg.fontFamily, cfg.tinyFont, cfg.fontWeight), text="Enter Product Company Name: ", padx=2, pady=2, bg=cfg.primary_bg, fg=cfg.fontColor)
        self.labelpCompany.grid(row=4, column=0, sticky=W)

        # Input Company Variable Holder
        self.txtpCompany = Entry(LeftBodyFrame, font=(
            cfg.fontFamily, cfg.smallFont, cfg.fontWeight), textvariable=pCompany, width=cfg.inputWidth, bg=cfg.inputColor, fg=cfg.inputFontColor)
        self.txtpCompany.grid(row=4, column=1, sticky=W)

        # label Contact for Form
        self.labelpContact = Label(LeftBodyFrame, font=(
            cfg.fontFamily, cfg.tinyFont, cfg.fontWeight), text="Enter Product Company Contact: ", padx=2, pady=2, bg=cfg.primary_bg, fg=cfg.fontColor)
        self.labelpContact.grid(row=5, column=0, sticky=W)

        # Input Contact Variable Holder
        self.txtpContact = Entry(LeftBodyFrame, font=(
            cfg.fontFamily, cfg.smallFont, cfg.fontWeight), textvariable=pContact, width=cfg.inputWidth, bg=cfg.inputColor, fg=cfg.inputFontColor)
        self.txtpContact.grid(row=5, column=1, sticky=W)

        # # label Dummy for Form
        # self.labelpDummy = Label(LeftBodyFrame, padx=2, pady=2)
        # self.labelpDummy.grid(row=6, column=0, sticky=W)

        ''' Add Scroll bar '''
        # Scroll Parent
        scroll = Scrollbar(RightBodyFrame)
        scroll.grid(row=0, column=1, sticky='ns')

        # Product List
        productList = Listbox(RightBodyFrame, width=40, height=16, font=(
            cfg.fontFamily, 12, cfg.fontWeight), yscrollcommand=scroll.set, fg=cfg.listColor)

        # Called productRec by scroll list
        productList.bind('<<ListboxSelect>>', productRec)

        productList.grid(row=0, column=0, padx=8)
        scroll.config(command=productList.yview)

        ''' Add the Buttonto Operation Frame '''

        # Save Button
        self.buttonSave = Button(OperationFrame, text="Save Data", font=(
            cfg.fontFamily, cfg.smallFont, cfg.fontWeight), height=cfg.btn_height, width=cfg.btn_width, bd=cfg.borderLight, bg=cfg.btn_primary, fg=cfg.btn_secondary, command=insert)
        self.buttonSave.grid(row=0, column=0)

        # Show Button
        self.buttonShow = Button(OperationFrame, text="Show All Data", font=(
            cfg.fontFamily, cfg.smallFont, cfg.fontWeight), height=cfg.btn_height, width=cfg.btn_width, bd=cfg.borderLight, bg=cfg.btn_primary, fg=cfg.btn_secondary, command=showlist)
        self.buttonShow.grid(row=0, column=1)

        # Clear Button
        self.buttonClear = Button(OperationFrame, text="Reset", font=(
            cfg.fontFamily, cfg.smallFont, cfg.fontWeight), height=cfg.btn_height, width=cfg.btn_width, bd=cfg.borderLight, bg=cfg.btn_primary, fg=cfg.btn_secondary, command=clear)
        self.buttonClear.grid(row=0, column=2)

        # Delete Button
        self.buttonDelete = Button(OperationFrame, text="Delete Data", font=(
            cfg.fontFamily, cfg.smallFont, cfg.fontWeight), height=cfg.btn_height, width=cfg.btn_width, bd=cfg.borderLight, bg=cfg.btn_primary, fg=cfg.btn_secondary, command=delete)
        self.buttonDelete.grid(row=0, column=3)

        # Update Button
        self.buttonUpdate = Button(OperationFrame, text="Update Data", font=(
            cfg.fontFamily, cfg.smallFont, cfg.fontWeight), height=cfg.btn_height, width=cfg.btn_width, bd=cfg.borderLight, bg=cfg.btn_primary, fg=cfg.btn_secondary, command=update)
        self.buttonUpdate.grid(row=0, column=4)

        # Search Button
        self.buttonSearch = Button(OperationFrame, text="Search Data", font=(
            cfg.fontFamily, cfg.smallFont, cfg.fontWeight), height=cfg.btn_height, width=cfg.btn_width, bd=cfg.borderLight, bg=cfg.btn_primary, fg=cfg.btn_secondary, command=search)
        self.buttonSearch.grid(row=0, column=5)

        # Close Button
        self.buttonClose = Button(OperationFrame, text="Close", font=(
            cfg.fontFamily, cfg.smallFont, cfg.fontWeight), height=cfg.btn_height, width=cfg.btn_width, bd=cfg.borderLight, bg=cfg.btn_primary, fg=cfg.btn_secondary, command=close)
        self.buttonClose.grid(row=0, column=6)

        # Show if any data in DB
        showlist()
