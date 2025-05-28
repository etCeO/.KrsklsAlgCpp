// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA6: Kruskal's

#ifndef WGraph_H // instantiates class once
#define WGraph_H // defines weighted graph class

#include <iostream> // includes input and output functions

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

typedef unsigned int VertexID; // an unsigned int declared to ensure no negative weights are to be added

class WGraph { // class body

    public: // public constructors and methods
        WGraph(); // default constructor
        WGraph(unsigned int sz); // overloaded constructor
        ~WGraph(); // default destructor
        void computeMST(double** graph); // computes the minimum spanning tree of a graph using Kruskal's algorithm

    private: // private variables
        double** adjacents; // an adjacency matrix
        unsigned int size; // nodes in WGraph (fixed)
        double getNextMin(double currMin, double** graph); // method for getting the next minimum number
        int edgeCount(); // counts the number of edges in the adjacency matrix
        int nodeCount(); // counts the number of nodes in the adjacency matrix
        void addEdge(VertexID i, VertexID j, double w); // method for adding edges
        bool areAdjacent(VertexID i, VertexID j); // confirms whether two nodes are adjacent or not
        bool areConnected(VertexID i, VertexID j); // returns whether or not the nodes are already a part of the graph
        bool isFullGraph(); // returns whether or not the graph has islands (no islands is considered a full graph)

};

#endif // end of class definition