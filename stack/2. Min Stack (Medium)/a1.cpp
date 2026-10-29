#include <vector>

class MinStack {
private:
  std::vector<int> m_array;
  std::vector<int> m_minValues;

public:
  MinStack() {}

  void push(int val) {
    m_array.push_back(val);
    if (m_minValues.empty()) {
      m_minValues.push_back(val);
    } else if (m_minValues.back() < val) {
      m_minValues.push_back(m_minValues.back());
    } else {
     m_minValues.push_back(val);
    }
  }

  void pop() {
    m_array.pop_back();
    m_minValues.pop_back();
  }

  int top() { return m_array.back(); }

  int getMin() { return m_minValues.back(); }
};
