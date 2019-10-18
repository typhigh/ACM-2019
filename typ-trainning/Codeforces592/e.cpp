#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200010;
int n, a[MAXN];
LL k;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	sort(a, a + n);
	a[n] = -1;
	int cnt = 1;
	vector<pair<LL, int>> q;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == a[i-1]) ++cnt;
		else {
			q.emplace_back(a[i-1], cnt);
			cnt = 1;
		}
	}
	int L = 0, R = q.size()-1;
	while (k && R > L) {
		if (q[L].second > q[R].second) {
			LL step = k / q[R].second;
			step = min(step, q[R].first - q[R-1].first);
			if (!step) break;
			k -= step * q[R].second;
			q[R].first -= step;
			if (q[R].first == q[R-1].first) {
				q[R-1].second += q[R].second;
				--R;
			}
		} else {
			LL step = k / q[L].second;
			step = min(step, q[L+1].first - q[L].first);
			if (!step) break;
			q[L].first += step;
			k -= step * q[L].second;
			if (q[L].first == q[L+1].first) {
				q[L+1].second += q[L].second;
				++L;
			}
		}
	}
	cout << q[R].first - q[L].first << endl;
}
