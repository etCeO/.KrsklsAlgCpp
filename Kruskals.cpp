// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA6: Kruskal's

#include <iostream> // includes input and output functions
#include <fstream> // includes ifstream and ofstream
#include <string> // includes std::string
#include "Kruskals.h" // includes header file
#include "WGraph.h" // includes WGraph class

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

Kruskals::Kruskals(){}; // default constructor

Kruskals::~Kruskals(){}; // default destructor

void Kruskals::runAlgorithm(std::string inFileName) {
// a public void method that reads a graph from a txt file and prints its mst into the terminal
    std::ifstream inFile(inFileName); // declare file reading

    if (inFile.is_open()) {
    // if the file is open
        int sz; // declare an integer for size in line 1
        inFile >> sz; // read this integer assuming the proper format
        double** graph = new double*[sz];
        // next, declare a graph matrix using the previous size read
        for (int i = 0; i < sz; i++) {
            graph[i] = new double[sz];
            // this graph has dimensons sz * sz
        }
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
            // assuming the graph is written correctly
                inFile >> graph[i][j]; // read each double from the file into the graph
            }
        }
        WGraph grph(sz); // declare a weighted graph using size as the parameter
        grph.computeMST(graph); // compute your graph's mst and print this tree matrix into the terminal
        for (int i = 0; i < sz; i++) {
            delete[] graph[i];
        }
        delete[] graph;
        // clear memory
        inFile.close(); // close file reading
    }
    else {
    // if something went wrong when attempting to open the file, print so
        cout << "Error: Something went wrong when reading from the file" << endl;
    }
}