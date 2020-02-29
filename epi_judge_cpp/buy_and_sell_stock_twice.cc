#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockTwice(const vector<double>& prices) {
    double max_profit = 0, minimum_stock_so_far = std::numeric_limits<double>::max();
    vector<double> max_profits(prices.size(), 0);
    
    for (auto i = 0; i < prices.size(); ++i) {
        max_profit = std::max(max_profit, prices[i] - minimum_stock_so_far);
        minimum_stock_so_far = std::min(minimum_stock_so_far, prices[i]);
        max_profits[i] = max_profit;
    }
    
    auto max_price_so_far = std::numeric_limits<double>::min();
    for (auto i = prices.size() - 1; i >= 0; --i) {
        max_profit = std::max(max_profit, max_profits[i] + max_price_so_far - prices[i]);
        max_price_so_far = std::max(max_price_so_far, prices[i]);
    }
    
    return max_profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock_twice.cc",
                         "buy_and_sell_stock_twice.tsv", &BuyAndSellStockTwice,
                         DefaultComparator{}, param_names);
}
