# RSA Digital Signature Cryptosystem Demo - Sample Output

# Overview

This project demonstrates a basic implementation of the RSA Digital Signature Cryptosystem using Python sockets. It consists of a server and a client that communicate securely using RSA encryption. The server and client exchange public keys and encrypted messages to ensure secure communication.

# Steps for execution

# Step 1: Run the Server

1. Open a terminal and navigate to the project folder.

2. Start the server using:

        python server.py

3. The server will generate an RSA key pair and listen for client connections.

# Step 2: Run the Client

1. Open another terminal and navigate to the same project folder.

2. Start the client using:

        python client.py

3. The client will generate its RSA key pair and establish a connection with the server.

4. The server and client will exchange public keys and securely transmit messages.

# Expected Output

The server and client will display their generated public and private keys.

Messages sent between them will be encrypted and decrypted using RSA.

Example:

Server Terminal: 

    PS D:\CNS Assignments\RSA_Digital_Signature_Cryptosystem_Demo> python RSAserver.py
    Private key of A is: = 7
    Public key of A is: 55 221
    Socket successfully created
    socket binded to 1232
    socket is listening
    Got connection from ('127.0.0.1', 64282)
    Enter message for client: 60
    Encrpyted message from client recieved: 84
    After decryption: 50

Client Terminal: 

    PS D:\CNS Assignments\RSA_Digital_Signature_Cryptosystem_Demo> python RSAclient.py
    Private key of B is: 95
    Public key of B is: 95 221
    Enter message for server: 50
    Encrpyted message from server recieved: 70
    After decryption: 60
