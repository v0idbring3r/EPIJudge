#include "dec.h"

int minimum_steps_to_reach_end_of_array(const vector<int>& arr, int n)
{
    if (n < 0 || n >= arr.size())
        return -1;
    
    auto furthest_reach = arr[0], jumps = 1, steps = arr[0];
    
    for (auto i = 1; i <= furthest_reach && i <= n; ++i) {
        if (i == n)
            return jumps;
        
        furthest_reach = max(furthest_reach, i + arr[i]);
        --steps;
        
        if (steps == 0) {
            ++jumps;
            steps = furthest_reach - i;
        }
    }
    return -1;
}
