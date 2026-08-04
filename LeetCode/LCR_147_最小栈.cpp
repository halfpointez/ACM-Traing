class MinStack {
 public:
  std::stack<int> s1;  // 数据栈
  std::stack<int> s2;  // 最小栈
  int Min;
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    if (s1.empty()) {
      s1.push(x);
      Min = x;
      s2.push(Min);
    } else {
      Min = min(x, Min);
      s1.push(x);
      s2.push(Min);
    }
  }

  void pop() {
    s1.pop();
    s2.pop();
    if (!s2.empty()) {
      Min = s2.top();
    }
  }

  int top() { return s1.top(); }

  int getMin() { return s2.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */