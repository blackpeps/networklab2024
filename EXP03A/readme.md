# String reverse (TCP)

## About the program

This program demonstrates a client-server model using TCP sockets to reverse a string. The client sends a string to the server, which then reverses it and sends it back to the client.

### Server

#### Steps for Server Operation:

1. **Creating a socket**

   ```c
   int socket(int domain, int type, int protocol);
   ```

2. **Binding to a local port**

   ```c
   int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
   ```

3. **Listening for connections**

   ```c
   int listen(int sockfd, int backlog);
   ```

4. **Accepting incoming connections**

   ```c
   int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
   ```

5. **Receiving data from clients**

   ```c
   ssize_t read(int fd, void *buf, size_t count);
   ```

6. **Sending data to clients**

   ```c
   ssize_t send(int sockfd, const void *buf, size_t len, int flags);
   ```

### Client

#### Steps for Client Operation:

1. **Creating a socket**

   ```c
   int socket(int domain, int type, int protocol);
   ```

2. **Connecting to the server**

   ```c
   int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
   ```

3. **Sending data to the server**

   ```c
   ssize_t send(int sockfd, const void *buf, size_t len, int flags);
   ```

4. **Receiving data from the server**

   ```c
   ssize_t read(int fd, void *buf, size_t count);
   ```

## Algorithm

### Server

1. Create socket
2. Bind IP address and port number to the socket
3. Listen for incoming connections
4. Accept incoming connection from client
5. Receive string from client
6. Reverse the string
7. Send reversed string to client
8. Close the socket

### Client

1. Create socket
2. Connect to the server
3. Send string to server
4. Receive reversed string from server
5. Close the socket

## Output

### Server.c

![Screenshot from 2024-03-04 18-59-55](https://github.com/blackpeps/networklab2024/assets/126700907/cf10f42c-e2f9-4657-8452-ff416ba9a99e)

### Client.c

![Screenshot from 2024-03-04 19-00-01](https://github.com/blackpeps/networklab2024/assets/126700907/511c8cad-b732-4c8c-b90c-41d059d2b838)
