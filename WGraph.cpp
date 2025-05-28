// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA6: Kruskal's

#include <iostream> // includes input and output functions
#include "WGraph.h" // includes header class

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

WGraph::WGraph() {
// default constructor
  size = 0; // assign size to 0 nodes
  adjacents = NULL; // begin with no edges and adjacents
}

WGraph::WGraph(unsigned int sz) {
// overloaded constructor
// takes in a size and builds ideal matrices with it
  size = sz; // size is the parameter
  adjacents = new double*[sz];   // allocate sz * sz adjacency matrix
  for(int i = 0; i < size; i++){
    // for all indices in both matrices
    adjacents[i] = new double[sz]; // assign adjacent indices to arrays
  }
  // start with edges
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
    // for every index in both matrices
      adjacents[i][j] = 0.0;
      // start by assinging them to zero before further analysis
    }
  }
}

WGraph::~WGraph(){
  // default destructor
  // clears memory of adjacency matrix
  for (int i = 0; i < size; i++) {
    // for all arrays in adjacents
    delete[] adjacents[i]; // delete them
  }
  delete[] adjacents; // then delete the array itself
}

// PRIVATE METHODS

double WGraph::getNextMin(double currMin, double** graph) {
// a private double method that returns the next minimum weight in the graph
// currMin is the minimum before and graph is a double matrix
  double nextMin = 1000.0; // start at a high number
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      // for all individual nodes in the graph
      if (graph[i][j] > currMin && graph[i][j] < nextMin) {
      // if the node's value is greater than the current min and less than nextMin's value
        nextMin = graph[i][j]; // label this as the next minimum
      }
    }
  }
  return nextMin; // return the double value after looping through the graph
}

int WGraph::edgeCount() {
// a private int method that counts all edges created so far
  int edges = 0; // set the count of adjacents to 0
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
    // for all nodes in the adjancecy matrix
      if (areAdjacent(i, j)) {
      // if nodes are adjacent
        ++edges; // add this to the edge count
      }
    }
  }
  edges /= 2; // the number of complete edges in the node is the number of adjacents divided by 2
  return edges; // return the number of edges in adjacency matrix
}

int WGraph::nodeCount() {
// a private int method for counting 
  int nodes = 0; // set the count of nodes to 0
  for (int i = 0; i < size; i++) {
  // for all rows in the matrix
    int conn = 0; // begin # of connections at 0
    for (int j = 0; j < size; j++) {
    // for all columns in the matrix
      if (areAdjacent(i, j)) {
      // if there is a connection
        ++conn; // increment count
      }
    }
    if (conn > 0) {
    // if the number of connections in a row is greater than 0
    // this means the node is part of the graph
      ++nodes; // add this to the node count
    }
  }
  return nodes; // return the total number of nodes after
}

void WGraph::addEdge(VertexID i, VertexID j, double w) {
// a private void method that adds an edge of weight w between adjacent nodes i and j
  if (i < size && j < size) {
    // if i and j are valid indices
    adjacents[i][j] = w;
    adjacents[j][i] = w;
    // assign weighted edge w between them in both ways since the graph is undirected
  }
}

bool WGraph::areAdjacent(VertexID i, VertexID j) {
// a private void method evaluating if nodes i and j are adjacent to each other in the graph
  return (adjacents[i][j] > 0.0);
  // if the weighted edge between i and j is greater than zero, return true
  // else the nodes are not adjacent and return false
}

bool WGraph::areConnected(VertexID i, VertexID j) {
// a private bool method that confirms whether or not these nodes have already been added to the mst
  bool iConn = false; // a bool for node i's connection
  bool jConn = false; // a bool for node j's connection
  for (int x = 0; x < size; x++) { // for the dimensions of the graph
    if (adjacents[i][x] > 0.0) {
    // if i to x has a weight greater than 0
      iConn = true; // it's connected
    }
    if (adjacents[j][x] > 0.0) {
    // if j to x has a weight greater than 0
      jConn = true; // then it's also connected
    }
  }
  if (iConn && jConn) {
  // if both i and j are connected to the graph
    return true; // return true
  }
  return false; // otherwise they are not
}

bool WGraph::isFullGraph() {
// a private bool method that evaluates if the graph has islands or not
  return (edgeCount() == nodeCount() - 1);
  // if the number of edges is not the same as one less than the nodes, this is not a complete graph
}

// PUBLIC METHOD

void WGraph::computeMST(double** graph) {
// a public void method that computes a minimum spanning tree using Kruskal's algorithm and prints the results in the terminal
  bool completeMST = false; // assign complete mst to false
  double min = 0.0; // assign current minimum value as 0.0 for the adjacency matrix
  while (!completeMST) {
  // while the mst is not complete
    if (edgeCount() == size - 1) {
    // if the number of edges is equal to the total number of nodes minus 1
      completeMST = true; // this is how you know your mst is complete
    }
    else {
    // if your mst is not complete
      min = getNextMin(min, graph);
      // get the next minimum value in the graph
      // starting at 0, if there's a next smallest weight of 1, this would be 1
      // starting at 1, if there's a next smallest weight of 3, this would be 3
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
        // for all nodes in the graph
          if (graph[i][j] == min) {
          // if a graph's node weight is equal to the next minimum
            if (!areConnected(i, j) || !isFullGraph()) {
            // if the two nodes are not already connected or the graph is not full (has islands)
              addEdge(i, j, min); // add this weight into the adjacents
            }
          }
        }
      }
    }
  }
  // now that you have an mst
  double cost = 0.0; // begin calculating the cost
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
    // for all weights in the adjacency matrix
      cost += adjacents[i][j]; // add these weights to the cost
    }
  }
  cost /= 2; // this cost divided by 2 is your actual cost
  cout << "The MST cost is: " << cost << endl;
  // print Kruskal's MST cost
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << adjacents[i][j] << " ";
      // print all values in the matrix
    }
    cout << endl; // newline for neatness
  }
}