# Concurrent Time Server

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

````

ifconfig
eth0 Link encap:Ethernet HWaddr 54:be:f7:57:e8:c5
inet addr:192.168.90.111 Bcast:192.168.90.255 Mask:255.255.255.0
inet6 addr: fe80::56be:f7ff:fe57:e8c5/64 Scope:Link
UP BROADCAST RUNNING MULTICAST MTU:1500 Metric:1
RX packets:36656 errors:0 dropped:31 overruns:0 frame:0
TX packets:10582 errors:0 dropped:0 overruns:0 carrier:0
collisions:0 txqueuelen:1000
RX bytes:20471919 (20.4 MB) TX bytes:1253533 (1.2 MB)
lo Link encap:Local Loopback
inet addr:127.0.0.1 Mask:255.0.0.0
inet6 addr: ::1/128 Scope:Host
UP LOOPBACK RUNNING MTU:65536 Metric:1
RX packets:765 errors:0 dropped:0 overruns:0 frame:0
TX packets:765 errors:0 dropped:0 overruns:0 carrier:0
collisions:0 txqueuelen:1
RX bytes:71838 (71.8 KB) TX bytes:71838 (71.8 KB)
iit-b@inlabpc-11:~/Desktop/concurrent$ gcc conserver.c -o s
iit-b@inlabpc-11:~/Desktop/concurrent$ ./s 4011
CLIENT 1
gcc conclient.c -o c1
./c1 192.168.90.111 4011
the current time is:Mon Mar 19 11:09:27 2018
CLIENT 1 requests time – Server responds with current time
CLIENT 2
gcc conclient.c -o c2
./c2 192.168.90.111 4011
the current time is:Mon Mar 19 11:13:57 2018
CLIENT 2 requests time – Same Server responds with current time

```
````
