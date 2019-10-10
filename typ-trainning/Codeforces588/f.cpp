#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
typedef long long LL;
int n, m, deg[MAXN];
vector<int> in[MAXN];

LL Calc(int u) {return (deg[u] - in[u].size()) * (in[u].size());}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (u > v) swap(u, v);
		in[u].push_back(v);
		++deg[u], ++deg[v];
	}
	LL ans = 0;
	for (int i = 1; i <= n; ++i) ans += Calc(i);
	cout << ans << endl;
	int q;
	scanf("%d", &q);
	while (q--) {
		int u;
		scanf("%d", &u);
		ans -= Calc(u);
		for (int v : in[u]) {
			ans -= Calc(v);
			in[v].push_back(u);
			ans += Calc(v);
		}
		in[u].clear();
		cout << ans << endl;
	}
}

