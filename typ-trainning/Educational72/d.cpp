#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5050;
bool circled, vis[MAXN];
int n, m, du[MAXN];
vector<int> G[MAXN];
vector<pair<int, int>> edges;

void AddEdge(int from, int to) {
	++du[to];
	int id = edges.size();
	edges.emplace_back(from, to);
	G[from].push_back(id);
}

bool Circle() {
	int cnt = n;
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (du[i] == 0) q.push(i);
	}
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		--cnt;
		for (int id : G[u]) {
			int v = edges[id].second;
			if (--du[v] == 0) q.push(v);
		}
	}
	return cnt > 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		AddEdge(u, v);
	}
	circled = Circle();
	int cnt = circled ? 2 : 1;
	printf("%d\n", cnt);
	vector<int> ans;
	if (!circled) {
		for (int i = 0; i < m; ++i) ans.push_back(1);
	} else {
		for (int i = 0; i < m; ++i) {
			auto& p = edges[i];
			if (p.first > p.second) ans.push_back(1);
			else ans.push_back(2);
		}
	}
	for (int i = 0; i < m; ++i) {
		printf("%d%c", ans[i], " \n"[i == m-1]);
	}
}
