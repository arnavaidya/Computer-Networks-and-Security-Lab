import socket
from Crypto.Cipher import DES

# Function to pad text to make it a multiple of 8 bytes
def pad(text):
    while len(text) % 8 != 0:
        text += ' '  # Padding with spaces
    return text

# Create socket object
server = socket.socket()
host = '127.0.0.1'
port = 5001

server.bind((host, port))
server.listen(1)
print("Server listening for connections...")

conn, addr = server.accept()
print(f"Connection established with {addr}")

conn.send("ServerUser".encode())  # Send server name

# Diffie-Hellman Key Exchange
P = int(conn.recv(1024).decode())
G = int(conn.recv(1024).decode())

private_key = int(input("Enter Server Private Key: "))
Y = pow(G, private_key, P)  # Compute Y = G^private_key mod P
conn.send(str(Y).encode())

X = int(conn.recv(1024).decode())  # Receive X from client
shared_key = pow(X, private_key, P)  # Compute shared secret key
print(f"Shared Secret Key for the Server is: {shared_key}")

# Convert key to 8 bytes for DES
key = str(shared_key).zfill(8).encode()[:8]

# DES Encryption Setup
cipher = DES.new(key, DES.MODE_ECB)

# Receive and decrypt message
cipher_text_received = conn.recv(1024)
decrypted_text = cipher.decrypt(cipher_text_received).decode().strip()
print(f"Decrypted Text from Client: {decrypted_text}")

# Encrypt and send response
response_text = input("Enter response message: ")
response_text = pad(response_text)  # Ensure multiple of 8
cipher_text = cipher.encrypt(response_text.encode())

conn.send(cipher_text)  # Send encrypted response
print("Cipher Text Sent to Client")

conn.close()
