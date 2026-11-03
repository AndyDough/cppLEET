#include <algorithm>
#include <print>
#include <stack>
#include <utility>
#include <vector>

int carFleet(int target, std::vector<int> &position, std::vector<int> &speed) {

  if (position.size() <= 1) {
    return 1;
  }

  std::vector<std::pair<int, int>> cars{};

  for (auto i{0uz}; i < position.size(); ++i) {
    cars.push_back(std::pair{position[i], speed[i]});
  }

  std::sort(cars.begin(), cars.end(), std::greater<std::pair<int, int>>());

  int fleetCounter{1};
  double prevTime = ((target - cars[0].first) / cars[0].second);
  for (auto i{1uz}; i < position.size(); ++i) {
    double time{(target - cars[i].first) / cars[i].second};
    if (fleetCounter == 0) {
      prevTime = time;
      ++fleetCounter;
    } else if (time > prevTime) {
      prevTime = time;
      ++fleetCounter;
    }
  }

  return fleetCounter;
}
// target=10
// position=[6,8]
// speed=[3,2]
// cars[{8,2}, {6,3}]
// times{1, }
int main() {
  std::vector<int> position{6, 8};
  std::vector<int> speed{3, 2};

  std::print("expects: 2\n"
             "output: {}\n",
             carFleet(10, position, speed));

  return 0;
}
