#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 500010;
struct Water {
	int t, a, b;
	bool operator < (const Water& r) const {
		return t < r.t;
	}
}w[MAXN];

int n, m, c, c0;

LL solve() {
	map<LL, LL> pool;
	LL cost = 0, cap = 0;
	for (int i = 0; i < n - 1; ++i) {
		LL t = w[i].t, a = w[i].a, b = w[i].b;
		if (cap < c && a) {
			int add = min(c- cap, a);
			cap += add;
			a -= add;
			pool[b] += add;
		}
		
		while (a && !pool.empty() && pool.rbegin()->first > b) {
			auto it = pool.end();
			--it;
			LL add = min(a, it->second);
			a -= add;
			it->second -= add;
			if (it->second == 0) pool.erase(it);
			pool[b] += add;
		}
		
		LL need = w[i+1].t - w[i].t;
		while (need && !pool.empty()) {
			auto it = pool.begin();
			LL add = min(it->second, need);
			need -= add;
			cap -= add;
			it->second -= add;
			cost += add * it->first;
			if (it->second == 0) pool.erase(it);
		}
		if (need) return -1;
	}
	return cost;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &n, &m, &c, &c0);
		for (int i = 0; i < n; ++i) {
			int t, a, b;
			scanf("%d %d %d", &t, &a, &b);
			w[i] = Water{t, a, b};
		}
		w[n++] = Water{0, c0, 0};
		w[n++] = Water{m, 0, 0};
		sort(w, w+n);
		cout << solve() << endl; 
	}
}
