#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100010;
const LL INF64 = 1LL << 60;
int n, m, k, q;

struct Edge {
    int u, v;
    LL w;
    bool operator < (const Edge& rhs) const {
        return w < rhs.w;
    }
};
vector<int> G[MAXN];
vector<Edge> edges;
bool vis[MAXN];
int fro[MAXN], pa[MAXN], sz[MAXN];
LL d[MAXN], val[MAXN];
int fa(int x) {
    return x == pa[x] ? x : fa(pa[x]);
}

void addEdge (int u, int v, int w) {
    edges.push_back(Edge {u, v, w});
    G[u].push_back(edges.size()-1);
    edges.push_back(Edge {v, u, w});
    G[v].push_back(edges.size()-1);
}

struct HeapNode {
    LL x;
    int u;
    bool operator < (const HeapNode& rhs) const {
        return x > rhs.x;
    }
};

void dij() {
    priority_queue<HeapNode> pq;
    for (int i = 1; i <= k; ++i) fro[i] = i, d[i] = 0, pq.push(HeapNode{0, i});
    for (int i = k+1; i <= n; ++i) d[i] = INF64;
    while (!pq.empty()) {
        HeapNode x = pq.top(); pq.pop();
        int u = x.u;
        if (vis[u]) continue;
        vis[u] = true;
        for (int i: G[u]) {
            Edge& e = edges[i];
            int v = e.v;
            if (d[v] > d[u] + e.w) {
                d[v] = d[u] + e.w;
                fro[v] = fro[u];
                pq.push(HeapNode{d[v], v});
            }
        }
    } 
}

LL query(int u, int v) {
    LL ans = 0;
    while (u != v) {
        if (sz[u] > sz[v]) swap(u, v);
        ans = max(ans, val[u]);
        u = pa[u];
    }    
    return ans;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }
    dij();
    vector<Edge> data;
    for (int i = 0; i < edges.size(); i += 2) {
        Edge& e = edges[i];
        data.push_back(Edge{fro[e.u], fro[e.v], e.w + d[e.u] + d[e.v]});
    }
    sort(data.begin(), data.end());
    for (int i = 1; i <= k; ++i) pa[i] = i, sz[i] = 1;
    for (int i = 0; i < m; ++i) {
        int u = fa(data[i].u);
        int v = fa(data[i].v);
        if (u == v) continue;
        if (sz[u] > sz[v]) swap(u, v);
        pa[u] = v;
        sz[v] += sz[u];
        val[u] = data[i].w;
    }

    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        cout << query(u, v) << '\n';
    }
}