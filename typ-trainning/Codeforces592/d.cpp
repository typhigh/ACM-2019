#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF64 = 1LL << 60;
const int MAXN = 100010;
int n, c[MAXN][3];
vector<int> G[MAXN];

void DFS(int u, int fa, vector<int>& q) {
	q.push_back(u);
	for (int v: G[u]) {
		if (fa == v) continue;
		DFS(v, u, q);
	}
}
void solve() {
	int one = 0;
	int two = 0;
	int st = -1;
	for (int i = 0; i < n; ++i) {
		if (G[i].size() == 1) {
			++one;
			st = i;
		} else if (G[i].size() == 2) {
			++two;
		}
	}
	
	if (one != 2 || two != n - 2) {
		puts("-1");
		return;
	}

	vector<int> q;
	DFS(st, -1, q);
	vector<int> p = {0, 1, 2};
	vector<int> ans;
	LL minv = INF64;
	do {
		LL now = 0;
		for (int i = 0; i < n; ++i) {
			int x = q[i];
			now += c[q[i]][p[i%3]];
		}
		if (minv > now) {
			minv = now;
			ans = p;
		}
	} while(next_permutation(p.begin(), p.end()));
	cout << minv << '\n';
	vector<int> col;
	col.resize(n);
	for (int i = 0; i < n; ++i) 
		col[q[i]] = ans[i%3]+1;
	for (int i = 0; i < n; ++i) 
		cout << col[i] << (" \n"[i == n-1]);
}
int main() {
	scanf("%d", &n);
	for (int j = 0; j < 3; ++j)
		for (int i = 0; i < n; ++i) 
			scanf("%d", &c[i][j]);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	solve();
}
