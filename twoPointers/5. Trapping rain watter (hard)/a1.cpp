// Answered using the answer description of (two pointer)
#include <algorithm>
#include <vector>

int trap(std::vector<int> &height) {
  int l{0}, r{static_cast<int>(height.size()) - 1};
  int res{};
  int maxLeft{height[l]}, maxRight{height[r]};

  while (l < r) {
    if (maxLeft < maxRight) {
      ++l;
      maxLeft = std::max(maxLeft, height[l]);
      res += maxLeft - height[l];
    } else {
      --r;
      maxRight = std::max(maxRight, height[r]);
      res += maxRight - height[r];
    }
  }

  return res;
}
