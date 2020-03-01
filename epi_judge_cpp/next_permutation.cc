#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
vector<int> NextPermutation(vector<int> perm) {
    int i = perm.size()-2;
    for (; i >= 0; --i) {
        if (perm[i] < perm[i+1]) {
            for(int j = perm.size()-1; j > i; --j) {
                if (perm[j] > perm[i]) {
                    std::swap(perm[i], perm[j]);
                    break;
                }
            }
            break;
        }
    }
    
    if (i < 0)
        return {};

    std::reverse(perm.begin()+i+1, perm.end());
    return perm;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm"};
  return GenericTestMain(args, "next_permutation.cc", "next_permutation.tsv",
                         &NextPermutation, DefaultComparator{}, param_names);
}
