# 06 - Stop N Wait

## About the program

This program implements a simplified version of the Reliable Data Transfer (RDT) protocol using UDP (User Datagram Protocol). It consists of a server and a client communicating over a network. The server sends frames to the client, and the client sends acknowledgment (ACK) frames back to the server.

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

3. **Receiving frames from the client**

   ```c
   ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                    struct sockaddr *src_addr, socklen_t *addrlen);
   ```

4. **Sending acknowledgment (ACK) frames to the client**

   ```c
   ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
                  const struct sockaddr *dest_addr, socklen_t addrlen);
   ```

### Client

#### Steps for Client Operation:

1. **Creating a socket**

   ```c
   int socket(int domain, int type, int protocol);
   ```

2. **Sending frames to the server**

   ```c
   ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
                  const struct sockaddr *dest_addr, socklen_t addrlen);
   ```

3. **Receiving acknowledgment (ACK) frames from the server**

   ```c
   ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                    struct sockaddr *src_addr, socklen_t *addrlen);
   ```

## Algorithm

### Server

1. Create socket
2. Bind IP address and port number to the socket
3. Receive frames from the client
4. Send acknowledgment (ACK) frames to the client

### Client

1. Create socket
2. Send frames to the server
3. Receive acknowledgment (ACK) frames from the server

## Output

### Server

![06 - Stop n Wait - server](https://github.com/blackpeps/networklab2024/assets/126700907/a936b7e3-8ae9-4bee-9a1f-88c8c9a3fbbf)

### Client

![06 - Stop n Wait - client](https://github.com/blackpeps/networklab2024/assets/126700907/e351197f-31a5-41d0-92ea-3e9b3cfd80b2)
