# Networking Lab - CSL332

## Table of Contents

| No. | Experiment Name                    | Date         | More Details   | Download PDF                                                                                        |
| --- | ---                                | ---          | ---            | ---                                                                                                 |
| 01. | Network Config Files and Commands  | 30-01-2024   | [Go](/EXP01/)  | N/A                                                                                                 |
| 02. | System Calls in OS                 | 30-01-2024   | [Go](/EXP02/)  | N/A                                                                                                 |
| 03. | TCP (using Socket Programming)     | 06-02-2024   | [Go](/EXP03/)  | [CSL332 - EXP03.pdf](https://github.com/blackpeps/networklab2024/files/14379167/CSL332.-.EXP03.pdf) |
|     | TCP - String Reverse               | 04-03-2024   | [Go](/EXP03A/) | N/A |
| 04. | UDP (using Socket Programming)     | 26-02-2024   | [Go](/EXP04/)  | [CSL332 - EXP04.pdf](https://github.com/blackpeps/networklab2024/files/14379588/CSL332.-.EXP04.pdf) |
|     | UDP - Matrix Multiplication        | 04-03-2024   | [Go](/EXP04A/) | N/A |
| 05. | Multi-User Chat using TCP          | 04-03-2024   | [Go](/EXP05/)  | [CSL332 - EXP05.pdf](https://github.com/blackpeps/networklab2024/files/14469951/CSL332.-.EXP05.pdf) |
| 06. | Stop and Wait                      | 26-03-2024   | [Go](/EXP06/)  | |
| 07. | Leaky Bucket                       | 26-03-2024   | [Go](/EXP07/)  | |

## Syllabus

> *Mandatory (Note: At least one program from each topic in the syllabus should be completed in the Lab)

1. Getting started with the basics of network configuration files and networking commands in Linux.*
2. To familiarize and understand the use and functioning of system calls used for network programming in Linux.*
3. Implement client-server communication using socket programming and TCP as transport layer protocol*
4. Implement client-server communication using socket programming and UDP as transport layer protocol*
5. Simulate sliding window flow control protocols.* (Stop and Wait, Go back N, Selective Repeat ARQ protocols)
6. Implement and simulate the algorithm for Distance Vector Routing protocol or Link State Routing protocol.*
7. Implement a Simple Mail Transfer Protocol.
8. Implement File Transfer Protocol.*
9. Implement congestion control using a leaky bucket algorithm.*
10. Understanding the Wireshark tool.*
11. Design and configure a network with multiple subnets with wired and wireless LANs using required network devices. Configure commonly used services in the network.*
12. Study of NS2 simulator*

## Practice Questions

1. `Questions`
- View the configuration, including the addresses of your computer's network interfaces.
- Test the network connectivity between your computer and several other computers.
- View the active TCP connections in the computer after visiting a website.
- Find the hardware/MAC address of another computer in the network using ARP.

2. Write the system calls for creating sockets and transferring data between two nodes.

3. `Questions`
- Implement a multi-user chat server using TCP as a transport layer protocol.
- Implement a simple web proxy server that accepts HTTP requests forwarding to remote servers and returns data to the client using TCP

4. Implement a Concurrent Time Server application using UDP to execute the program at a remote server. A client sends a time request to the server, and the server sends its system time back to the client. The client displays the result.

5. `Questions`
- Implement Stop-and-Wait ARQ flow control protocol.
- Implement Go-Back--N ARQ flow control protocol.
- Implement Selective Repeat ARQ flow control protocol.

6. Implement Distance Vector Routing algorithm or Link State Routing algorithm.

7. Implement a Simple Mail Transfer Protocol.

8. Develop a concurrent file server which will provide the file requested by a client if it exists. If not, the server sends an appropriate message to the client. The server should also send its process ID (PID) to clients for display along with the file or the message.

9. Implement a leaky bucket algorithm for congestion control.

10. `Questions`
- Using Wireshark, Capture packets transferred while browsing a selected website. Investigate the protocols used in each packet, the values of the header fields and the packet size.
- Using Wireshark, observe three-way handshaking connection establishment, three-way handshaking connection termination and Data transfer in client-server communication using TCP.
- Explore at least the following features of Wireshark: filters, Flow graphs (TCP), statistics, and protocol hierarchies.

11. Design and configure a network (wired and wireless LANs) with multiple subnets using required network devices. Configure at least three of the following services in the network- TELNET, SSH, FTP server, Web server, File server, DHCP server and DNS server.

12. `Questions`
- The network consists of a TCP source node (n0) and destination node (n1) over an area size of 500m x 500m. Node (n0) uses Agent/TCP/Reno as the sending TCP agent and FTP traffic source. Node (n1) is the receiver of FTP transfers, and it uses Agent/TCP sink as its TCP agent for the connection establishment. Simulate for 150 seconds and show the TCP window size in two static node scenarios with any dynamic routing protocol. Run the script and analyze the output graph for the given scenario.
- Simulate the transmission of ping messages over a star network topology consisting of ‘n’ nodes and find the number of packets dropped due to congestion using NS2simulator.
- Simulate Link State Protocol or Distance Vector Routing protocol in NS2.
