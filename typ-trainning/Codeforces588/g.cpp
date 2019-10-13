#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200010;
const int MAXP = 125;

map<vector<int>, int> ID;
vector<int> p[MAXP];
vector<int> a[MAXN];
int g[MAXP][MAXP];

int n, k;

int getID(vector<int>& a) {
	int ret;
	if (!ID.count(a)) {
		ret = ID.size();
		ID[a] = ret;
		p[ret] = a;
	} else {
		ret = ID[a];
	}
	// assert(ret < MAXP);
	return ret;
}

vector<int> calc(const vector<int>& a, const vector<int>& b) {
	vector<int> ret;
	ret.resize(k);
	for (int i = 0; i < k; ++i) ret[i] = a[b[i]];
	return ret;
}

void init() {
	vector<int> a;
	for (int i = 0; i < k; ++i) a.push_back(i);
	do {
		getID(a);
	} while(next_permutation(a.begin(), a.end()));

//	cout << "YES1" << endl;
	for (int i = 0; i < ID.size(); ++i) 
		for (int j = 0; j < ID.size(); ++j)
			g[i][j] = ID[calc(p[i], p[j])];
//	cout << "YES2" << endl;
}

int vis[MAXP];
int BFS(vector<int> ids) {
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(0);
	vis[0] = 1;
	int ret = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : ids) {
			int xy = g[x][y];
			if (vis[xy]) continue;
			vis[xy] = true;
			++ret;
			q.push(xy);
		}
	}
	return ret;
}

LL solve() {
	LL ret = 0;
	int t = 0;
	vector<int> G[2], d[2];
	G[0].clear();
	d[0].clear();

	for (int i = 0; i < n; ++i) {
		G[t^1].clear();
		d[t^1].clear();
		d[t^1].push_back(i);
		G[t^1].push_back(ID[a[i]]);
		// G and d have the same size
		int s = BFS(G[t^1]);
		for (int j = 0; j < G[t].size(); ++j) {
			if (vis[G[t][j]]) continue;
			ret += 1LL * s * (d[t^1][d[t^1].size()-1] - d[t][j]);
			d[t^1].push_back(d[t][j]);
			G[t^1].push_back(G[t][j]);
			s = BFS(G[t^1]);
		}
		ret += s * (d[t^1][d[t^1].size()-1]+1);
		t^=1;
//		cout << ret << endl;
	}
	return ret;
}

int main() {
	scanf("%d %d", &n, &k);
	init();
	for (int i = 0; i < n; ++i) {
		a[i].clear();
		a[i].resize(k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &a[i][j]);
			--a[i][j];
		}
	}
//	cout << "yes" << endl;
	cout << solve() << endl;
}
