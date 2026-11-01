# Advance-Algorithms

A collection of fundamental and advanced algorithms implemented in **C++**, focused on **graph algorithms** and **dynamic programming**. It is intended as a learning resource for understanding algorithm design, implementation, and problem-solving techniques.

## Covered Algorithms

### 1. Shortest Path

| Algorithm | Folder | Description |
| :--- | :--- | :--- |
| Dijkstra's Algorithm | `Dijkstra and BellmanFord` | Shortest paths from a source in graphs with non-negative edge weights. |
| Bellman-Ford Algorithm | `Dijkstra and BellmanFord` | Single-source shortest paths; supports negative weights and detects negative cycles. |
| Floyd-Warshall Algorithm | `Flyod Warshell` | All-pairs shortest paths using dynamic programming. |
| Johnson's Algorithm | `Johnsons` | All-pairs shortest paths on sparse graphs using Bellman-Ford reweighting and Dijkstra. |

### 2. Minimum Spanning Tree

| Algorithm | Folder | Description |
| :--- | :--- | :--- |
| Kruskal's Algorithm | `Kruskals` | Sorts edges by weight and adds those that form no cycle, using a Disjoint Set Union (DSU). |
| Prim's Algorithm | `Prims MST` | Grows the tree by repeatedly adding the minimum-weight edge to a new vertex. |

### 3. Dynamic Programming (`Dynamic Programming/`)

| Problem | File | Description |
| :--- | :--- | :--- |
| Climbing Stairs (1 or 2 steps) | `climbing2stairs.cpp` | Counts ways to reach the top with 1 or 2 steps per move. |
| Climbing Stairs (1, 2, or 3 steps) | `climbing3stairs.cpp` | Extends the problem to moves of 1, 2, or 3 steps. |
| Coin Change | `coinchange.cpp` | Coin-denomination problem (variant defined by the implementation). |
| Fibonacci | `fibonacci_dp.cpp` | Computes Fibonacci numbers by reusing previous values. |
| Longest Common Subsequence | `lcs.cpp` | Finds the longest subsequence shared by two sequences. |
| Optimal Binary Search Tree | `obst.cpp` | Builds a BST with minimum expected search cost. |
| Rod Cutting | `rodcutting.cpp` | Cuts a rod to maximize total revenue. |

## Complexity Summary

`V` = vertices, `E` = edges.

| Algorithm | Time Complexity |
| :--- | :--- |
| Dijkstra (binary heap) | `O((V + E) log V)` |
| Bellman-Ford | `O(V · E)` |
| Floyd-Warshall | `O(V³)` |
| Johnson's | `O(V · E log V)` |
| Kruskal's | `O(E log E)` |
| Prim's (binary heap) | `O(E log V)` |
| Fibonacci / Climbing Stairs | `O(n)` |
| Coin Change | `O(n · amount)` |
| LCS | `O(m · n)` |
| Rod Cutting | `O(n²)` |
| OBST | `O(n³)` |

## Getting Started

**Prerequisites:** a C++ compiler such as G++, Clang, or MSVC.

```bash
# Clone the repository
git clone https://github.com/Dibbo008/Advance-Algorithms.git
cd Advance-Algorithms

# Compile (example: LCS)
g++ "Dynamic Programming/lcs.cpp" -o lcs

# Run
./lcs        # Linux / macOS
lcs.exe      # Windows
```

To run a different algorithm, replace the source path and output name.

## Future Improvements

- [ ] Add more graph algorithms
- [ ] Add greedy, divide-and-conquer, and backtracking algorithms
- [ ] Expand the dynamic programming collection
- [ ] Add sample input/output test cases

## Contributing

1. Fork the repository
2. Create a branch (`git checkout -b feature/new-algorithm`)
3. Commit your changes (`git commit -m "Add new algorithm"`)
4. Push the branch (`git push origin feature/new-algorithm`)
5. Open a Pull Request

## Author

**Dibbo Adhikary** · [@Dibbo008](https://github.com/Dibbo008)
