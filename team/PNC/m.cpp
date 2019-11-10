#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2050;

struct TwoSAT {
	int n;
	vector<int> G[MAXN*2];
	bool mark[MAXN*2];
	int S[MAXN*2], c;

	bool dfs(int x) {
		if (mark[x^1]) return false;
		if (mark[x]) return true;
		mark[x] = true;
		S[c++] = x;
		for (int i = 0; i < G[x].size(); ++i) 
			if (!dfs(G[x][i])) return false;
		return  true;
	}

	void init(int n) {
		this->n = n;
		for (int i = 0; i < n*2; ++i) G[i].clear();
//		memset(mark, 0, sizeof(mark));
	}

	void add_clause(int x, int xval, int y, int yval) {
		x = x * 2 + xval;
		y = y * 2 + yval;
		G[x^1].push_back(y);
		G[y^1].push_back(x);
	}

	void pop_clause(int x, int xval, int y, int yval) {
		x = x * 2 + xval;
		y = y * 2 + yval;
		G[x^1].pop_back();
		G[y^1].pop_back();
	}
	bool solve() {
		memset(mark, 0, sizeof(mark));
		for (int i = 0; i < n*2; i += 2) {
			if (!mark[i] && !mark[i+1]) {
				c = 0;
				if (!dfs(i)) {
					while (c > 0) mark[S[--c]] = false;
					if (!dfs(i+1)) return false;
				}
			}
		}
		return true;
	}
}G;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	G.init(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		bool uf = u > 0;
		bool vf = v > 0;
		u = abs(u);
		v = abs(v);
		--u, --v;
		G.add_clause(u, uf, v, vf);
	}
	if (!G.solve()) {
		puts("0");
		return 0;
	}
	
	for (int i = 0; i < n; ++i) {
		G.add_clause(i, 1, i, 1);
		if (!G.solve()) {
			puts("1");
			return 0;
		}
		G.pop_clause(i, 1, i ,1);
	}
	for (int i = 0; i < n; ++i) 
		for (int j = i; j < n; ++j) G.add_clause(i, 1, j, 1);
	if (G.solve()) puts("-1");
	else puts("2");
}
