#include <print>
#include <vector>
std::vector<int> dailyTemperature(std::vector<int> &temperature) {
  std::vector<int> result(temperature.size(), 0);
  std::vector<std::pair<int, int>> stack;

  // temp[30,38,30,36,35,40,28]
  //
  // stack[{38,1}, {30,2}]
  //
  // result[1, 0, 0, 0, 0, 0, 0]
  // i represents the day
  for (auto i{0uz}; i < temperature.size(); ++i) {
    if (stack.empty()) {
      stack.push_back(std::pair(temperature[i], i));
    } else if (temperature[i] > stack.back().first) {
      while (!stack.empty() && temperature[i] > stack.back().first) {
        result[stack.back().second] = (i - stack.back().second);
        stack.pop_back();
      }
    } else {
      stack.push_back(std::pair(temperature[i], i));
    }
  }

  return result;
}

int main() {

  std::vector<int> temp{30, 38, 30, 36, 35, 40, 28};
  std::print("Result array {}", dailyTemperature(temp));

  return 0;
}
