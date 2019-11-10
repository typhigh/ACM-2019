#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000100;

vector<int> G[MAXN], G2[MAXN];
vector<int> S;
int vis[MAXN], sccno[MAXN], scc_cnt;
int kase;

void dfs1(int u) {
    if (vis[u] == kase) return ;
    vis[u] = kase;
    for (int i = 0; i < G[u].size(); ++i) dfs1(G[u][i]);
    S.push_back(u);
}

void dfs2(int u) {
    if (sccno[u]) return;
    sccno[u] = scc_cnt;
    for (int i = 0; i < G2[u].size(); ++i) dfs2(G2[u][i]);
}

void find_scc(int n) {
    scc_cnt = 0;
    S.clear();
//    memset(sccno, 0, sizeof(sccno));
//    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) dfs1(i);
    for (int i = n-1; i >= 0; --i) {
        if (!sccno[S[i]]) {
            ++scc_cnt;
            dfs2(S[i]);
        }
    }
}

int n, m;
void init() {
    for (int i = 0; i < n; ++i) {
        G[i].clear(), G2[i].clear();
        sccno[i] = 0;
    }
}

int du[MAXN];
void solve() {
    find_scc(n);
//    for (int i = 0; i < n; ++i) cout << sccno[i] << " \n"[i==n-1];
    if (scc_cnt == 1) {
        puts("No");
        return;
    }
    for (int i = 0; i <= scc_cnt; ++i) du[i] = 0;
    for (int u = 0; u < n; ++u) {
        for (int v: G[u]) {
            int x = sccno[u], y = sccno[v];
            if (x == y) continue;
//            g[x].push_back(y);
            ++du[x];
        }
    }
    int now = 0;
    vector<int> ans1, ans2;
    for (int i = 1; i <= scc_cnt; ++i) if (du[i] == 0) {
        now = i;
        break;
    }
//    cout << now << endl;
    for (int i = 0; i < n; ++i) {
        if (sccno[i] == now) ans1.push_back(i+1);
        else ans2.push_back(i+1);
    }
    puts("Yes");
    printf("%d %d\n", (int)ans1.size(), (int)ans2.size());
    for (int i = 0; i < ans1.size(); ++i) printf("%d%c", ans1[i], " \n"[i==ans1.size()-1]);
    for (int i = 0; i < ans2.size(); ++i) printf("%d%c", ans2[i], " \n"[i==ans2.size()-1]);
}

int main() {
    int T;
    kase = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        init();
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            --u, --v;
            if (u == v) continue;
            G[u].push_back(v);
            G2[v].push_back(u);
        }
        solve();
        ++kase;
    }
}