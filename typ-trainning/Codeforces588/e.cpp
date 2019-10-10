#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100010;
const LL MOD = 1e9 + 7;
vector<int> G[MAXN];
map<LL, int> valToCnt[MAXN];
LL ans, a[MAXN];

int n;

void addEdge(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

void DFS(int u, int fa) {
	for (auto& p : valToCnt[fa]) {
		LL tmp = __gcd(p.first, a[u]);
		valToCnt[u][tmp] += p.second;
		ans = (ans + tmp * p.second) % MOD;
	}
	++valToCnt[u][a[u]];
	ans = (ans + a[u]) % MOD;
	for (int v : G[u]) 
		if (v != fa) 
			DFS(v, u);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	}
	DFS(1, 1);
	ans = (ans % MOD + MOD) % MOD;
	cout << ans << endl;
	return 0;
}
