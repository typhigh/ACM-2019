#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100010;
vector<int> b0, b1;
pair<int, bool> b[MAXN];
int n, m;

LL solve2(multiset<int> a, bool flag) {
	LL ans =  0;
	vector<int> now;
	for (int u : a) now.push_back(u);
	reverse(now.begin(), now.end());
	for (int i = 0; i < now.size(); ++i) {
		if (i >= b0.size()) {
			if (flag) ans += now[i];
		} else {
			if (now[i] < b0[i]) break;
			else ans += 1LL * now[i] - b0[i];
		}
	}
//	cout <<"solve2 " << ans << endl;
	return ans;
}


LL solve1(multiset<int> a) {
	// attack people
	LL ans;
	if (m >= n){
		ans = 0;
	} else {
		ans = 0;
		for (int u: b1) {
			auto it = lower_bound(a.begin(), a.end(), u);
			if (it == a.end()) {
				ans = 0;
				goto L1;
			}
			a.erase(it);
		}
		ans = solve2(a, true);
	}
L1 :
//	cout << "solve1 " << ans << endl;
	return ans;
}

int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		multiset<int> a;
		scanf("%d %d", &n, &m);
		a.clear();
		b0.clear();
		b1.clear();
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			a.insert(x);
		}
//		sort(a.begin(), a.end());
		for (int i = 0; i < m; ++i) scanf("%d", &b[i].first);
		for (int i = 0; i < m; ++i) {
			int x;
			scanf("%d", &x);
			b[i].second = x;
			if (x) b1.push_back(b[i].first);
			else b0.push_back(b[i].first);
		}
//		sort(b.begin(), b.end());
		sort(b0.begin(), b0.end());
		sort(b1.begin(), b1.end());
		LL ans = max(solve1(a), solve2(a, false));
		cout << "Case " << ++kase << ": " << ans << endl; 
	}
}
