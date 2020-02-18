#include <algorithm>
#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
vector<int> PlusOne(vector<int> A) {
  // TODO - you fill in here.
//    auto result = vector<int>{};
//    int carry = 1, i = A.size() - 1;
//
//    while (carry > 0 && i >= 0) {
//        result.push_back((A[i]+1)%10);
//        carry = (A[i--]+1)/10;
//    }
//    while (i >= 0) {
//        result.push_back(A[i--]);
//    }
//    if (carry > 0)
//        result.push_back(1);
//    std::reverse(result.begin(), result.end());
//
//    return result;
    auto i = A.size() - 1;
    
    while (i >= 0 && A[i] == 9) {
        A[i--] = 0;
    }
    
    if (i == -1)
        A.insert(A.begin(), 1);
    else
        ++A[i];
    
    return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
