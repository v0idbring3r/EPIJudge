#include "dec.h"

int sorted_array_m_times(vector<int>& arr, int m) {
    int count = min(2, m), valid_count;
    int n = arr.size();
    
    if (n <= 1)
        return n;
    
    int first_index = 0, i = 0;
    
    for (int j = 0; j <= n; ++j) {
        if (arr[j] != arr[first_index] || j == n) {
            if (j - first_index >= m) {
                valid_count = count;
            }
            else {
                valid_count = j - first_index;
            }

            for (int k = 1; k <= valid_count; ++k) {
                arr[i++] = arr[first_index];
            }

            first_index = j;
        }
    }
    
    return i;
}
