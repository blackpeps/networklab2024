# 04 - UDP (using Socket Programming)

## About the program

### Steps for transfer of data using UDP

1. **Creation of UDP socket**

   The function call for creating a UDP socket is
   
   ```c
   int socket(int domain, int type, int protocol);
   ```
   
   The domain parameter specifies a communication domain; this selects the protocol family which will be used for communication. These families are defined in `<sys/socket.h>`. In this program, the domain `AF_INET` is used. The next field type has the value `SOCK_DGRAM`. It supports datagrams (connectionless, unreliable messages of a fixed maximum length). The protocol field specifies the protocol used. We always use 0. If the `socket` function call is successful, a socket descriptor is returned. Otherwise -1 is returned. The header files necessary for this function call are `sys/types.h` and `sys/socket.h`.
   
2. **Filling the fields of the server address structure**

   The socket address structure is of type `struct sockaddr_in`.
   
   ```c
   struct sockaddr_in {
       u_short sin_family;
       u_short sin_port;
       struct in_addr sin_addr;
       char sin_zero[8]; /* unused, always zero */
   };
   
   struct in_addr {
       u_long s_addr;
   };
   ```
   
   The fields of the socket address structure are:
   - `sin_family` which in our case is `AF_INET`
   - `sin_port` which is the port number where socket binds
   - `sin_addr` is used to store the IP address of the server machine and is of type `struct in_addr`
   
   The value for `servaddr.sin_addr` is assigned using the following function:
   
   ```c
   inet_pton(AF_INET, "IP_Address", &servaddr.sin_addr);
   ```
   
   The binary value of the dotted decimal IP address is stored in the field when the function returns.
   
   The header file that is to be used is `netinet/in.h`.
   
3. **Binding of a port to the socket in the case of server**

   This call is used to specify for a socket the protocol port number where it will wait for messages. A call to `bind` is optional in the case of client and compulsory on the server side.
   
   ```c
   int bind(int sd, struct sockaddr* addr, int addrlen);
   ```
   
   The first field is the socket descriptor. The second is a pointer to the address structure of this socket. The third field is the length in bytes of the size of the structure referenced by `addr`. The header files are `sys/types.h` and `sys/socket.h`. This function call returns an integer, which is 0 for success and -1 for failure.
   
4. **Receiving data**

   ```c
   ssize_t recvfrom(int s, void *buf, size_t len, int flags, struct sockaddr *from, socklen_t *fromlen);
   ```
   
   The `recvfrom` calls are used to receive messages from a socket, and may be used to receive data on a socket whether or not it is connection oriented. The first parameter `s` is the socket descriptor to read from. The second parameter `buf` is the buffer to read information into. The third parameter `len` is the maximum length of the buffer. The fourth parameter is `flag`, which is set to zero. The fifth parameter `from` is a pointer to `struct sockaddr` variable that will be filled with the IP address and port of the originating machine. The sixth parameter `fromlen` is a pointer to a local `int` variable that should be initialized to `sizeof(struct sockaddr)`. When the function returns, the integer variable that `fromlen` points to will contain the actual number of bytes that is contained in the socket address structure. The header files required are `sys/types.h` and `sys/socket.h`. When the function returns, the number of bytes received is returned or -1 if there is an error.
   
5. **Sending data**

   ```c
   ssize_t sendto(int s, const void *buf, size_t len, int flags, const struct sockaddr *to, socklen_t tolen);
   ```
   
   The first parameter `s` is the socket descriptor of the sending socket. The second parameter `buf` is the array which stores data that is to be sent. The third parameter `len` is the length of that data in bytes. The fourth parameter is the `flag` parameter, which is set to zero. The fifth parameter `to` points to a variable that contains the destination IP address and port. The sixth parameter `tolen` is set to `sizeof(struct sockaddr)`. This function returns the number of bytes actually sent or -1 on error. The header files used are `sys/types.h` and `sys/socket.h`.

## Algorithm

### Client

1. Create socket
2. Read the matrices from the standard input and send them to the server using the socket
3. Read the product matrix from the socket and display it on the standard output
4. Close the socket

### Server

1. Create socket
2. Bind IP address and port number to the socket
3. Read the matrices from the client using the socket
4. Find the product of matrices
5. Send the product matrix to the client using the socket
6. Close the socket

## Output

### Client

![client](https://github.com/blackpeps/networklab2024/assets/126700907/cd3950c2-208a-4531-b701-1ef5f0de14d7)

### Server


![server](https://github.com/blackpeps/networklab2024/assets/126700907/7c57c6be-2202-4e8c-be47-5098cb6e4df9)
