# 04 - UDP (using Socket Programming)

## About the program

This program demonstrates the use of UDP (User Datagram Protocol) for communication between a client and a server. UDP is a connectionless protocol where data packets are sent without establishing a connection. This makes UDP faster but less reliable compared to TCP.

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

3. **Receiving data from clients**

   ```c
   ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                    struct sockaddr *src_addr, socklen_t *addrlen);
   ```

4. **Sending data to clients**

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

2. **Sending data to the server**

   ```c
   ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
                  const struct sockaddr *dest_addr, socklen_t addrlen);
   ```

3. **Receiving data from the server**

   ```c
   ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                    struct sockaddr *src_addr, socklen_t *addrlen);
   ```

## Algorithm

### Server

1. Create socket
2. Bind IP address and port number to the socket
3. Receive data from clients
4. Send response to clients
5. Close the socket

### Client

1. Create socket
2. Send data to the server
3. Receive response from the server
4. Close the socket

## Output

### Client

![client](https://github.com/blackpeps/networklab2024/assets/126700907/cd3950c2-208a-4531-b701-1ef5f0de14d7)

### Server


![server](https://github.com/blackpeps/networklab2024/assets/126700907/7c57c6be-2202-4e8c-be47-5098cb6e4df9)
