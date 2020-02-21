#include <algorithm>
#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
using std::reverse;
vector<int> Multiply(vector<int> num1, vector<int> num2) {
  // TODO - you fill in here.
    bool is_negative = false;
    vector<int> result(num1.size() + num2.size(), 0);

    if (num1.front() < 0)
    {
        is_negative = !is_negative;
        num1.front() *= -1;
    }
    if (num2.front() < 0)
    {
        is_negative = !is_negative;
        num2.front() *= -1;
    }

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for (auto i = 0; i < num1.size(); ++i) {
        for (auto j = 0; j < num2.size(); ++j) {
            result[i+j] += num1[i]*num2[j];
            result[i+j+1] += result[i+j]/10;
            result[i+j] %= 10;
        }
    }
    
    auto i = num1.size() + num2.size() - 1;
    while (result[i] == 0 && i > 0) {
        --i;
    }
    if (result[i] != 0 && is_negative)
        result[i] *= -1;
    
    auto final_result = vector<int>(result.begin(), result.begin() + i + 1);
    reverse(final_result.begin(), final_result.end());

    return final_result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num1", "num2"};
  return GenericTestMain(args, "int_as_array_multiply.cc",
                         "int_as_array_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
