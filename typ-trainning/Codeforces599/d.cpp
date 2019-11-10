#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
vector<int> G[MAXN];
int n, m, du[MAXN], pa[MAXN];
bool vis[MAXN];
int fa(int x) {
    return x == pa[x] ? x : pa[x] = fa(pa[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) pa[i] = i;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
        ++du[u], ++du[v];
    }
    for (int i = 0 ; i < n; ++i) G[i].push_back(n);
    int which = 0;
    for (int i = 1; i < n; ++i) {
        if (du[i] < du[which]) which = i;
    } 
    int cnt = 0;
    sort(G[which].begin(), G[which].end());
//    cout << which << " " << G[which].size() << endl;
    for (int i = 0, old = 0; i < G[which].size(); ++i) {
        for (int j = old; j < G[which][i]; ++j) {
            pa[j] = which;
            ++cnt;
        }
        old = G[which][i]+1;
    }
//    cout << cnt << endl;
    for (int i = 0; i < G[which].size(); ++i) {
        int u = G[which][i];
        sort(G[u].begin(), G[u].end());
        for (int j = 0, old = 0; j < G[u].size(); ++j) {
            for (int v = old; v < G[u][j]; ++v) {
                int fu = fa(u);
                int fv = fa(v);
                if (fu == fv) continue;
                pa[fu] = fv;
                ++cnt;
            }
            old = G[u][j]+1;
        }
    }
    cout << n - cnt << endl;
}
