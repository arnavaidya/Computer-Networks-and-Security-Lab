Socket Programming Demo - Sample Output

This repository contains implementations of simple TCP and UDP client-server programs in C. Below are sample outputs demonstrating their functionality.

1. TCP Server and Client Communication

Run the TCP Server:

$ gcc tcp_server.c -o tcp_server
$ ./tcp_server

Output:

TCPServer Waiting for client on port 5000
I got a connection from (127.0.0.1 , 34567)
SEND (q or Q to quit) : Hello, Client!
RECEIVED DATA = Hello, Server!
SEND (q or Q to quit) : q

Run the TCP Client:

$ gcc tcp_client.c -o tcp_client
$ ./tcp_client

Output:

Received data = Hello, Client!
SEND (q or Q to quit) : Hello, Server!
Received data = q

2. UDP Server and Client Communication

Run the UDP Server:

$ gcc udp_server.c -o udp_server
$ ./udp_server

Output:

UDPServer Waiting for client on port 5000
(127.0.0.1 , 54321) said : Hello, UDP Server!
(127.0.0.1 , 54321) said : q

Run the UDP Client:

$ gcc udp_client.c -o udp_client
$ ./udp_client

Output:

Type Something (q or Q to quit): Hello, UDP Server!
Type Something (q or Q to quit): q

Notes:

The TCP server runs continuously and handles one client at a time.

The UDP server listens for messages and responds but does not maintain a connection.

To test, first start the server, then run the client.