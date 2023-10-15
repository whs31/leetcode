#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

auto maxProfit(vector<int>& prices) -> int
{
  int min_price = numeric_limits<int>::max();
  int ret = 0;
  for(const auto& price : prices)
  {
    min_price = min(price, min_price);
    ret = max(price - min_price, ret);
  }
  return ret;
}