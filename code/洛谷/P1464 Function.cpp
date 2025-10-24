#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f[21][21][21] = {0};  // 用于记忆化存储计算结果

// 带记忆化的递归函数，计算并缓存结果
ll w(ll a, ll b, ll c) {
  // 先判断是否在可缓存范围（0~20），如果是则直接返回缓存值
  if (a >= 0 && a <= 20 && b >= 0 && b <= 20 && c >= 0 && c <= 20 &&
      f[a][b][c] != 0) {
    return f[a][b][c];
  }
  // 递归终止条件
  if (a <= 0 || b <= 0 || c <= 0) {
    return 1;
  } else if (a > 20 || b > 20 || c > 20) {
    return w(20, 20, 20);
  } else if (a < b && b < c) {
    // 计算后缓存结果
    return f[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
  } else {
    // 计算后缓存结果
    return f[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) +
                        w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
  }
}

int main() {
  // 预处理：计算所有0~20范围内的结果并缓存
  w(20, 20, 20);

  ll a, b, c;
  while (cin >> a >> b >> c) {
    if (a == -1 && b == -1 && c == -1) break;
    cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
  }

  return 0;
}