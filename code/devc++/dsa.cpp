#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e8 + 5; // 确保覆盖最大可能的n
bool num[MAXN];
vector<int> ord; // 动态数组避免越界
vector<long long> ans;

void shai(int n) {
    memset(num, true, sizeof(num));
    num[0] = num[1] = false;
    int sqrt_n = static_cast<int>(sqrt(n));
    for (int i = 2; i <= sqrt_n; ++i) {
        if (num[i]) {
            // 标记倍数时使用long long防止溢出
            for (long long j = (long long)i * i; j <= n; j += i) {
                num[j] = false;
            }
        }
    }
    // 统一收集所有未被标记的素数
    for (int i = 2; i <= n; ++i) {
        if (num[i]) {
            ans.push_back(i);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    ord.resize(q); // 动态调整大小
    for (int i = 0; i < q; ++i) {
        cin >> ord[i];
    }
    shai(n);
    for (int i = 0; i < q; ++i) {
        // 假设输入是1-based索引
        cout << ans[ord[i] - 1] << endl;
    }
    return 0;
}
