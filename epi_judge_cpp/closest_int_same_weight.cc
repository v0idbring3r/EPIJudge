#include "test_framework/generic_test.h"
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
  // TODO - you fill in here.
    for (int i = 0; i < 63; ++i) {
        if (((x >> i) ^ (x >> (i+1))) & 1) {
            x ^= (1ULL << i) | (1ULL << (i+1));
            break;
        }
    }

    return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc",
                         "closest_int_same_weight.tsv", &ClosestIntSameBitCount,
                         DefaultComparator{}, param_names);
}
