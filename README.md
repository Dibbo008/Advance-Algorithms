# Advance-Algorithms

Welcome to the **Advance-Algorithms** repository[cite: 1]! This repository contains efficient implementations of fundamental and advanced graph algorithms, covering shortest-path finding and Minimum Spanning Trees (MST)[cite: 1].

## Repository Overview

This project serves as a reference collection for classical advanced algorithms[cite: 1]:

| Category | Algorithm | Folder Path |
| :--- | :--- | :--- |
| **Shortest Path** | Dijkstra's Algorithm | `Dijkstra and BellmanFord`[cite: 1] |
| **Shortest Path** | Bellman-Ford Algorithm | `Dijkstra and BellmanFord`[cite: 1] |
| **Shortest Path** | Floyd-Warshall Algorithm | `Flyod Warshell`[cite: 1] |
| **Shortest Path** | Johnson's Algorithm | `Johnsons`[cite: 1] |
| **Minimum Spanning Tree** | Kruskal's Algorithm | `Kruskals`[cite: 1] |
| **Minimum Spanning Tree** | Prim's Algorithm | `Prims MST`[cite: 1] |

---

## Covered Algorithms

### Single-Source & All-Pairs Shortest Path
* **Dijkstra's Algorithm:** Finds the shortest path from a starting node to all other nodes in a weighted graph with non-negative edge weights[cite: 1].
* **Bellman-Ford Algorithm:** Solves the single-source shortest path problem and handles graphs with negative edge weights while detecting negative weight cycles[cite: 1].
* **Floyd-Warshall Algorithm:** An all-pairs shortest path algorithm using dynamic programming[cite: 1].
* **Johnson's Algorithm:** Finds all-pairs shortest paths efficiently on sparse graphs by reweighting edges using Bellman-Ford and running Dijkstra's algorithm for every vertex[cite: 1].

### Minimum Spanning Tree (MST)
* **Kruskal's Algorithm:** A greedy algorithm that finds an MST by sorting edges and using a Disjoint Set Union (DSU) structure[cite: 1].
* **Prim's Algorithm:** A greedy algorithm that grows an MST starting from an arbitrary vertex using priority queues[cite: 1].

---

## Usage & Getting Started

### 1. Clone the Repository
```bash
git clone [https://github.com/Dibbo008/Advance-Algorithms.git](https://github.com/Dibbo008/Advance-Algorithms.git)
cd Advance-Algorithms
