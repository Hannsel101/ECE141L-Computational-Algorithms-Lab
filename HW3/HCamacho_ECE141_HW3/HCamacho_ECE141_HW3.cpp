// HCamacho_ECE141_HW3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdlib>
#include <iostream>
#include "graphType.h"

using namespace std;

int main(int argc, char** argv) {

    graphType graph1(20);
    graph1.createGraph();
    
    graph1.parallelEdges();
    graph1.checkCyclic();
    cout << endl;

    return (EXIT_SUCCESS);
}

