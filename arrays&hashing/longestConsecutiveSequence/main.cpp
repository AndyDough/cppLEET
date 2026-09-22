#include <unordered_set>
#include <vector>

// Given a list of nums (The list isn't always in order), but we can't sort
// cause we are aiming for linear time.
//
// approach: throw every element of the num list into a set. Since we only care
// about sequence. We can find a number that is the start of a sequence.
//  - Have a variable that keeps track of the longest sequence
//  - Starting num of a sequence: will not have a number also in the set that is
//  (n - 1)
//  - Iterating through the set, check if the current number has a num that is
//  (n - 1):
//    a) if exist: skip num
//    b) if not exist: current num is a start of a sequence
//      - loop till fail to find (n + 1)
//      - save the longest sequence
//

// num = [2,20,4,10,3,4,5]
// numSet {2, 3, 4, 5, 10, 20}
int longestConsecutive(std::vector<int> &num) {
  int longestSequence{};
  std::unordered_set<int> numSet{};

  // early return if given array is empty
  if (num.empty()) {
    return 0;
  }

  // insert all of our nums into set
  for (const auto &e : num) {
    numSet.insert(e);
  }

  for (const auto &e : numSet) {
    if (numSet.contains(e - 1)) {
      continue;
    }

    int currSequence{1};
    int nextNum{e + 1};
    while (true) {
      if (numSet.contains(nextNum)) {
        ++currSequence;
        ++nextNum;
      } else {
        break;
      }
    }
    if (currSequence > longestSequence) {
      longestSequence = currSequence;
    }
  }

  return longestSequence;
}
