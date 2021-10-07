import socket
host='127.0.0.1'
port=8000
#Create client side socket
s=socket.socket()
s.connect((host,port))
# Enter message at Client side
str1=input("Enter your message or press exit to quit : ")
# Continue till client exits
while str1!='exit':
    # Send data from client to server
    s.send(str1.encode())
    #receive 1024 byte data from client
    data=s.recv(1024)
    data1=data.decode()
    print ("From server :",data1)
    #Enter data
    str1=input("Enter data : ")
#Close Connection
s.close()
