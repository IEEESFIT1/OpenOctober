import socket
host='127.0.0.1'
port=8000
#Create server side socket
s=socket.socket()
s.bind((host,port))
print ("Server is Waiting.........")
#Allow max clients connections=1
s.listen(1)
# wait till client connects
c,addr=s.accept()
print ("A Client is connected")
#Server runs continiously
while True:
    #receive 1024 byte data from client
    data=c.recv(1024)
    # if client send empty string then come out
    if not data:
        break
    print ("From Client: "+str(data.decode()))
    # Enter response from server
    data1=input("From Server : ")
    # Send data to the client
    c.send(data1.encode())
#Close Connection
c.close()
