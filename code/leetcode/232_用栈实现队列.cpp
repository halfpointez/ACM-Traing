class MyQueue {
 public:
  std::stack<long long> s1;
  std::stack<long long> s2;
  MyQueue() {}

  void push(int x) { s1.push(x); }

  int pop() {
    while (!empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    int temp = s2.top();
    s2.pop();
    while (s2.size() != 0) {
      s1.push(s2.top());
      s2.pop();
    }
    return temp;
  }

  int peek() {
    while (!empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    int temp = s2.top();
    while (s2.size() != 0) {
      s1.push(s2.top());
      s2.pop();
    }
    return temp;
  }

  bool empty() {
    if (s1.size() == 0) {
      return true;
    } else
      return false;
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */