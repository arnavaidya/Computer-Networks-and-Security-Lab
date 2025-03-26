# Socket Programming Demo - Sample Output

This folder contains implementations of simple TCP and UDP client-server programs in C. Below are sample outputs demonstrating their functionality.

# 1. TCP Server and Client Communication

Run the TCP Server:

    $ gcc tcpServer.c -o tcpServer
    $ ./tcpServer

Output:

    TCPServer Waiting for client on port 5000
    I got a connection from (127.0.0.1 , 34567)
    SEND (q or Q to quit) : Hello, Client!
    RECEIVED DATA = Hello, Server!
    SEND (q or Q to quit) : q

Run the TCP Client:

    $ gcc tcpClient.c -o tcpClient
    $ ./tcpClient

Output:

    Received data = Hello, Client!
    SEND (q or Q to quit) : Hello, Server!
    Received data = q

# 2. UDP Server and Client Communication

Run the UDP Server:

    $ gcc udpServer.c -o udpServer
    $ ./udpServer

Output:

    UDPServer Waiting for client on port 5000
    (127.0.0.1 , 54321) said : Hello, UDP Server!
    (127.0.0.1 , 54321) said : q

Run the UDP Client:

    $ gcc udpClient.c -o udpClient
    $ ./udpClient

Output:

    Type Something (q or Q to quit): Hello, UDP Server!
    Type Something (q or Q to quit): q

Notes:

1. The TCP server runs continuously and handles one client at a time.

2. The UDP server listens for messages and responds but does not maintain a connection.

3. To test, first start the server, then run the client.
