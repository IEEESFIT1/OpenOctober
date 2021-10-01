import socket
s=socket.socket()
print("Connecting to a Server...")
s.connect(('127.0.0.1', 8888))
print("Connected to Server!")
def FILE_TRANSFER_CLIENT2SERVER():
    filename = input("Enter file name to transfer ")
    f = open(filename, "r")
    s.send(f.read().encode())
    f.close()
def FILE_TRANSFER_SERVER2CLIENT():
    filename = input("Enter file name needed ")
    s.send(filename.encode())
    f1 = open("Demo2.txt", "w")
    f1.write(s.recv(2048).decode())
    print("File Transfer Successful")
    f1.close()
    f1 = open("Demo1.txt", "r")
    print("New File (Demo 2) Contents are ")
    print(f1.read())
while True:
    data=input()
    s.send(data.encode())
    if data == "Quit":
        print(s.recv(2048).decode())
        break
    elif data == "File Transfer":
        ch = input("Client to Server or Server to Client: ")
        s.send(ch.encode())
        if ch == "Client to Server":
            FILE_TRANSFER_CLIENT2SERVER()
        else:
            FILE_TRANSFER_SERVER2CLIENT()
        continue
    data1=s.recv(2048)
    print("Server: "+data1.decode())
s.close
