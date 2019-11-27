#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300100;
const double INF = 1e9 + 7;
int n, m, deg[MAXN];

struct HeapNode {
    double val;
    int u;
    bool operator < (const HeapNode& rhs) const {
        return val > rhs.val;
    }
};

struct Value{
    double sum;
    int b;
    double val;
    void set() {
        if (b) val = sum / b;
    }
} a[MAXN];

struct Dij {
    int n, m;
    vector<int> G[MAXN];
    bool done[MAXN];
    double d[MAXN];

    void Add(int v, int u) {
        ++a[v].b;
        a[v].sum += d[u];
        a[v].set();
        d[v] = a[v].val;
    }

    void init(int n) {
        this->n = n;
        for (int i = 1; i <= n; ++i) G[i].clear();
    }

    void AddEdge(int x, int y) {
        G[x].push_back(y);
        G[y].push_back(x);
    }

    double solve(int s) {
        priority_queue<HeapNode> q;
        for (int i = 1; i <= n; ++i) d[i] = INF;
        d[s] = 0;
        memset(done, 0, false);
        q.push((HeapNode{0, s}));
        while (!q.empty()) {
            HeapNode x = q.top();
            q.pop();
            int u = x.u;
            if (done[u]) continue;
            done[u] = true;
            for (int v: G[u]) {
                if (done[v]) continue;
                Add(v, u);
                q.push(HeapNode{d[v], v});
            }
        }
        return d[1];
    }
} g;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        g.AddEdge(x, y);      
        ++deg[x], ++deg[y];
    }
    for (int i = 1; i <= n; ++i) {
        a[i].sum = deg[i];
        a[i].b = 0;
    }
    printf("%.7f\n", g.solve(n));
}