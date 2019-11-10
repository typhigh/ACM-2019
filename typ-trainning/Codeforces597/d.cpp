#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2010;
typedef long long LL;
struct Edge {
    int x, y;
    LL cost;
    bool operator < (const Edge& rhs) const {
        return cost < rhs.cost;
    }
};

vector<Edge> edges;
int n, pa[MAXN], x[MAXN], y[MAXN], k[MAXN], c[MAXN];

LL Calc(int i, int j) {
    return 1LL * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));     
}

int fa(int x) {
    return x == pa[x] ? x : pa[x] = fa(pa[x]);  
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) pa[i] = i;
    for (int i = 0; i < n; ++i) scanf("%d %d", x+i, y+i);
    for (int i = 0; i < n; ++i) scanf("%d", c+i);
    for (int i = 0; i < n; ++i) scanf("%d", k+i);
    for (int i = 0; i < n; ++i) 
        for (int j = i+1; j < n; ++j) edges.push_back(Edge {i, j, Calc(i, j)});
    for (int i = 0; i < n; ++i) edges.push_back(Edge {i, n, c[i]});
    sort(edges.begin(), edges.end());
    vector<pair<int, int>> p;
    vector<int> build;
    LL ans = 0;
    int cnt = n;
    for (int i = 0; i < edges.size() && cnt; ++i) {
        int x = edges[i].x;
        int y = edges[i].y;
        if (x > y) swap(x, y); 
        int fx = fa(x);
        int fy = fa(y);
        if (fx == fy) continue;
        pa[fx] = fy;
        if (y == n) build.push_back(x);
        else p.emplace_back(x, y);
        --cnt;
        ans += edges[i].cost;
    }
    cout << ans << "\n";
    printf("%d\n", build.size());
    for (int i = 0; i < build.size(); ++i) {
        printf("%d %c", build[i]+1, " \n"[i == build.size()-1]);
    }
    printf("%d\n", p.size());
    for (int i = 0; i < p.size(); ++i) {
        printf("%d %d\n", p[i].first+1, p[i].second+1);
    }
}