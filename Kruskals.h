// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA6: Kruskal's

#ifndef KRUSKALS_H // instantiates class once
#define KRUSKALS_H // defines Kruskals class

#include <iostream> // includes input and output functions
#include <fstream> // includes ifstream and ofstream
#include <string> // includes std::string
#include "WGraph.h" // includes WGraph class

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

class Kruskals { // class body

    public:
        Kruskals(); // default constructor
        ~Kruskals(); // default destructor
        void runAlgorithm(std::string inFileName); // runs and computes MST of graph using Kruskal's algorithm

};

#endif // end class definition