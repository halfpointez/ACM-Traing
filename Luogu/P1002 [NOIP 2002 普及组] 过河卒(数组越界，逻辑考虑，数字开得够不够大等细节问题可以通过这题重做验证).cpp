#include <bits/stdc++.h>
using namespace std;
long long dp[21][21] = {0};    // 棋盘最大20x20，用long long防溢出
bool block[21][21] = {false};  // 标记障碍物

int main() {
  int n, m, hx, hy;
  cin >> n >> m >> hx >> hy;

  // 马的位置及8个控制点标记为障碍物
  block[hx][hy] = true;
  int dirs[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                    {-2, 1},  {-1, 2},  {1, 2},  {2, 1}};
  for (auto& d : dirs) {
    int x = hx + d[0];
    int y = hy + d[1];
    if (x >= 0 && x <= n && y >= 0 && y <= m) {  // 确保在棋盘范围内
      block[x][y] = true;
    }
  }

  // 起点或终点被阻挡，直接返回0
  if (block[0][0] || block[n][m]) {
    cout << 0 << endl;
    return 0;
  }

  // 初始化起点
  dp[0][0] = 1;

  // 初始化第一行（只能从左边来）
  for (int j = 1; j <= m; ++j) {
    if (!block[0][j]) {
      dp[0][j] = dp[0][j - 1];
    }
  }

  // 初始化第一列（只能从上面来）
  for (int i = 1; i <= n; ++i) {
    if (!block[i][0]) {
      dp[i][0] = dp[i - 1][0];
    }
  }

  // 动态规划计算路径数
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!block[i][j]) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
  }

  cout << dp[n][m] << endl;
  return 0;
}