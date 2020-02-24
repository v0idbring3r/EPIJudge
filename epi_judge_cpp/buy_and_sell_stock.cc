#include <algorithm>
#include <limits>
#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {
    double max_profit = 0, minimum_stock_so_far = std::numeric_limits<double>::max();
    
    for (const auto& i : prices) {
        max_profit = std::max(max_profit, i - minimum_stock_so_far);
        minimum_stock_so_far = std::min(minimum_stock_so_far, i);
    }
    
    return max_profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
