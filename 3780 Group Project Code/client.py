import socket
import threading
import struct

def conError():
    print ("connection error")
    s.close()

def estConnection(port, host):
    address = (host,port)
    #send 1
    sent = sock.sendto(b'10', address)
    print("sending {} bytes to {} ".format(sent,address))
    #receive 1
    data, addr = sock.recvfrom(1024)
    if data:
        print ("data received: ", data)
        #send 2
        sent = sock.sendto(b'ack', address)
        print("sending {} to {}".format(sent, address))
        print("connection established")
        return data
    else:
        return None

def disconnection(data, soc,addr):
    if data == b'close':
        soc.sendto(b'terminated', (server, port))
        d, addr = soc.recvfrom(1024)
        if d == b'okay':
            print("Connection gracefully terminated")
            return True
    return False

# Creates a packet from a sequence number and byte data
def makePacket(seqNum, data = b''):
    seqBytes = seqNum.to_bytes(4, byteorder = 'little', signed = True)
    return seqBytes + data

# Extracts sequence number and data from a non-empty packet
def extractPacket(packet):
    seqNum = int.from_bytes(packet[0:4], byteorder = 'little', signed = True)
    return seqNum, packet[4:]

# Receive packets from server
def receive():
	expectedNum = 0
    while True:
        # Get the next packet from the sender
        packet, addr = sock.recvfrom(buffer)
        if not packet:
            break
        seqNum, data = extractPacket(packet)
        print('Got packet', seqNum)
        
        # Send back an ACK
        if seqNum == expectedSeq:
            print('Got expected packet')
            print('Sending ACK', expectedNum)
            packet = packet.make(expectedNum)
            sock.sendto(packet, addr)
            expectedNum += 1
            file.write(data)
        else:
            print('Sending ACK', expectedNum - 1)
            packet = makePacket(expectedNum - 1)
			sock.sendto(packet, addr)
    file.close()

buffer = 1024

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
host = socket.gethostname()
port = 8000
server= "142.66.140.56"#"142.66.140.48"
data = estConnection(port, server)

while data:
    data, addr = sock.recvfrom(1024) #recieve array
    print("recieving: {} from {}".format(data,addr))
    #send 3
    # ack = 0
    # sock.sendto(bytes(ack),(server, port))
    # ack += 1
    closed = disconnection(data, sock,addr)
    if closed:
        break