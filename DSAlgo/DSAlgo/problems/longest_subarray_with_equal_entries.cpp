#include "dec.h"

int longest_subarray_with_equal_entries(const vector<int>& arr) {
    if (arr.size() == 0)
        return 0;
    
    auto longest_subarray = 1, first_index = 0;
    
    for (auto i = 1; i <= arr.size(); ++i) {
        if (arr[i] != arr[first_index] || i == arr.size()) {
            longest_subarray = max(longest_subarray, i - first_index);
            first_index = i;
        }
    }
    
    return longest_subarray;
}
