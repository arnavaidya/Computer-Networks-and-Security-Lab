import socket
from Crypto.Cipher import DES

# Function to pad text to make it a multiple of 8 bytes
def pad(text):
    while len(text) % 8 != 0:
        text += ' '  # Padding with spaces
    return text

# Create a socket object
client = socket.socket()
host = '127.0.0.1'
port = 5001

client.connect((host, port))

# Receive and display server message
server_name = client.recv(1024).decode()
print(f"{server_name} has joined the Client")

# Diffie-Hellman Key Exchange
P = int(input("Enter the Value of Prime Number P: "))
G = int(input("Enter the Value of Prime Number G: "))
client.send(str(P).encode())
client.send(str(G).encode())

private_key = int(input("Enter Client Private Key: "))
X = pow(G, private_key, P)  # Compute X = G^private_key mod P
client.send(str(X).encode())

Y = int(client.recv(1024).decode())  # Receive Y from server
shared_key = pow(Y, private_key, P)  # Compute shared secret key
print(f"Shared Secret Key for the Client is: {shared_key}")

# Convert key to 8 bytes for DES
key = str(shared_key).zfill(8).encode()[:8]

# DES Encryption Setup
cipher = DES.new(key, DES.MODE_ECB)

# Encrypt message
plain_text = input("Enter the Plain Text: ")
plain_text = pad(plain_text)  # Ensure multiple of 8
cipher_text = cipher.encrypt(plain_text.encode())

client.send(cipher_text)  # Send encrypted message
print("Cipher Text Sent to Server")

# Receive and decrypt message from the server
cipher_text_received = client.recv(1024)
decrypted_text = cipher.decrypt(cipher_text_received).decode().strip()
print(f"Decrypted Text from Server: {decrypted_text}")

client.close()
#End