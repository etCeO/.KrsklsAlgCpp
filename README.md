# Kruskal's Algorithm

- A program that accepts an adjacency matrix representation of a weighted graph and computes the cost of its minimum spanning tree, applying a proposed structure based on Kruskal’s algorithm to efficiently select edges and determine an optimal spanning configuration.

## Author Info

- Full Name: Ethan E. Lopez
- Chapman Email: etlopez@chapman.edu

## Source Files
- Main.cpp
- Kruskals.cpp
- Kruskals.h
- WGraph.cpp
- WGraph.h
- graph.txt

## Errors
- N/A

## Instructions For Running
- To compile: g++ *.cpp -o kruskals.exe
- To run: ./kruskals graph.txt

Note: "graph.txt" may be replaced with any file containing the adjancency matrices and contents of an undirected, weighted graph

## Usage

This program is designed to:

1. Read a graph from a file (adjacency matrix representation).
2. Construct a data structure for a weighted graph.
3. Execute Kruskal’s algorithm.
4. Sort the edges by their weights.
5. Add the edges without any cycle.

Output:

- Total cost of Minimum Spanning Tree.

Example Command
- ./kruskals graph.txt

Example Output (conceptual):
- 'graph representation'
- Total MST Cost: 11

## Input Format

The input file must define an undirected weighted graph using an adjacency matrix.

Expected Structure
---
- First line: integer N (number of vertices)
- Next N lines: N x N adjacency matrix

Rules
1. 0 is typically used to represent no edge (except for the diagonal).
2. Positive integers represent edge weights.
3. The matrix is symmetric, reflecting the undirected nature of the graph.
4. Diagonal elements are 0.

Example (graph.txt)
---
4
0 2 5 0
2 0 3 4
5 3 0 1
0 4 1 0

- This is a graph with 4 vertices and weighted edges between them.

## Implementation Details

Core Algorithm: Kruskal’s Algorithm
---
The program is implemented according to the following steps:

1. Edge Extraction

The adjacency matrix is converted to edges, where each edge is represented by (u, v, weight).

2. Sorting Edges

Edges are sorted according to weight in ascending order.

3. MST Construction

Edges are processed from the sorted edge list:

- If the edge connects two different components, it is included in the MST.
- If it does not, it is skipped and the process continues until N-1 edges are included.
