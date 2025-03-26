# RSA Cryptography Demo - Sample Output

# Steps for execution: 

# 1. Run the Server First

Start the server:

    python RSAserver.py

The server will start and wait for a connection from the client.

# 2. Run the Client in a New Terminal

1. Start the client:

        python RSAclient.py

2. Enter a message when prompted.

    1. The client will encrypt the message and send it to the server.

    2. The server will decrypt the message and display it.

# Expected Ouptut

Server Terminal:

        PS D:\CNS Assignments\RSA_Cryptosystem_Demo> python RSAserver.py
        Private key of B is: 11
        Public key of B is: 35 221
        Enter message for server: 45
        Encrpyted message from server recieved: 141
        After decryption: 45

Client Terminal:

        PS D:\CNS Assignments\RSA_Cryptosystem_Demo> python RSAclient.py
        Private key of A is: = 53
        Public key of A is: 29 221
        Socket successfully created
        socket binded to 1237
        socket is listening
        Got connection from ('127.0.0.1', 64159)
        Enter message for client: 45
        Encrpyted message from client recieved: 41
        After decryption: 45
