// HCamacho_ECE141_HW4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Edge.h"
#include "UnionFind.h"
#include "EdgeWeightedGraph.h"
#include "KruskalMST.h"

void Question1();
void Question2();

int main()
{
    Question1();
    cout << "\n\n\n";
    Question2();
}
//====================================================
//====================================================
//====================================================
void Question1()
{
    int vertices = 7;
    UnionFind UF(7);

    cout << "Created Union Find with 7 vertices...\n\n";
    cout << "Connected(0,3)? ";
    if (UF.connected(0, 3))
        cout << "True\n";
    else
        cout << "False\n";


    cout << "\nUnion(0,3)...\nUnion(4,6)...\nConnected(0,3)? ";
    UF.Union(0, 3);
    UF.Union(4, 6);

    if (UF.connected(0, 3))
        cout << "True\n";
    else
        cout << "False\n";
    
    cout << "Connected(4,3)? ";
    if (UF.connected(4, 3))
        cout << "True\n";
    else
        cout << "False\n";

    
    cout << "\nUnion(6,0)...\nConnected(4,3)? ";
    UF.Union(6, 0);
    
    if (UF.connected(4, 3))
        cout << "True\n";
    else 
        cout << "False\n";
}
//====================================================
void Question2()
{
    EdgeWeightedGraph G(5);

    //Edge(int v, int w, double weight)
    Edge* e = new Edge(4, 5, 0.35);
    G.addEdge(e);

    e = new Edge(1, 5, 0.32);
    G.addEdge(e);
    e = new Edge(0, 2, 0.26);
    G.addEdge(e);
    e = new Edge(0, 4, 0.38);
    G.addEdge(e);
    e = new Edge(1, 3, 0.29);
    G.addEdge(e);

    KruskalMST mst(G);
}