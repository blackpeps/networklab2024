# 07 - Leaky Bucket

## About the program

This program simulates the Token Bucket algorithm, which is a traffic policing mechanism used in networking. It regulates the rate at which packets are transmitted by a network device.

### Program Description

The program takes inputs such as the bucket size, outgoing rate, and number of inputs. It then simulates incoming packets and determines whether they are dropped or accepted based on the current state of the bucket buffer.

## Algorithm

The Token Bucket algorithm operates as follows:

1. Initialize the bucket buffer size to 0.
2. Read inputs for bucket size, outgoing rate, and the number of inputs.
3. For each incoming packet:
   - Check if the packet size exceeds the available space in the bucket buffer.
   - If the packet can be accommodated, add its size to the bucket buffer.
   - If the packet cannot be accommodated, drop it and display the number of packets dropped.
   - Subtract the outgoing rate from the bucket buffer to simulate packet transmission.
4. Repeat until all inputs are processed.

## Input Format

The program expects the following inputs:

- Bucket size: The maximum capacity of the bucket buffer.
- Outgoing rate: The rate at which packets are transmitted from the bucket buffer.
- Number of inputs: The total number of packets to simulate.

## Output

The program outputs the following information:

- Incoming packet size: Size of each incoming packet.
- Bucket buffer size: Current size of the bucket buffer.
- Packets dropped: Number of packets dropped due to buffer overflow.
- Packets left in buffer: Number of packets remaining in the buffer after outgoing transmission.

## Sample Input/Output

*Sample Input:*

```
Enter bucket size, outgoing rate and no of inputs: 20 5 3
```

*Sample Output:*

```
Enter the incoming packet size: 10
Incoming packet size 10
Bucket buffer size 10 out of 20
After outgoing 5 packets left out of 20 in buffer
```

```
Enter the incoming packet size: 15
Incoming packet size 15
Dropped 5 no of packets
Bucket buffer size 20 out of 20
After outgoing 15 packets left out of 20 in buffer
```

```
Enter the incoming packet size: 8
Incoming packet size 8
Bucket buffer size 3 out of 20
After outgoing -2 packets left out of 20 in buffer
```
```
*Sample Output:*

```
Enter the incoming packet size: 10
Incoming packet size 10
Bucket buffer size 10 out of 20
After outgoing 5 packets left out of 20 in buffer
```

```
Enter the incoming packet size: 15
Incoming packet size 15
Dropped 5 no of packets
Bucket buffer size 20 out of 20
After outgoing 15 packets left out of 20 in buffer
```

```
Enter the incoming packet size: 8
Incoming packet size 8
Bucket buffer size 3 out of 20
After outgoing -2 packets left out of 20 in buffer
```
