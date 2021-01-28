// ECE141L_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Base_List.h"

void Demo1();
void Demo2();
void Demo3();
void Demo4();

int main()
{
    int demo = 0;

    if (demo == 0)
    {
        Demo1();
    }
    else if (demo == 1)
    {
        Demo2();
    }
    else if (demo == 2)
    {
        Demo3();
    }
    else if (demo == 3)
    {
        Demo4();
    }
    else
    {
        cout << "INVALID SELECTION!\n";
    }

    return(EXIT_SUCCESS);
}
//**********************************************************//
// Demo Functions Begin
//**********************************************************//
void Demo1()
{
    string inputFile = "Demo1_1.txt";
    string inputFile2 = "Demo1_2.txt";

    Base_List<string> testing(inputFile);

    cout << "Printing contents from first file...\n\n";
    testing.write();
    cout << "------------------------------------\n";

    testing.read(inputFile2);

    cout << endl << "Printing contents from second file...\n\n";
    testing.write();
    cout << "------------------------------------\n";
}
//**********************************************************//
void Demo2()
{

}
//**********************************************************//
void Demo3()
{

}
//**********************************************************//
void Demo4()
{

}
