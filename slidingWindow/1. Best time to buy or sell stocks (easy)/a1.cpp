#include <iostream>
#include <vector>

// [7,1,5,3,6,4]
int maxProfit(std::vector<int> &prices) {
  int maxProfit{};
  int start{}, next{1};

  if (prices.empty()) {
    return 0;
  }

  while (next < prices.size()) {
    int diff{prices[next] - prices[start]};
    if (0 <= diff) {
      ++next;
      maxProfit = std::max(maxProfit, diff);
    } else {
      start = next;
      next = start + 1;
    }
  }

  return maxProfit;
}

int main() {
  std::vector prices{7, 1, 5, 3, 6, 4};
  std::cout << maxProfit(prices) << '\n';

  return 0;
}
