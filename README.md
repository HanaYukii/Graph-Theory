# Graph Theory Course Assignments -- NCTU

Solutions to programming assignments from the Graph Theory course at National Chiao Tung University (NCTU). All solutions are written in C++.

## Assignments

| Homework | Problem | Topics / Algorithms |
|----------|---------|---------------------|
| HW0 | HW0-1 | Basic I/O |
| HW0 | HW0-2 | Frequency counting (mode of a sequence) |
| HW0 | HW0-3 | Adjacency-matrix score computation (tournament graphs) |
| HW1 | HW1-1 | Bipartite graph checking (BFS / 2-coloring) |
| HW1 | HW1-2 | Degree-sequence realizability (Erdos--Gallai theorem, BIT) |
| HW1 | HW1-3 | Dynamic tournament scoring with adjacency-matrix updates |
| HW2 | HW2-1 | Tree diameter (DFS-based depth computation) |
| HW2 | HW2-2 | Shortest paths -- Dijkstra's algorithm with priority queue |
| HW2 | HW2-3 | Shortest Hamiltonian path (Floyd--Warshall + bitmask DP, TSP variant) |
| HW3 | HW3-1 | Eulerian path detection (Union-Find, odd-degree check) |
| HW3 | HW3-2 | Minimum spanning tree with uniqueness check (Kruskal's algorithm) |
| HW3 | HW3-3 | Edge-biconnected components / bridges (Tarjan's algorithm) |
| HW4 | HW4-1 | Minimum weighted vertex cover on trees (tree DP) |
| HW4 | HW4-2 | Maximum flow / minimum cut (Dinic's algorithm, bipartite matching) |
| HW4 | HW4-3 | Counting connected subtrees of a tree (tree DP, combinatorics mod prime) |
| HW5 | HW5-1 | Minimum-weight cycle detection (Floyd--Warshall, directed and undirected) |
| HW5 | HW5-2 | Monotone path counting on weighted trees (edge-weight grouping DP) |
| HW5 | HW5-3 | Offline dynamic connectivity (Union-Find with rollback, edge/vertex deletion processed in reverse) |

## Building

Each `.cpp` file is a standalone solution. Compile with any C++17 compatible compiler:

```bash
g++ -std=c++17 -O2 HW1/HW1-1.cpp -o hw1-1
```
