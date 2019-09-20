#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
const int INF32 = 0x3f3f3f3f;

int n, d[MAXN][20];
vector<pair<int, int>> a, ans;

void update(int& x, int d) {
	x = min(x, d);
}

void init() {
	for (int k = 1; (1<<k) <= MAXN; ++k) 
		for (int i = 0; i + (1<<k) - 1 < MAXN; ++i) 
			d[i][k] = min(d[i][k-1], d[i+(1<<k-1)][k-1]);
}

int query(int l, int r) {
	int k = 0;
	while ((1<<k) <= r - l + 1) ++k;
	return min(d[l][k-1], d[r-(1<<k-1)+1][k-1]);
}

int main() {
	while (~scanf("%d", &n)) {
		a.clear();
		ans.clear();
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d %d", &x, &y);
			a.emplace_back(++x, ++y);
		}
		for (int i = 0; i < MAXN; ++i) d[i][0] = INF32;
		for (int i = 0; i < n; ++i) update(d[a[i].first][0], a[i].second);
		init();
		sort(a.begin(), a.end());
		for (auto e: a) 
			if (query(0, e.first-1) >= e.second) 
				ans.push_back(e);
		printf("%d\n", ans.size());
		for (auto e: ans) 
			printf("%d %d\n", e.first-1, e.second-1);
	}
}
