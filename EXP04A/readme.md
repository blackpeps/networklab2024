# Matrix Multiplication (UDP)

## About the program

This program demonstrates a client-server model using UDP (User Datagram Protocol) for matrix multiplication. The client sends two matrices to the server, which performs the multiplication and sends the result back to the client.

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

3. **Receiving matrices from the client**

   ```c
   ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                    struct sockaddr *src_addr, socklen_t *addrlen);
   ```

4. **Performing matrix multiplication**

5. **Sending the result to the client**

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

2. **Sending matrices to the server**

   ```c
   ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
                  const struct sockaddr *dest_addr, socklen_t addrlen);
   ```

3. **Receiving the result from the server**

   ```c
   ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                    struct sockaddr *src_addr, socklen_t *addrlen);
   ```

## Algorithm

### Server

1. Create socket
2. Bind IP address and port number to the socket
3. Receive size and elements of matrices A and B from client
4. Perform matrix multiplication
5. Send the result matrix to the client
6. Close the socket

### Client

1. Create socket
2. Enter the dimensions and elements of matrices A and B
3. Send size and elements of matrices A and B to server
4. Receive the result matrix from the server
5. Display the result matrix
6. Close the socket

## Output

### Server.c

![Screenshot from 2024-03-04 19-06-03](https://github.com/blackpeps/networklab2024/assets/126700907/1a359f7d-2739-449b-bb44-153c80727d96)

### Client.c

![Screenshot from 2024-03-04 19-06-06](https://github.com/blackpeps/networklab2024/assets/126700907/f3b4e450-ee6f-419a-b2ba-c2180d40d1ff)
