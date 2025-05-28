// Full Name: Ethan E. Lopez
// Student ID: 2425516 
// Chapman Email: etlopez@chapman.edu
// Course Number And Section: CPSC-350-03
// Assignment Or Exercise Number: PA6: Kruskal's

#include <iostream> // includes input and output functions
#include <string> // includes std::string
#include "Kruskals.h" // includes kruskals class
#include "WGraph.h" // includes weighted graph class

using std::cout; // shortens output to cout
using std::endl; // shortens newline to endl

int main(int argc, char* argv[]) { // main method
// takes in a txt file and processes its contents

    cout << endl; // newline for neatness

    Kruskals mst; // kruskal's algorithm analysis object created

    try { // try the following program
        mst.runAlgorithm(argv[1]); // prints an mst from the matrix read in the txt
    }
    catch (const std::exception& e) { // if something goes wrong
        std::cerr << "Error loading file... " << e.what() << endl;
        // print an error occurred and communicate what happened
        return 1; // end the program
    }

    cout << endl; // newline for neatness

    return 0; // ends the program when success

}