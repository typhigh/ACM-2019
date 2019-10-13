#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300010;
vector<int> G[MAXN];
int n, ans, dp[MAXN][3], fa[MAXN];

void AddEdge(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

void init() {
	for (int i = 0; i < n; ++i) G[i].clear();
	for (int i = 0; i < n; ++i) dp[i][0] = dp[i][1] = dp[i][2] = 0, fa[i] = -1;
	ans = 0;
}

int DP(int u, int op) {
	if (dp[u][op]) return dp[u][op];
	int &d = dp[u][op];
	int fi0 = 0, fi1 = 0, fi2 = 0, se2 = 0;
	for (int v : G[u]) {
		if (fa[u] == v) continue;
		fa[v] = u;
		int now = DP(v, 2);
		if (now >= fi2) {
			se2 = fi2;
			fi2 = now;
		} else if (now > se2) se2 = now;
		now = DP(v, 1);
		fi1 = max(fi1, now);
		now = DP(v, 0);
		fi0 = max(fi0, now);
	}
	int cnt = (int) G[u].size() - 1;
	if (op == 0) d = fi0;
	if (cnt == 0)  
		d = 1;
	else if (cnt == 1) {
		if (op == 0) d = max(d, fi1 + 1);
		else d = max(d, fi2 + 1);
	} else {
		if (fi2 == 0 || se2 == 0) while(1);
		if (op == 0) d = max(d, max(fi1 + 1, fi2 + se2 + cnt - 1));
		else if (op == 1) d = max(d, fi2 + se2 + cnt - 1);
		else d = max(d, fi2 + cnt);
	}
//	cout << u << " " << op << " " << d << endl;
//	cout << fi0 << " " << fi1 << " " << fi2 << " " << se2 << endl;
	return d;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		init();
		for (int i = 0 ; i < n - 1; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			--u, --v;
			AddEdge(u, v);
		}
		G[0].push_back(-1);
		cout << DP(0, 0) << endl;
	}
}


