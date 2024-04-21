# 09 - Link State Routing - Dijkstra's Algorithm Implementation

## About the Program

This program implements Dijkstra's algorithm to find the shortest paths from a source node to all other nodes in a weighted graph. It generates routing tables for each node, showing the cost to reach each destination node and the next hop.

## Program Description

The program reads the number of nodes in the graph, the cost matrix representing the edges between nodes, and the source node from the user. It then applies Dijkstra's algorithm to find the shortest paths and generates routing tables for each node.

## Function: `shortest_path`

The function `shortest_path` takes the following parameters:
- `n`: Number of nodes in the graph.
- `cost`: Cost matrix representing the weighted edges between nodes.
- `src`: Source node from which to calculate the shortest paths.

## Algorithm

1. Initialize distance array `dist`, visited array `visited`, and last array `last`.
2. Initialize `dist[src]` to 0 and all other elements of `dist` to a large value (infinity).
3. Iterate `n - 1` times:
   a. Find the vertex `u` with the minimum distance value among the vertices not yet visited.
   b. Mark `u` as visited.
   c. Update the distance values of the vertices adjacent to `u`.
   d. Update the last array to store the next hop for each destination.
4. Generate routing tables for each node, showing the destination, cost, and next hop.

## Input Format

- Number of nodes in the graph.
- Cost matrix representing the weighted edges between nodes.
- Source node.

## Output

The program outputs the following:
- Routing table for each node, showing the destination, cost, and next hop.

## Sample Input/Output

*Sample Input:*

```
Enter the Number of Nodes: 4
Enter the cost between Nodes:
Cost from 1->2: 2
Cost from 1->3: 5
Cost from 1->4: 4
Cost from 2->1: 2
Cost from 2->3: 2
Cost from 2->4: 1
Cost from 3->1: 5
Cost from 3->2: 2
Cost from 3->4: 1
Cost from 4->1: 4
Cost from 4->2: 1
Cost from 4->3: 1
Enter the source Node: 1
```

*Sample Output:*

```
Routing Table of Node 1
Destination    Cost    Next Hop
  1            -        -
  2            2        -
  3            5        -
  4            4        -

After Applying Dijkstra's Algorithm

Routing Table of Node 1
Destination    Cost    Next Hop
  1            -        -
  2            2        1
  3            4        2
  4            3        4

Routing Table of Node 2
Destination    Cost    Next Hop
  1            2        1
  2            -        -
  3            2        -
  4            1        4

Routing Table of Node 3
Destination    Cost    Next Hop
  1            5        2
  2            2        1
  3            -        -
  4            1        4

Routing Table of Node 4
Destination    Cost    Next Hop
  1            4        2
  2            1        4
  3            1        4
  4            -        -
```

![Screenshot from 2024-04-21 20-07-57](https://github.com/blackpeps/networklab2024/assets/126700907/94cf049e-9f60-4957-8af4-c5ea1b4b8156)
