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
    
    vector<int> a = {5, 6, 7, 7, 7, 7, 7, 8, 8, 7, 9, 10, 10, 10, 10, 10, 10, 10, 10};
    auto x = longest_subarray_with_equal_entries(a);
    
    cout<<x<<endl;
//    for (auto i = 0; i < x; ++i)
//        std::cout<<a[i]<<' ';
//    std::cout<<std::endl;

    return 0;
}
