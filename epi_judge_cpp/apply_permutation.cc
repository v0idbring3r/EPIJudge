#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
void ApplyPermutation(vector<int>* perm_ptr, vector<int>* A_ptr) {
    for (int i = 0; i < A_ptr->size(); ++i) {
        if ((*perm_ptr)[i] >= 0) {
            int a = i;
            int temp = (*A_ptr)[a];
            do {
                int next_a = (*perm_ptr)[a];
                int next_temp = (*A_ptr)[next_a];
                (*A_ptr)[next_a] = temp;
                
                (*perm_ptr)[a] -= perm_ptr->size();
                a = next_a, temp = next_temp;
            } while (a != i);
        }
    }
    
    std::for_each(perm_ptr->begin(), perm_ptr->end(), [&](auto& x) { x += perm_ptr->size(); });
}
vector<int> ApplyPermutationWrapper(vector<int> perm, vector<int> A) {
  ApplyPermutation(&perm, &A);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm", "A"};
  return GenericTestMain(args, "apply_permutation.cc", "apply_permutation.tsv",
                         &ApplyPermutationWrapper, DefaultComparator{},
                         param_names);
}
