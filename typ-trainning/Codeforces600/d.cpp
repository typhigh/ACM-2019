#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
vector<int> G[MAXN];
int n, m, tot;
bool vis[MAXN];
vector<pair<int, int>> v;

void DFS(int u) {
    vis[u] = 1;
    v[tot].first = min(v[tot].first, u);
    v[tot].second = max(v[tot].second, u);
    for (auto v: G[u]) {
        if (vis[v]) continue;
        DFS(v);
    }
}

int solve() {
    int ret = 0;
    pair<int, int> now = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (now.second < v[i].first) {
            now = v[i];
            continue;
        }
        ++ret;
        if (v[i].second > now.second) now = v[i];
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }    
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        v.emplace_back(n, 1);
        DFS(i);
        ++tot;
    }
    sort(v.begin(), v.end());
//    for (auto p : v) cout << p.first << " " << p.second << endl;
    printf("%d\n", solve());
}