#include <vector>

int maxArea(std::vector<int> &heights) {
  int maxArea{};
  int l{0}, r{static_cast<int>(heights.size()) - 1};

  if (heights.empty()) {
    return 0;
  }

  while (l < r) {
    int area{(r - l) * (std::min(heights[l], heights[r]))};

    if (area > maxArea) {
      maxArea = area;
    }

    if (heights[l] < heights[r]) {
      ++l;
    } else {
      --r;
    }
  }

  return maxArea;
}
