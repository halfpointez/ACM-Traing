#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e8 + 5; // ȷ�����������ܵ�n
bool num[MAXN];
vector<int> ord; // ��̬�������Խ��
vector<long long> ans;

void shai(int n) {
    memset(num, true, sizeof(num));
    num[0] = num[1] = false;
    int sqrt_n = static_cast<int>(sqrt(n));
    for (int i = 2; i <= sqrt_n; ++i) {
        if (num[i]) {
            // ��Ǳ���ʱʹ��long long��ֹ���
            for (long long j = (long long)i * i; j <= n; j += i) {
                num[j] = false;
            }
        }
    }
    // ͳһ�ռ�����δ����ǵ�����
    for (int i = 2; i <= n; ++i) {
        if (num[i]) {
            ans.push_back(i);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    ord.resize(q); // ��̬������С
    for (int i = 0; i < q; ++i) {
        cin >> ord[i];
    }
    shai(n);
    for (int i = 0; i < q; ++i) {
        // ����������1-based����
        cout << ans[ord[i] - 1] << endl;
    }
    return 0;
}
