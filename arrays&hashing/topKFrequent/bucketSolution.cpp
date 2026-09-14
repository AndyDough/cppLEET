#include <cstddef>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>

// bucket sort solution
// 1. loop through the given array and note how many times a number shows up
//  - This can be done with an unordered map (Key: num, value: how many
//  times it appears)
// 2. Then sort all the nums into buckets defining how many times they show up
//  - Done with an array max size being the size of given array + 1
// 3. Iterate backwards from greatest to least to find the top K elements
//
// optimization:
// return an empty array if nums is empty

std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
  std::vector<int> answer{};
  if (nums.empty()) {
    return answer;
  }

  std::unordered_map<int, int> count{};
  // adds 1 to the running count of every number it sees
  for (const auto &e : nums) {
    count[e] += 1;
  }

  // Has to be +1 since nums could contain just 1 number being repeated
  // My solution weren't buckets, it didn't account of different numbers
  // appearing the same amount of times geeg
  std::vector<std::vector<int>> buckets(nums.size() + 1);
  for (const auto &e : count) {
    buckets[static_cast<std::size_t>(e.second)].push_back(e.first);
  }

  // for (int i{static_cast<int>(buckets.size()) - 1}; i > 0; --i) {
  //   for (int e : buckets[static_cast<std::size_t>(i)]) {
  //     answer.push_back(e);
  //     if (answer.size() == static_cast<std::size_t>(k)) {
  //       return answer;
  //     }
  //   }
  // }

  for (const auto &element : std::views::reverse(buckets)) {
    for (const auto &inner : element) {
      answer.push_back(inner);
      if (static_cast<int>(answer.size()) == k) {
        return answer;
      }
    }
  }

  return answer;
}

int main() {
  std::vector test1{1, 2};
  int k{2};

  std::vector answer{1, 2};
  std::vector answer2{2, 1};

  if (topKFrequent(test1, k) == answer || topKFrequent(test1, k) == answer2) {
    std::cout << "Test Pass\n";
  } else {
    std::cout << "FAILED\n";
  }

  return 0;
}
