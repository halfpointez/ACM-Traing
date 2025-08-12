#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 100005;

struct Water {
    ll h;
    int id;
    Water() : h(0), id(0) {}
};

bool compare(const Water &a, const Water &b, ll H) {
    return a.h * (H - a.h) < b.h * (H - b.h);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        ll H;
        scanf("%d %lld", &n, &H);
        Water ws[maxn];
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &ws[i].h);
            ws[i].id = i;
        }
        sort(ws + 1, ws + 1 + n, [H](const Water &a, const Water &b) {
            return compare(a, b, H);
        });
        for (int i = 1; i <= n; ++i) printf("%d ", ws[i].id);
        printf("\n");
    }
    return 0;
}