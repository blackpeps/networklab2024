# 10 - IMPLEMENTATION OF FTP CLIENT AND SERVER

## Aim

Program to implement a simple FTP server for file transfer to the server.

## Algorithm

### Steps involved in writing the Server Process:

1. Create a socket using `socket()` system call with address family `AF_INET`, type `SOCK_STREAM`, and default protocol.
2. Bind the server’s address and port using `bind()` system call.
3. Wait for the client connection to complete accepting connections using `accept()` system call.
4. Receive the client's file using `recv()` system call.
5. Use `fgets(char *str, int n, FILE *stream)` function to read a line of text from the specified stream and store it into the string pointed to by `str`. It stops when either `(n-1)` characters are read, or when the end-of-file is reached.
6. On successful execution i.e. when the file pointer reaches the end of the file, a file transfer “completed” message is sent by the server to the accepted client connection using `send()` with the `newsd` socket file descriptor.

### Steps involved in writing the Client Process:

1. Create a socket system call with address family `AF_INET`, type `SOCK_STREAM`, and default protocol.
2. Enter the client port ID.
3. Fill in the internet socket address structure (with server information).
4. Connect to the server address using `connect()` system call.
5. Read the existing and new file name from the user.
6. Send the existing file to the server using `send()` system call.
7. Receive feedback from the server “Completed”, regarding file transfer completion.
8. Write “File is transferred” to the standard output screen.
9. Close the socket connection and file pointer.

## OUTPUT

### Server.c

![Screenshot from 2024-04-16 01-04-22](https://github.com/blackpeps/networklab2024/assets/126700907/a4b755ff-34cb-480a-a77d-316fe68f0b91)

### Client.c

![Screenshot from 2024-04-16 01-04-29](https://github.com/blackpeps/networklab2024/assets/126700907/b7be56dd-e5b6-4e12-b184-108006495743)
