#pragma once
#include <fstream>

#include "unorderedLinkedList.h"
#include "linkedQueueType.h"

class graphType
{
public:
    bool isEmpty() const;
    //Function to determine whether the graph is empty.
    //Postcondition: Returns true if the graph is empty;
    // otherwise, returns false.
    void createGraph();
    //Function to create a graph.
    //Postcondition: The graph is created using the
    // adjacency list representation.
    void clearGraph();
    //Function to clear graph.
    //Postcondition: The memory occupied by each vertex
    // is deallocated.
    void printGraph() const;
    //Function to print graph.
    //Postcondition: The graph is printed.
    void depthFirstTraversal();
    //Function to perform the depth first traversal of
    //the entire graph.
    //Postcondition: The vertices of the graph are printed
    // using depth first traversal algorithm.
    void dftAtVertex(int vertex);
    //Function to perform the depth first traversal of
    //the graph at a node specified by the parameter vertex.
    //Postcondition: Starting at vertex, the vertices are
    // printed using depth first traversal
    // algorithm.
    void breadthFirstTraversal();
    //Function to perform the breadth first traversal of
    //the entire graph.
    //Postcondition: The vertices of the graph are printed
    // using breadth first traversal algorithm.
    graphType(int size = 0);
    //Constructor
    //Postcondition: gSize = 0; maxSize = size; graph is an array of pointers to linked lists.
    ~graphType();
    //Destructor
    //The storage occupied by the vertices is deallocated.
    int parallelEdges();

    void checkCyclic();
protected:
    int maxSize; //maximum number of vertices
    int gSize; //current number of vertices
    unorderedLinkedList<int>* graph; //array to create adjacency lists
private:
    void dft(int v, bool visited[]);
    void dft(int v, int start, bool visited[]);
    int getSize() { return gSize; }
    //Function to perform the depth first traversal of
    //the graph at a node specified by the parameter vertex.
    //This function is used by the public member functions
    //depthFirstTraversal and dftAtVertex.
    //Postcondition: Starting at vertex, the vertices are
    // printed using depth first traversal
    // algorithm.
};


