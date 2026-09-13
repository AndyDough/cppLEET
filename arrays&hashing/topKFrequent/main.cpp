#include <queue>
#include <unordered_map>
#include <vector>

std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
  std::unordered_map<int, int> groupedNums{};
  std::priority_queue<std::pair<int, int>> kFrequent{};
  std::vector<int> answer{};

  for (const auto &e : nums) {
    groupedNums[e] += 1;
  }

  // Priority queue contains a pair of numbers(first: key num, second: how many
  // times it appears)
  for (const auto &e : groupedNums) {
    kFrequent.push({e.second, e.first});
  }

  for (auto i{0uz}; i < k; ++i) {
    answer.push_back(kFrequent.top().second);
    kFrequent.pop();
  }

  return answer;
}
