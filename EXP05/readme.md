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

### SERVER

1. Create a TCP socket.
2. Clear memory space for socket address.
3. Set up socket address structure with server details.
4. Bind socket to server address.
5. Start listening for incoming connections.
6. Accept client connections.
7. Convert client's network address to a readable format.
8. Spawn a child process to handle client while the parent process stops listening.
9. Receive data from client.
10. Send received data back to client.
11. Print client's IP address.
12. Close the socket.

### CLIENT

1. Create a TCP socket.
2. Clear memory space for socket address.
3. Set up socket address structure with server details.
4. Connect to server.
5. Continuously read input from user.
6. Send user input to server.
7. Receive response from server.
8. Print server's response.
9. Repeat steps 5-8 as needed.

## Output

### Server

![05 - Multi-User TCP - server](https://github.com/blackpeps/networklab2024/assets/126700907/33bd6be6-1357-4162-b0d6-30551936e4e5)


### Client 1

![05 - Multi-User TCP - Client1](https://github.com/blackpeps/networklab2024/assets/126700907/e61eb91a-fac9-4eb7-95d6-d26549441176)

### Client 2

![05 - Multi-User TCP - client2](https://github.com/blackpeps/networklab2024/assets/126700907/2863a374-fb70-4dd8-8996-2e1a5f45c895)
