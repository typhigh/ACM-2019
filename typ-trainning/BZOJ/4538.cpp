/**************************************************************
    Problem: 4538
    User: typhigh
    Language: C++
    Result: Accepted
    Time:13788 ms
    Memory:40092 kb
****************************************************************/
 
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
vector<int> G[MAXN];
int n, m, dep[MAXN], vis[MAXN], dfs_clock, ss, dfsL[MAXN], dfsR[MAXN], fa[MAXN];
int ST[MAXN][20], Log2[MAXN];
 
void addEdge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}
 
void DFS(int u) {
    dfsL[u] = ++dfs_clock;
    vis[u] = ++ss;
    ST[ss][0] = u;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (fa[u] == v) continue;
        dep[v] = dep[u] + 1;
        fa[v] = u;
        DFS(v);
        ST[++ss][0] = u;
    }
    dfsR[u] = dfs_clock;
}
 
int Min(int x, int y) {
    return dep[x] < dep[y] ? x : y;
}
 
void buildST() {
    Log2[1] = 0;
    for (int i = 2; i <= ss; ++i) Log2[i] = Log2[i>>1] + 1;
    for (int j = 1; j <= Log2[ss]; ++j) 
        for (int i = 1; i + (1<<j) -1 <= ss; ++i) 
            ST[i][j] = Min(ST[i][j-1], ST[i+(1<<j-1)][j-1]);
}
 
int queryMin(int x, int y) {
    int l = vis[x], r = vis[y];
    if (l > r) swap(l, r);
    int k = Log2[r-l+1];
    return Min(ST[l][k], ST[r-(1<<k)+1][k]);
}
 
int BIT[MAXN];
void updateBIT(int x, int d) {
    for (; x <= n; x += x & -x) BIT[x] += d;
}
 
int queryBIT(int x) {
    int ret = 0;
    for (; x ; x -= x & -x) ret += BIT[x];
    return ret;
}
 
struct Query {
    int op, x, y, c, id, ans;
    bool operator < (const Query& rhs) const {
        return id < rhs.id;
    }
} q[MAXN], tmp[MAXN];
 
int Ask(int x) {
    int L = dfsL[x], R = dfsR[x];
    return queryBIT(R) - queryBIT(L-1);
}
 
void Update(int x, int y, int op) {
    updateBIT(dfsL[x], op);
    updateBIT(dfsL[y], op);
    int lca = queryMin(x, y);
    updateBIT(dfsL[lca], -op);
    if (fa[lca]) updateBIT(dfsL[fa[lca]], -op);
}
 
void CDQ(int L, int R, int l, int r) {
    if (L > R) return;
    int mid = l + (r - l) / 2;
    if (l == r) {
        for (int i = L; i <= R; ++i) 
            if (q[i].op == 2) q[i].ans = mid;
        return;
    }
 
    int num = 0;
    int qq = L-1, tt = 0;
    for (int i = L; i <= R; ++i) {
        if (q[i].op == 2) {
            if (Ask(q[i].x) == num) q[++qq] = q[i];
            else  tmp[++tt] = q[i];
        } else {
            int op = q[i].op == 0 ? 1 : -1;
            if (q[i].c <= mid) {
                q[++qq] = q[i];
            } else {
                tmp[++tt] = q[i];
                num += op;
                Update(q[i].x, q[i].y, op);
            }
        }
    }
    assert(qq + tt == R);
    for (int i = 1; i <= tt; ++i) {
        if (tmp[i].op != 2) {
            Update(tmp[i].x, tmp[i].y, - (tmp[i].op == 0 ? 1 : -1));
        }
    }
    for (int i = 1; i <= tt; ++i) q[i+qq] = tmp[i];
     
    CDQ(L, qq, l, mid);
    CDQ(qq+1, R, mid+1, r);
}
 
void solve() {
    dep[1] = fa[1] = 0;
    DFS(1);
//    for (int i = 1; i <= ss; ++i) cout << ST[i][0] << " \n"[i==ss];
    buildST();  
    int r = -1;
    for (int i = 1; i <= m; ++i) 
        if (q[i].op != 2) r = max(r, q[i].c);
    CDQ(1, m, -1, r);
    sort(q+1, q+m+1);
    for (int i = 1; i <= m; ++i) if (q[i].op == 2) {
        printf("%d\n", q[i].ans);
    }
}
 
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }  
    for (int i = 1; i <= m; ++i) {
        q[i].id = i;
        int op;
        scanf("%d", &op);
        q[i].op = op;
        if (op == 0) {
            scanf("%d %d %d", &q[i].x, &q[i].y, &q[i].c);
        } else if (op == 1) {
            int t;
            scanf("%d", &t);
            q[i].x = q[t].x;
            q[i].y = q[t].y;
            q[i].c = q[t].c;
        } else {
            scanf("%d", &q[i].x);
        }
    }
    solve();
}