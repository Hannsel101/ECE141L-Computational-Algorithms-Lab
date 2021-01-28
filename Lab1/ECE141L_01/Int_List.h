#pragma once
#include "Base_List.h"
class Int_List :
    public Base_List<int>
{
public:
    void sum3_brute_force();
    void sum3_bin_search();
};

