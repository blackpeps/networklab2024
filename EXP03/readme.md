# 03 - TCP (using Socket Programming)

## About the program

### The steps for creating a TCP connection by a client:

1. **Creation of Client Socket:**
   ```c
   int socket(int domain, int type, int protocol);
   ```
   This function call creates a socket and returns a socket descriptor. The `domain` parameter specifies the communication domain (e.g., `AF_INET` for IPv4). The `type` parameter specifies the communication semantics (`SOCK_STREAM` for TCP). The `protocol` parameter specifies the protocol used (typically 0 for default protocol).

2. **Filling the Fields of the Server Address Structure:**
   The socket address structure is of type `struct sockaddr_in`. Example:
   ```c
   struct sockaddr_in servaddr;
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(port_number);
   inet_pton(AF_INET, "IP_Address", &servaddr.sin_addr);
   ```
   Here, `htons` function is used to ensure correct representation of the port number in network byte order (big-endian). `inet_pton` converts the IP address from text to binary format.

3. **Binding of the Client Socket to a Local Port:**
   This step is optional for the client.

4. **Connection of Client to the Server:**
   A server is identified by an IP address and a port number. The `connect` operation is used on the client side to establish the connection to the server.
   ```c
   int connect(int sd, struct sockaddr *addr, int addrlen);
   ```
   Here, `sd` is the file descriptor of the local socket, `addr` is a pointer to the protocol address of the server socket, and `addrlen` is the length in bytes of the address structure.

5. **Reading from Socket:**
   Reading from a TCP socket can be done using the `read` system call.
   ```c
   int read(int sd, char *buf, int length);
   ```

6. **Writing to Socket:**
   Writing to a TCP socket can be done using the `write` system call.
   ```c
   int write(int sd, char *buf, int length);
   ```

7. **Closing the Connection:**
   The connection can be closed using the `close` system call.
   ```c
   int close(int sd);
   ```

These are the essential steps involved in establishing a TCP connection from a client perspective.

### Steps for TCP Connection for server

1. **Creating a listening socket**

   ```c
   int socket(int domain, int type, int protocol);
   ```

   This system call creates a socket and returns a socket descriptor. The domain field used is AF_INET. The socket type is SOCK_STREAM. The protocol field is 0. If the system call is a failure, a -1 is returned. Header files used are sys/types.h and sys/socket.h.

2. **Binding to a local port**

   ```c
   int bind(int sd, struct sockaddr *addr, int addrlen);
   ```

   This call is used to specify for a socket the protocol port number where it will wait for messages. A call to bind is optional on the client side, but required on the server side. The first field is the socket descriptor of local socket. Second is a pointer to protocol address structure of this socket. The third is the length in bytes of the structure referenced by addr. This system call returns an integer. It is 0 for success and -1 for failure. The header files are sys/types.h and sys/socket.h.

3. **Listening on the port**

   The listen function is used on the server in the connection oriented communication to prepare a socket to accept messages from clients.

   ```c
   int listen(int fd, int qlen);
   ```

   `fd` – file descriptor of a socket that has already been bound. `qlen` – specifies the maximum number of messages that can wait to be processed by the server while the server is busy servicing another request. Usually it is taken as 5. The header files used are sys/types.h and sys/socket.h. This function returns 0 on success and -1 on failure.

4. **Accepting a connection from the client**

   The accept function is used on the server in the case of connection oriented communication to accept a connection request from a client.

   ```c
   int accept(int fd, struct sockaddr *addressp, int *addrlen);
   ```

   The first field is the descriptor of server socket that is listening. The second parameter `addressp` points to a socket address structure that will be filled by the address of calling client when the function returns. The third parameter `addrlen` is an integer that will contain the actual length of address structure of client. It returns an integer that is a descriptor of a new socket called the connection socket. Server sockets send data and read data from this socket. The header files used are sys/types.h and sys/socket.h.

## Algorithm

### Client

1. Create socket
2. Connect the socket to the server
3. Read the string to be reversed from the standard input and send it to the server
   Read the matrices from the standard input and send them to the server using the socket
4. Read the reversed string from the socket and display it on the standard output
   Read the product matrix from the socket and display it on the standard output
5. Close the socket

### Server

1. Create listening socket
2. Bind IP address and port number to the socket
3. Listen for incoming requests on the listening socket
4. Accept the incoming request
5. Connection socket is created when accept returns
6. Read the string using the connection socket from the client
7. Reverse the string
8. Send the string to the client using the connection socket
9. Close the connection socket
10. Close the listening socket

## OUTPUT

> After the compilation of server and client C files, the output of the server needs to be executed first, followed by the client.

### Client

![client](https://github.com/blackpeps/networklab2024/assets/126700907/c31ead7e-238c-4311-b100-f9d8ced24dcc)

### Server

![server](https://github.com/blackpeps/networklab2024/assets/126700907/77e53aef-58b7-4b86-bb0a-67ee4d940ba9)
