#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100100;
int n, m, r, nowr, tot, dep[MAXN], sz[MAXN], top[MAXN], id[MAXN], fa[MAXN][20], son[MAXN];
LL w[MAXN], wt[MAXN];
vector<int> G[MAXN];

/***/
LL a[MAXN<<2], lazy[MAXN<<2];
void pushDown(int id) {
    if (lazy[id]) {
        //0 is unable
        lazy[id<<1] = lazy[id<<1|1] = lazy[id];
        a[id<<1] = a[id<<1|1] = lazy[id];
        lazy[id] = 0;
    }
}

void pushUp(int id) {
    a[id] = min(a[id<<1], a[id<<1|1]);
}

void segBuild(int id, int l, int r) {
    if (l == r) {
        a[id] = wt[l];
        lazy[id] = 0;
        return;
    }
    int mid = l + (r - l) / 2;
    segBuild(id<<1, l, mid);
    segBuild(id<<1|1, mid+1, r);
    pushUp(id);
}

void segUpdate(int id, int l, int r, int L, int R, LL d) {
    if (L <= l && r <= R) {
        lazy[id] = a[id] = d;
        return;
    }
    pushDown(id);
    int mid = l + (r - l) / 2;
    if (L <= mid) segUpdate(id<<1, l, mid, L, R, d);
    if (R >= mid+1) segUpdate(id<<1|1, mid+1, r, L, R, d);
    pushUp(id);
}

LL segQuery(int id, int l, int r, int L, int R) {
    if (L <= l && r <= R) return a[id];
    int mid = l + (r - l) / 2;
    pushDown(id);
    LL ans = 1LL << 60;
    if (L <= mid) ans = min(ans, segQuery(id<<1, l, mid, L, R));
    if (R >= mid+1) ans = min(ans, segQuery(id<<1|1, mid+1, r, L, R));
    pushUp(id);
    return ans;
}

/**/
void dfs1(int u) {
    sz[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v == fa[u][0]) continue;
        dep[v] = dep[u] + 1;
        fa[v][0] = u;
        dfs1(v);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v]) son[u] = v;
    }
}

void dfs2(int u, int topf) {
    id[u] = ++tot;
    wt[tot] = w[u];
    top[u] = topf;
    if (!son[u]) return;
    dfs2(son[u], topf);
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v == fa[u][0] || v == son[u]) continue;
        dfs2(v, v);
    } 
}

/*OP*/ 

void updateOp2(int x, int y, LL v) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        segUpdate(1, 1, n, id[top[x]], id[x], v);
        x = fa[top[x]][0];
    }
    if (dep[x] < dep[y]) swap(x, y);
    segUpdate(1, 1, n, id[y], id[x], v);
}

int LCA(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]][0];
    }
    if (dep[x] < dep[y]) return x;
    return y;
}

void buildFa() {
    for (int j = 1; j < 20; ++j) 
        for (int i = 1; i <= n; ++i) fa[i][j] = fa[fa[i][j-1]][j-1];
}

int jump(int x, int step) {
    for (int i = 0; i < 20; ++i) {
        if ((step >> i) & 1) x = fa[x][i];
    }
    return x;
}

LL queryOp3(int x) {
    if (x == nowr) {
        return segQuery(1, 1, n, 1, n);
    }
    LL ret;
    int lca = LCA(x, nowr);
    if (lca != x) {
        ret = segQuery(1, 1, n, id[x], id[x] + sz[x]-1);
    }  else {
        int v = jump(nowr, dep[nowr] - dep[x] - 1);
        ret = 1LL << 60;
        if (id[v]-1 >= 1 ) ret = min(ret, segQuery(1, 1, n, 1, id[v]-1));
        if (id[v]+sz[v] <= n) ret = min(ret, segQuery(1, 1, n, id[v]+sz[v], n));        
    }
    return ret;
}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) scanf("%lld", w+i);
    dep[r] = fa[r][0] = 0;
    scanf("%d", &r);
    dfs1(r);
    dfs2(r, r);
    buildFa();
    segBuild(1, 1, n);    
    nowr = r;
    for (int i = 0; i < m; ++i) {
        int opt, x, y;
        LL v;
        scanf("%d", &opt);
        if (opt == 1) {
            scanf("%d", &x);
            nowr = x;
        } else if (opt == 2) {
            scanf("%d %d %lld", &x, &y, &v);
            updateOp2(x, y, v);
        } else {
            scanf("%d", &x);
            printf("%lld\n", queryOp3(x));
        }
    }
}

/*‭
3 2
1 2
1 3
2147483648‬ 2147483648‬ 1
3 1
3 3
*/

/*
3 7
1 2
1 3
1 2 3
1
3 1
2 1 1 6
3 1
2 2 2 5
3 1
2 3 3 4
3 1
*/