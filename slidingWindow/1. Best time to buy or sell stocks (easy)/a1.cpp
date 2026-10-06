#include <vector>

// [7,1,5,3,6,4]
int maxProfit(std::vector<int> &prices) {
  int maxProfit{};
  int start{}, next{1};

  if (prices.empty()) {
    return 0;
  }

  while (start < prices.size() - 1) {
    int diff{prices[next] - prices[start]};
    if (prices[start] <= diff) {
      ++next;
      maxProfit = std::max(maxProfit, diff);
    } else if (prices[start] > diff) {
      start = next;
      next = start + 1;
    }
  }

  return maxProfit;
}
