#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000100;
vector<int> G[MAXN];
bool dp[MAXN], vis[MAXN];
int n, p[MAXN];

bool DFS(int u) {
	if (vis[u]) return dp[u];
	vis[u] = true;
	int count = 0;
	for (int v: G[u]) {
		count += DFS(v);
	}
	if (count == 1) dp[u] = false;
	else dp[u] = true;
	cout << " " << u << " " << dp[u] << endl;
	return dp[u];
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			G[i].clear();
			vis[i] = false;
		}
		for (int i = 2; i <= n; ++i) {
			scanf("%d", p + i);
			G[p[i]].push_back(i);
		}
		bool ans = DFS(1);
		if (ans) puts("Takeru");
		else puts("Meiya");
	}
}
