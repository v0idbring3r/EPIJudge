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
    
    vector<int> a = {0,3,2,1};
    inverse_permutation(a);
    
//    cout<<x<<endl;
    for (auto i = 0; i < a.size(); ++i)
        std::cout<<a[i]<<' ';
    std::cout<<std::endl;

    return 0;
}
