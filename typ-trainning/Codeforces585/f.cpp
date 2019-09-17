#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1600043;

struct TwoSAT {
	int n;
	vector<int> G[MAXN];
	bool mark[MAXN];
	int S[MAXN], c;

	bool dfs(int x) {
		if (mark[x^1]) return false;
		if (mark[x]) return true;
		mark[x] = true;
		S[c++] = x;
		for (int u: G[x])
			if (!dfs(u)) return false;
		return true;
	}
	void init(int n) {
		this->n = n;
		for (int i = 0; i < n * 2; ++i) G[i].clear();
		memset(mark, 0, sizeof(mark));
	}

	void addClause(int x, int xval, int y, int yval) {
		x = x * 2 + xval;
		y = y * 2 + yval;
		G[x^1].push_back(y);
		G[y^1].push_back(x);
	}

	bool solve() {
		for (int i = 0; i < n * 2; i += 2) 
			if (!mark[i] && !mark[i+1]) {
				c = 0;
				if (!dfs(i)) {
					while (c > 0) mark[S[--c]] = false;
					if (!dfs(i+1)) return false;
				}
			}
		return true;
	}
}G;

int n, p, M, m;
int main() {
	scanf("%d %d %d %d", &n, &p, &M, &m);
	G.init(p + M - 1);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		G.addClause(x, 0, y, 0);
	}
//	cout << " 1 " << endl;

	for (int i = 0; i < p; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		if (l != 1) G.addClause(p+l-2, 0, i, 1);
		if (r != M) G.addClause(p+r-1, 1, i, 1);
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		G.addClause(x, 1, y, 1);
	}
	for (int i = 2; i <= M - 1; ++i) {
		int f1 = i - 2 + p;
		int f2 = f1 + 1;
		G.addClause(f1, 0, f2, 1);
	}

//	cout << " 2 " << endl;
	if (!G.solve()) {
		puts("-1");
		return 0;
	}

//	cout << " 3 " << endl;
	vector<int> stations;
	int k = 1;
	for (int i = 0; i < 2 * G.n; i += 2) {
		if (i < 2 * p && G.mark[i]) stations.push_back(i/2);
		if (i >= 2 * p && G.mark[i]) k = i / 2 - p + 2;
	}
	printf("%d %d\n", stations.size(), k);
	for (int x : stations) 
		printf("%d ", x + 1);
	puts("");
	return 0;
}
