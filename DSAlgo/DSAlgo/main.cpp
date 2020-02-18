//
//  main.cpp
//  DSAlgo
//
//  Created by Angad Pal Singh on 16/02/20.
//  Copyright © 2020 abc. All rights reserved.
//
#include "dec.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> a = {4, 5, 2, 1, 7, 11, 3, 0};
    quicksort(a);
    
    for (auto& i : a)
        std::cout<<i<<' ';
    std::cout<<std::endl;

    return 0;
}
