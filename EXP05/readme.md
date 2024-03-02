# 05 - Multi-User Chat with TCP

## About the program

This program implements a simple multi-user chat system using TCP sockets. It consists of a server and a client component. The server waits for incoming connections from clients and relays messages between them. The client connects to the server and allows users to send and receive messages.

### Server

#### Steps for Server Operation:

1. **Creating a listening socket**

   ```c
   int socket(int domain, int type, int protocol);
   ```

2. **Binding to a local port**

   ```c
   int bind(int sd, struct sockaddr *addr, int addrlen);
   ```

3. **Listening on the port**

   ```c
   int listen(int fd, int qlen);
   ```

4. **Accepting a connection from the client**

   ```c
   int accept(int fd, struct sockaddr *addressp, int *addrlen);
   ```

### Client

#### Steps for Client Operation:

1. **Creation of Client Socket**

   ```c
   int socket(int domain, int type, int protocol);
   ```

2. **Filling the Fields of the Server Address Structure**

   ```c
   struct sockaddr_in servaddr;
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(port_number);
   inet_pton(AF_INET, "IP_Address", &servaddr.sin_addr);
   ```

3. **Connection of Client to the Server**

   ```c
   int connect(int sd, struct sockaddr *addr, int addrlen);
   ```

4. **Reading from Socket**

   ```c
   int read(int sd, char *buf, int length);
   ```

5. **Writing to Socket**

   ```c
   int write(int sd, char *buf, int length);
   ```

6. **Closing the Connection**

   ```c
   int close(int sd);
   ```

## Algorithm

### Server

1. Create listening socket
2. Bind IP address and port number to the socket
3. Listen for incoming requests on the listening socket
4. Accept the incoming request
5. Read messages from clients and relay them to other clients
6. Close the connection socket

### Client

1. Create socket
2. Connect the socket to the server
3. Send messages to the server
4. Receive messages from the server
5. Close the socket

## Output

### Server

![05 - Multi-User TCP - server](https://github.com/blackpeps/networklab2024/assets/126700907/33bd6be6-1357-4162-b0d6-30551936e4e5)


### Client 1

![05 - Multi-User TCP - Client1](https://github.com/blackpeps/networklab2024/assets/126700907/e61eb91a-fac9-4eb7-95d6-d26549441176)

### Client 2

![05 - Multi-User TCP - client2](https://github.com/blackpeps/networklab2024/assets/126700907/2863a374-fb70-4dd8-8996-2e1a5f45c895)
