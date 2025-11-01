#include <bits/stdc++.h>
using namespace std;
#define ll long long

void f(ll hang, ll lie, ll x, ll y, ll len) {
    if (len == 1) return;

    ll mid = len / 2;

    if (x <= hang + mid - 1 && y <= lie + mid - 1) { // 左上象限
        cout << hang + mid << " " << lie + mid << " 1" << endl;
        f(hang, lie, x, y, mid); // 左上
        f(hang, lie + mid, hang + mid - 1, lie + mid, mid); // 右上
        f(hang + mid, lie, hang + mid, lie + mid - 1, mid); // 左下
        f(hang + mid, lie + mid, hang + mid, lie + mid, mid); // 右下
    } else if (x <= hang + mid - 1 && y > lie + mid - 1) { // 右上象限
        cout << hang + mid << " " << lie + mid - 1 << " 2" << endl; // 改为类型2
        f(hang, lie, hang + mid - 1, lie + mid - 1, mid); // 左上
        f(hang, lie + mid, x, y, mid); // 右上
        f(hang + mid, lie, hang + mid, lie + mid - 1, mid); // 左下
        f(hang + mid, lie + mid, hang + mid, lie + mid, mid); // 右下
    } else if (x > hang + mid - 1 && y <= lie + mid - 1) { // 左下象限
        cout << hang + mid - 1 << " " << lie + mid << " 3" << endl; // 改为类型3
        f(hang, lie, hang + mid - 1, lie + mid - 1, mid); // 左上
        f(hang, lie + mid, hang + mid - 1, lie + mid, mid); // 右上
        f(hang + mid, lie, x, y, mid); // 左下
        f(hang + mid, lie + mid, hang + mid, lie + mid, mid); // 右下
    } else { // 右下象限
        cout << hang + mid - 1 << " " << lie + mid - 1 << " 4" << endl;
        f(hang, lie, hang + mid - 1, lie + mid - 1, mid); // 左上
        f(hang, lie + mid, hang + mid - 1, lie + mid, mid); // 右上
        f(hang + mid, lie, hang + mid, lie + mid - 1, mid); // 左下
        f(hang + mid, lie + mid, x, y, mid); // 右下
    }
}

int main() {
    ll k, x, y;
    cin >> k >> x >> y;
    f(1, 1, x, y, 1LL << k);
    return 0;
}
