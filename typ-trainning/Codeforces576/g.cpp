#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400;
const int INF = 0x3f3f3f3f;
bool g[MAXN][MAXN];

struct Edge {
	int from, to, cap, flow;
	Edge(int from, int to, int cap, int flow) : from(from), to(to), cap(cap), flow(flow) {}
};

struct Dinic {
	int n, m, s, t;
	vector<Edge> edges;
	vector<int> G[MAXN];
	bool vis[MAXN];
	int d[MAXN];
	int cur[MAXN];

	void Init(int n) {
		this->n = n;
		for (int i = 0; i < MAXN; ++i) G[i].clear();
		edges.clear();
		memset(vis, 0, sizeof(vis));
	}

	void AddEdge(int from, int to, int cap) {
//		cout << from << "->" << to << " " << cap << endl;
		edges.emplace_back(from, to, cap, 0);
		edges.emplace_back(to, from, 0, 0);
		m = edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}

	bool BFS() {
		memset(vis, 0, sizeof(vis));
		queue<int> Q;
		Q.push(s);
		d[s] = 0;
		vis[s] = 1;
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			for (int i = 0; i < G[x].size(); ++i) {
				Edge& e = edges[G[x][i]];
				if (!vis[e.to] && e.cap > e.flow) {
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}

	int DFS(int x, int a) {
		if (x == t || a == 0) return a;
		int flow = 0, f;
		for (int& i = cur[x]; i < G[x].size(); ++i) {
			Edge& e = edges[G[x][i]];
			if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
				e.flow += f;
				edges[G[x][i]^1].flow -= f;
				flow += f;
				a -= f;
				if (a == 0) break;
			}
		}
		return flow;
	}

	int Maxflow(int s, int t) {
		this->s = s;
		this->t = t;
		int flow = 0;
		while(BFS()) {
			memset(cur, 0, sizeof(cur));
			flow += DFS(s, INF);
		}
		return flow;
	}
}G;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> X, Y;
	vector<pair<int, int>> L, R;
	X.push_back(1); 
	X.push_back(n+1);
	Y.push_back(1);
	Y.push_back(n+1);

	for (int i = 0; i < m; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		++x2, ++y2;
		X.push_back(x1);
		X.push_back(x2);
		Y.push_back(y1);
		Y.push_back(y2);
		L.emplace_back(x1, y1);
		R.emplace_back(x2, y2);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	int S = X.size() + Y.size();
	int T = S + 1;
	G.Init(T);
	for (int i = 0; i+1 < X.size(); ++i) 
		G.AddEdge(S, i, X[i+1] - X[i]);
	for (int i = 0; i+1 < Y.size(); ++i)
		G.AddEdge(X.size() + i, T, Y[i+1] - Y[i]);
	for (int i = 0; i < m; ++i) {
		int lx = lower_bound(X.begin(), X.end(), L[i].first) - X.begin();
		int ly = lower_bound(Y.begin(), Y.end(), L[i].second) - Y.begin();
		int rx = lower_bound(X.begin(), X.end(), R[i].first) - X.begin();
		int ry = lower_bound(Y.begin(), Y.end(), R[i].second) - Y.begin();
		for (int x = lx; x < rx; ++x) {
			for (int y = ly; y < ry; ++y) {
				g[x][y] = true;
			}
		}
	}
	for (int x = 0; x < X.size(); ++x) 
		for (int y = 0; y < Y.size(); ++y) 
			if (g[x][y]) G.AddEdge(x, y + X.size(), INF);
	cout << G.Maxflow(S, T) << endl;
}
