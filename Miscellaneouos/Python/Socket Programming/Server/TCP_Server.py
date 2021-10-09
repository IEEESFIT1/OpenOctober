import socket
s=socket.socket()
s.bind(('127.0.0.1', 8888))
print('Server is listening and waiting for a connection')
s.listen(1)
c,addr=s.accept()
#c1, addr=s.accept()
print("A client is connected")
def ADD():
    c.send(("Enter number 1").encode())
    a=int(c.recv(2048).decode())
    c.send(("Enter number 2").encode())
    b=int(c.recv(2048).decode())
    c.send(str(a+b).encode())
    return
def REVERSE():
    c.send(("Enter String to be reversed").encode())
    c.send(str((c.recv(2048).decode())[::-1]).encode())
    return
def FILE_CONTENTS(fname):
    f = open(fname,"r")
    c.send(f.read().encode())
    f.close()
    return
def FILE_TRANSFER_CLIENT2SERVER():
    f1 = open("Demo1.txt", "w")
    f1.write(c.recv(2048).decode())
    print("File Transfer Successful")
    f1.close()
    f1 = open("Demo1.txt", "r")
    print("New File (Demo 1) Contents are ")
    print(f1.read())
def FILE_TRANSFER_SERVER2CLIENT():
    filename = c.recv(2048).decode()
    print("Client requests file",filename)
    f = open(filename, "r")
    c.send(f.read().encode())
    f.close()
while True:
    data=c.recv(2048)
    #data2=c1.recv(2048)
    print("Client: "+str(data.decode()))
    if (data.decode())=="Quit":
        print("Client disconnectes session")
        c.send(("Bye Thanks for Joining").encode())
        break
    elif (data.decode())=="Add":
        ADD()
        continue
    elif (data.decode())=="Reverse":
        REVERSE()
        continue
    elif (data.decode())=="File Contents":
        c.send(("Enter Name of file").encode())
        fname = c.recv(2048).decode()
        FILE_CONTENTS(fname)
        continue
    elif (data.decode())=="File Transfer":
        ch = c.recv(2048).decode()
        if ch == "Client to Server":
            FILE_TRANSFER_CLIENT2SERVER()
        else:
            FILE_TRANSFER_SERVER2CLIENT()
        continue
    data1=input()
    c.send(data1.encode())
    '''data3=input()
    c1.send(data3.encode())'''
c.close()
#c1.close()
