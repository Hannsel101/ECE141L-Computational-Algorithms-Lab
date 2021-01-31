#pragma once
#include "Base_List.h"
class Int_List :
    public Base_List<int>
{
public:
    Int_List(string inputFile);
    ~Int_List();
    void sum3_brute_force();
    void sum3_bin_search();
protected:
    int binarySearch(int start, int end_itr, int value);
};

