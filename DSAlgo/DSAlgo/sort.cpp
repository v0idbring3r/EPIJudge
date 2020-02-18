//
//  sort.cpp
//  DSAlgo
//
//  Created by Angad Pal Singh on 16/02/20.
//  Copyright © 2020 abc. All rights reserved.
//

#include "dec.h"

void bubble_sort(vector<int>& v)
{
    const auto n = v.size();
    for(auto i=n-1; i>0; --i)
    {
        for(auto j=0; j<i; ++j)
        {
            if (v[j]>v[j+1])
                std::swap(v[j], v[j+1]);
        }
    }
}

int partition(vector<int>& v, int start, int end)
{
    int pivot_element = v[start];
    int i=start+1;
    
    for(auto j=start+1; j<=end; ++j)
    {
        if (v[j]<pivot_element)
            std::swap(v[i++], v[j]);
    }
    std::swap(v[start], v[i-1]);
    
    return i-1;
}

void quicksort_recursive(vector<int>&v, int start, int end)
{
    if (start<end)
    {
        auto pivot = partition(v, start, end);
        quicksort_recursive(v, start, pivot-1);
        quicksort_recursive(v, pivot+1, end);
    }
}

void quicksort(vector<int>&v)
{
    quicksort_recursive(v, 0, v.size()-1);
}
