# 02 - System Calls in OS

## 1. ps

The `ps` command displays information about processes running on the system. Running `ps -ef` provides a detailed output including User ID, Process ID, Parent Process ID, CPU utilization, etc.

Example output:

```
UID PID PPID C STIME TTY TIME CMD

root 1 0 0 13:55 ? 00:00:01 /sbin/init
root 2 0 0 13:55 ? 00:00:00 [kthreadd]
root 3 2 0 13:55 ? 00:00:00 [ksoftirqd/0]
root 4 2 0 13:55 ? 00:00:01 [kworker/0:0]
root 5 2 0 13:55 ? 00:00:00 [kworker/0:0H]
root 7 2 0 13:55 ? 00:00:00 [rcu_sched]
root 8 2 0 13:55 ? 00:00:00 [rcuos/0]
```

## 2. fork

The `fork` system call creates a new process. The process that calls `fork` becomes the parent process, and the newly created process is the child process. Both processes have identical copies of data space, heap, and stack but different physical address spaces.

Example:

```c
#include<stdio.h>
void main() {
    int pid;
    pid = fork();
    if(pid > 0) {
        printf("I am parent\n");
    } else {
        printf("I am child\n");
    }
}
```

## 3. exec

The `exec` system call replaces the current process with a new program. Various flavors of `exec` exist, such as `execv`, which takes the pathname of the program to be executed and an array of pointers holding command-line arguments.

## 4. wait

The `wait` system call is used by a parent process to wait for the termination of its child process. It receives information about the termination status of the child process, including the process ID, termination status, and CPU time.

## 5. exit

The `exit` function is called to terminate a process normally.

## 6. open

The `open` system call opens a file specified by its pathname and options provided. It returns a file descriptor that can be used for reading from or writing to the file.

Example:

```c
open(filepathname, O_RDWR);
```

## 7. read

The `read` system call reads data from an open file into a buffer. It returns the number of bytes read, or 0 if the end of the file is encountered.

Example:

```c
read(fd, buffer, sizeof(buffer));
```

## 8. write

The `write` system call writes data to an open file. It returns the number of bytes written.

Example:

```c
write(fd, buffer, sizeof(buffer));
```
