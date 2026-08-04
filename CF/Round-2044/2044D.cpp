#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;
const int LIMIT = 100;
const int N = 1e7;
int p[N + 1];
vector<int> primes;

int gcd(int a, int b) {
	while (b) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

void sieve() {
	for (int i = 2; i <= N; ++i) {
		if (!p[i]) {
			p[i] = i;
			primes.push_back(i);
		}
		for (int j : primes) {
			if (j > p[i] || (i64)i * j > N) break;
			p[i * j] = j;
		}
	}
}

i64 calc(i64 x, const vector<int>& fac) {
	if (x <= 0) return 0;
	int sz = fac.size();
	i64 res = 0;
	for (int mask = 1; mask < (1 << sz); ++mask) {
		i64 prod = 1;
		int bits = 0;
		for (int i = 0; i < sz; ++i) {
			if (mask >> i & 1) {
				prod *= fac[i];
				bits++;
			}
		}
		i64 cnt = x / prod;
		if (bits & 1) res += cnt;
		else res -= cnt;
	}
	return x - res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	int T;
	cin >> T;
	
	while (T--) {
		int l, r, n;
		cin >> l >> r >> n;
		vector<int> fac;
		int tmp = n;
		while (tmp > 1) {
			int pr = p[tmp];
			fac.push_back(pr);
			while (tmp % pr == 0) tmp /= pr;
		}
		i64 ans = 0;
		int far_end = min(r, n - LIMIT - 1);
		if (far_end >= l) {
			i64 cnt1 = calc(far_end, fac) - calc(l - 1, fac);
			i64 total = far_end - l + 1;
			ans += cnt1 + 2 * (total - cnt1);
		}
		int near_start = max(l, n - LIMIT);
		for (int i = near_start; i <= r; ++i) {
			if (gcd(i, n) == 1) {
				ans += 1;
			} else {
				bool found = false;
				for (int k = i + 1; k < n; ++k) {
					if (gcd(k, i) == 1 && gcd(k, n) == 1) {
						found = true;
						break;
					}
				}
				ans += found ? 2 : 3;
			}
		}
		cout << ans << endl;
	}
	return 0;
}