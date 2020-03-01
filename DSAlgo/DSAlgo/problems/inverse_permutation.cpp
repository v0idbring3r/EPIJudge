#include "dec.h"

void inverse_permutation(vector<int>& inp) {
    int n = inp.size();
    for (int i = 0; i < inp.size(); ++i) {
        if (inp[i] >= 0) {
            int a = i;
            int na = inp[i];
            
            do {
                int nna = inp[na];
                inp[na] = a-n;

                a = na;
                na = nna;
            } while (a != i);
        }
    }
    
    std::for_each(inp.begin(), inp.end(), [&](auto& x) { x += n; });
}
