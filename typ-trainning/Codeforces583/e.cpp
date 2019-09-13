#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
int n, d[MAXN], id[MAXN];
vector<int> G[MAXN];

void solve() {
	vector<pair<int, int>> dii;
	for (int i = 1; i <= n; ++i) dii.emplace_back(-d[i], i);
	sort(dii.begin(), dii.end());
	
	for (int i = 1; i <= n; ++i) {
		id[i] = dii[i-1].second;
//		cout << id[i] << " ";
	}
//	cout << endl;
	int nn = n;
	for (int i = 1; i <= n; ++i) {
		int idx = id[i];
		int pos = d[idx] + i;
		assert(pos <= nn + 1);
		if (pos > nn) id[++nn] = 2 * idx;
		else {
			--pos;
			G[pos].push_back(2 * idx);
		}
	}
	for (int i = 1; i <= n; ++i) id[i] = id[i] * 2 - 1;
	
	for (int i = 1; i < nn; ++i) printf("%d %d\n", id[i], id[i+1]);
	for (int i = 1; i < nn; ++i) {
		for (int v : G[i]) {
			printf("%d %d\n", id[i], v);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", d + i);
	solve();
}
