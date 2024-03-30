# 08 - Concurrent Time Server

## Aim

Implement a Concurrent time server using UDP as a transport layer protocol by executing the program at a remote server. The client sends a time request to the Server, and the Server sends its system time back to the client. The client then displays the result.

## Problem Description

Using UDP socket, create a connection between multiple clients and a single time server.

### Algorithm – UDP SERVER

1. Create a socket for UDP using the function call `socket(AF_INET, SOCK_DGRAM, 0)`.
2. Declare a time object variable `ct` of data type `time_t`.
3. Use `bzero()` function to place null bytes of memory area pointed to by local.
   ```
   bzero((char*)&servaddr,sizeof(servaddr));
   ```
4. Initialize the structure `sockaddr_in` members of `sin_family`, `sin_addr`, `sin_port`.
5. Bind the socket to its port using `bind(s,(struct sockaddr*)&servaddr,sizeof(servaddr))`.
6. Receive time request from client using `recvfrom(s,buffer,1024,0,(struct sockaddr*)&cliaddr,&t)`.
7. Initialize `ct=time(NULL)` and Prints the current date and time by calling `ctime(&ct)`.
8. Child process is created. Parent process stops listening for new connections. Child will continue to accept TIME requests from other clients, since it is a concurrent server. The main (parent) process now handles the connected client.
9. After clearing the buffer memory area using `memset()` function, TIME request is received from client using `recvfrom(s,buffer,1024,0,(struct sockaddr*)&cliaddr,&t)`.
10. Prints the formatted string TIME to buffer.
11. Sends back UPDATED CURRENT TIME to client using `sendto(s,buffer,sizeof(buffer),0,(struct sockaddr*)&cliaddr,sizeof(cliaddr))`.
12. Close the socket using `close(int sockfd)` function.

### Algorithm – UDP CLIENT

1. Create a socket for UDP using the function call `socket(AF_INET, SOCK_DGRAM, 0)`.
2. Use `bzero()` function to place null bytes of memory area pointed to by local.
   ```
   bzero((char *)&local,sizeof(local));
   ```
3. Initialize the structure `sockaddr_in` members of `sin_family`, `sin_addr`, `sin_port`.
4. Bind the socket to its port using `bind(s,(struct sockaddr *)&local,sizeof(local))`.
5. Use `bzero()` function to place null bytes of memory area pointed to by servaddr.
   ```
   bzero((char *)&servaddr,sizeof(local));
   ```
6. Client sends TIME request to server using `sendto(s,buffer,sizeof(buffer),0,(struct sockaddr*)&servaddr,sizeof(servaddr))`.
7. Client receives TIME response from server using `recvfrom()` function.
   ```
   recvfrom(s,buffer,1024,0,(struct sockaddr *)&servaddr,&t)
   ```
8. Prints the received message in the client’s terminal.

## OUTPUT

### Server

![08 - Concurrent Time - Server](https://github.com/blackpeps/networklab2024/assets/126700907/4d8e119a-44e2-4e36-ad02-6b2b08d4a042)

### Client

![08 - Concurrent Time - Client](https://github.com/blackpeps/networklab2024/assets/126700907/0e7962f6-8b91-44d0-93ef-bf86eaaab0bb)
