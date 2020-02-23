#include <algorithm>
#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
bool CanReachEnd(const vector<int>& max_advance_steps) {
    const auto n = max_advance_steps.size();
//    vector<pair<bool, bool>> result(n, std::make_pair(false, false));
//    result[n-1].first = result[n-1].second = true;
//
//    auto helper = [&](int i) -> void
//    {
//        if (result[i].first)
//            return result[i].second;
//
//        if (i + max_advance_steps[i] >= n - 1)
//        {
//            result[i].first = result[i].second = true;
//            return;
//        }
//
//        for (int j = i+1; j < n && j <= i+max_advance_steps[i]; ++j)
//        {
//            if (auto res = helper(j))
//            {
//                result[i].first = result[i].second = true;
//                return;
//            }
//        }
//
//        result[i].first = true;
//    };
//    helper(0);
    int furthest_reach = max_advance_steps[0];
    for (auto i = 1; i <= furthest_reach && i < n; ++i) {
        furthest_reach = std::max(furthest_reach, i + max_advance_steps[i]);
    }

    return (furthest_reach >= n-1);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"max_advance_steps"};
  return GenericTestMain(args, "advance_by_offsets.cc",
                         "advance_by_offsets.tsv", &CanReachEnd,
                         DefaultComparator{}, param_names);
}
