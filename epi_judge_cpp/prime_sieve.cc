#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
    int size = std::floor(0.5*(n-3)) + 1;
    vector<bool> is_prime(size, true);
    vector<int> result;
    
    if (n >= 2)
        result.emplace_back(2);
    for (long i = 0; i < size; ++i) {
        if (is_prime[i]) {
            const long p = 2*i + 3;
            result.emplace_back(p);
            for (long j = p*p; j <= n; j += 2*p) {
                const long x = (j-3)/2;
                is_prime[x] = false;
            }
//            for (long j = 2*i*i + 6*i + 3; j < size; j += p) {
//                is_prime[j] = false;
//            }
        }
    }
    
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "prime_sieve.cc", "prime_sieve.tsv",
                         &GeneratePrimes, DefaultComparator{}, param_names);
}
