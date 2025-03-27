# DES Algorithm Demo - Sample Output

# Steps for Execution:

# 1️. Run the Server First

1. Start the server by executing the following command in the terminal:

    python DESserver.py

2. The server will start and wait for a connection from the client.

# 2️. Run the Client in a New Terminal

1. Start the client by executing:

    python DESclient.py

2. Enter a message when prompted.

3. The client will encrypt the message and send it to the server.

4. The server will decrypt the message and display it.

# Expected Output:

Server Terminal:

    PS D:\CNS Assignments\DES_Algorithm_Demo> python DESserver.py
    Server listening for connections...
    Connection established with ('127.0.0.1', 65203)
    Enter Server Private Key: 15
    Shared Secret Key for the Server is: 2
    Decrypted Text from Client: Hello Server
    Enter response message: Hi Client
    Cipher Text Sent to Client

Client Terminal:

    PS C:\Users\admin> cd D:\"CNS Assignments"\DES_Algorithm_Demo
    PS D:\CNS Assignments\DES_Algorithm_Demo> python DESclient.py
    ServerUser has joined the Client
    Enter the Value of Prime Number P: 23
    Enter the Value of Prime Number G: 5
    Enter Client Private Key: 6
    Shared Secret Key for the Client is: 2
    Enter the Plain Text: Hello Server
    Cipher Text Sent to Server
    Decrypted Text from Server: Hi Client

# Notes:

1. The program uses DES (Data Encryption Standard) for secure communication between the client and server.
2. It incorporates Diffie-Hellman key exchange to establish a shared secret key.
3. Ensure that the server is started before running the client.
4. If you face an issue with Crypto.Cipher, install dependencies using:

        pip install pycryptodome



