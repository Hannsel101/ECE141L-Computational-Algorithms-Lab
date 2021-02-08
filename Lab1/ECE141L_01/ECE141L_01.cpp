// ECE141L_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Base_List.h"
#include "Int_List.h"

void Demo1();
void Demo2();
void Demo3();

int main()
{
    int demo = 2;

    fstream outFile;
    outFile.open("inputInts2.txt");


    outFile.close();

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
    string inputFile = "inputInts.txt";
    string inputFile2 = "inputInts2.txt";

    Int_List demo2_list(inputFile2);
    demo2_list.write();
    cout << "\n\n";
    demo2_list.read(inputFile2);
    demo2_list.write();
}
//**********************************************************//
void Demo3()
{
    string inputFile = "inputInts.txt";
    string inputFile2 = "inputInts2.txt";

    Int_List demo2_list(inputFile2);
    demo2_list.write();
    cout << "\n\n";
    demo2_list.sum3_brute_force();
    cout << endl << endl;

    demo2_list.sum3_bin_search();

}
