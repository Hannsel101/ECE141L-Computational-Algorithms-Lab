// ECE141_HCamacho_Exam1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Hash_Table.h"
#include "Graph.h"
#include "edgeWeightedGraph.h"
#include "LazyPrimMST.h"

using namespace std;

void Q1();
float numCollisions(Hash_Table& HT, unsigned int range);
void averCollisions(Hash_Table arr[], unsigned int range);
void clearTables(Hash_Table arr[]);

void Q2();
void testGraph();
void testLazyPrim();

int main()
{
    Q1();
    Q2();
}
//====================================================
//===========Main Functions Start Here================
//====================================================
void Q1()
{
    // Instantiate Hash tables starting at a size of 125 and doubling
    // up to a size of 32000
    Hash_Table H125(125);
    Hash_Table H250(250);
    Hash_Table H500(500);
    Hash_Table H1000(1000);
    Hash_Table H2000(2000);
    Hash_Table H4000(4000);
    Hash_Table H8000(8000);
    Hash_Table H16000(16000);
    Hash_Table H32000(32000);
    Hash_Table Tables[] = { H125, H250, H500, H1000, H2000, H4000, H8000, H16000, H32000 };

    // Create an array to hold the averages
    float aver[9];

    cout << "For the range of 0 -> 1500\n-------------------------";
    averCollisions(Tables, 1500);
    clearTables(Tables);
    cout << "==========================================================\n";

    cout << "For the range of 0 -> 11000\n-------------------------";
    averCollisions(Tables, 11000);
    clearTables(Tables);
    cout << "==========================================================\n";

    cout << "For the range of 0 -> 12000\n-------------------------";
    averCollisions(Tables, 12000);
    clearTables(Tables);
    cout << "==========================================================\n";

    cout << "For the range of 0 -> 14000\n-------------------------";
    averCollisions(Tables, 14000);
    clearTables(Tables);
    cout << "==========================================================\n";
}
//====================================================
void Q2()
{
    bool testing = false;
    if (testing)
    {
        testGraph();
        exit(EXIT_SUCCESS);
    }
    
    testLazyPrim();
}
//====================================================
float numCollisions(Hash_Table& HT, unsigned int range)
{
    int numInserted = 0;
    int numColls = 0;
    size_t randomNum;
    float aver = 0;
    // Begin the random seed
    srand(time(NULL));
    for (int i = 0; i < 10000; ++i)
    {
        randomNum = rand()%range;
        if (HT.exist(randomNum))
        {
            numColls++;
        }
        HT.insert(randomNum);
        ++numInserted;
    }
    float ins = numInserted;
    float cols = numColls;
    aver = ins / cols;
    cout << "\nTable Size: " << HT.getSize() << endl;
    cout << "Aver: " << aver << endl;
    cout << "insertions: " << ins << endl;
    cout << "collisions: " << cols << endl << endl;
    return aver;
}
//====================================================
void clearTables(Hash_Table arr[])
{
    for (int i = 0; i < 9; ++i)
    {
        arr[i].clearTable();
    }
}
//====================================================
void averCollisions(Hash_Table arr[], unsigned int range)
{
    for (int i = 0; i < 9; ++i)
    {
        numCollisions(arr[i], range);
    }
}
//====================================================
void testGraph()
{
    EdgeWeightedGraph graph("graph.txt");
    graph.printEdges();
    cout << endl << "Edges: " << graph.getE() << endl
        << "Vertices: " << graph.getV() << endl;

    Edge e(3, 7, .70);
    cout << "\nAdding edge e(3, 7, 0.70)" << endl;
    graph.addEdge(e);
    graph.printEdges();
}
//====================================================
void testLazyPrim()
{
    EdgeWeightedGraph graph("graph.txt");
    LazyPrimMST lazy(graph);

    queue<Edge> testPrim = lazy.edges();
    float totalWeight = 0;
    while (!testPrim.empty())
    {
        Edge e = testPrim.front();
        testPrim.pop();
        e.toString();
        totalWeight += e.getWeight();
    }
    cout << "\nTotal Weight: " << totalWeight << endl;
}
//====================================================