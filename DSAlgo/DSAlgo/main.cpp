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
    
    vector<int> a = {1, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 7, 7, 7};
    auto x = sorted_array_m_times(a, 1);
    
    cout<<x<<endl;
    for (auto i = 0; i < x; ++i)
        std::cout<<a[i]<<' ';
    std::cout<<std::endl;

    return 0;
}
