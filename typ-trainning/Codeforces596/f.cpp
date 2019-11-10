#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, p[MAXN], du[MAXN], cur[MAXN], vis[MAXN];
vector<int> G[MAXN];

int v, mdep;
void dfs(int u, int dep) {
    for (int v: G[u]) 
        dfs(v, dep+1);

    if (dep > mdep) {
        v = u;
        mdep = dep;
    }
}

vector<int> ans;
void Up(int u) {
    vis[u] = 1;
    if (u == 0) return;
    if (du[p[u]] == 1) {
        return Up(p[u]);
    }
    int fa = p[u];
    for (int& i = cur[fa]; i < G[fa].size(); ++i) {
        int v = G[fa][i];
        if (vis[v]) continue;
        ans.push_back(u);
        p[u] = v;
        ++du[v];
        --du[fa];
        return Up(u);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) scanf("%d", p + i);
    for (int i = 1; i < n; ++i) {
        int x = i;
        int y = p[i];
        ++du[y];
        G[y].push_back(x);
    }
    dfs(0, 0);
    p[0] = -1;
    int from = v;
    Up(from);
    vector<int> st;
    st.push_back(from);
    for (int u = p[from]; u != -1; u = p[u]) st.push_back(u);
    reverse(st.begin(), st.end());
    for (int i = 0; i < st.size(); ++i) {
        printf("%d%c", st[i], " \n"[i==st.size()-1]);
    }
    reverse(ans.begin(), ans.end());
    printf("%d ", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d%c", ans[i], " \n"[i==ans.size()-1]);
    } 
}