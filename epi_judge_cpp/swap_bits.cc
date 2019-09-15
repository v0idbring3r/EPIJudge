#include "test_framework/generic_test.h"
long long SwapBits(long long x, int i, int j) {
  // TODO - you fill in here.
    long long xi = (x >> i) & 1,xj = (x >> j) & 1;
    x ^= (xi << i) | (xj << j);
    x |= (xi << j) | (xj << i);

    return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "i", "j"};
  return GenericTestMain(args, "swap_bits.cc", "swap_bits.tsv", &SwapBits,
                         DefaultComparator{}, param_names);
}
