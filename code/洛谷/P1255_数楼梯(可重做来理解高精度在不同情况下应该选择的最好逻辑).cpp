#include <bits/stdc++.h>
using namespace std;

// 大数加法：将两个逆序存储的数字相加（个位在索引0）
vector<int> h_plus(const vector<int>& a, const vector<int>& b) {
  vector<int> sum;
  int carry = 0;
  int i = 0;
  // 遍历两个数的每一位，直到都处理完且无进位
  while (i < a.size() || i < b.size() || carry > 0) {
    int val = carry;
    if (i < a.size()) val += a[i];
    if (i < b.size()) val += b[i];
    carry = val / 10;         // 计算进位
    sum.push_back(val % 10);  // 存储当前位
    i++;
  }
  return sum;
}

int main() {
  int N;
  cin >> N;

  // stair_way[i]存储f(i)的结果，逆序存储（个位在0索引）
  vector<vector<int>> stair_way(N + 1);
  stair_way[1] = {1};  // f(1) = 1
  if (N >= 2) {
    stair_way[2] = {2};  // f(2) = 2
  }

  // 递推计算f(n) = f(n-1) + f(n-2)
  for (int i = 3; i <= N; i++) {
    stair_way[i] = h_plus(stair_way[i - 1], stair_way[i - 2]);
  }
  
  // 逆序输出结果（从最高位到个位）
  const vector<int>& result = stair_way[N];
  for (auto it = result.rbegin(); it != result.rend(); ++it) {
    cout << *it;
  }
  cout << endl;

  return 0;
}