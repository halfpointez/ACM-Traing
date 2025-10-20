#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 计算单科的最短时间
int calculateMinTime(const vector<int>& times) {
  int total = 0;
  for (int t : times) total += t;  // 总耗时
  if (total == 0) return 0;
  int maxPossible = total / 2;  // 目标上限（总耗时的一半）

  // dp[j]表示是否能达到总耗时j
  vector<bool> dp(maxPossible + 1, false);
  dp[0] = true;  // 初始化：空子集可达

  for (int t : times) {
    // 01背包：从后往前遍历，避免重复使用同一元素
    for (int j = maxPossible; j >= t; --j) {
      if (dp[j - t]) {
        dp[j] = true;
      }
    }
  }

  // 找到最大的可达j
  int best = 0;
  for (int j = maxPossible; j >= 0; --j) {
    if (dp[j]) {
      best = j;
      break;
    }
  }

  return total - best;  // 单科最短时间
}

int main() {
  int s[4];
  cin >> s[0] >> s[1] >> s[2] >> s[3];

  vector<vector<int>> subjects(4);
  // 读取四科的题目耗时
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < s[i]; ++j) {
      int t;
      cin >> t;
      subjects[i].push_back(t);
    }
  }

  // 计算总最短时间
  int totalTime = 0;
  for (int i = 0; i < 4; ++i) {
    totalTime += calculateMinTime(subjects[i]);
  }

  cout << totalTime << endl;
  return 0;
}