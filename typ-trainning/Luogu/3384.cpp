#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
typedef long long LL;
LL MOD;
LL lazy[MAXN<<2], sum[MAXN<<2], wt[MAXN];

void pushDown(int id, int l, int r) {
    if (lazy[id]) {
        int mid = l + (r - l) / 2;
        sum[id<<1] += (mid - l + 1) * lazy[id];
        sum[id<<1|1] += (r - mid) * lazy[id];
        lazy[id<<1] += lazy[id];
        lazy[id<<1|1] += lazy[id];
        lazy[id] = 0;
        sum[id<<1] %= MOD;
        sum[id<<1|1] %= MOD;
    }
}

void pushUp(int id) {
    sum[id] = sum[id<<1] + sum[id<<1|1];
}

void segBuild(int id, int l, int r) {
    if (l == r) {
        lazy[id] = 0;
        sum[id] = wt[l];
        return;
    }
    int mid = l + (r - l) / 2;
    segBuild(id<<1, l, mid);
    segBuild(id<<1|1, mid+1, r);
    pushUp(id);
}

LL segQuery(int id, int l, int r, int L, int R) {
//    cout << id << " " << l << " " << r << " " << L << " " << R << '\n';
    if (L <= l && r <= R) {
        return sum[id];
    }
    int mid = l + (r - l) / 2;
    pushDown(id, l, r);
    LL ret = 0;
    if (L <= mid) ret += segQuery(id<<1, l, mid, L, R);
    if (R >= mid+1) ret += segQuery(id<<1|1, mid+1, r, L, R);
    pushUp(id);
    return ret;
}

void segAdd(int id, int l, int r, int L, int R, LL d) {
    if (L <= l && r <= R) {
        sum[id] += 1LL * (r - l + 1) * d % MOD;
        lazy[id] += d;
        return;
    }
    pushDown(id, l, r);
    int mid = l + (r - l) / 2;
    if (L <= mid) segAdd(id<<1, l, mid, L, R, d);
    if (R >= mid+1) segAdd(id<<1|1, mid+1, r, L, R, d);
    pushUp(id);
}

/******/

vector<int> G[MAXN];
int n, m, r, dep[MAXN], top[MAXN], fa[MAXN], son[MAXN], w[MAXN], sz[MAXN], id[MAXN];
int tot;
void dfs1(int u) {
    sz[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u]+1;
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
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

void AddOp1(int x, int y, int z) {
    z %= MOD;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        segAdd(1, 1, n, id[top[x]], id[x], z);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    segAdd(1, 1, n, id[x], id[y], z);
}

int QueryOp2(int x, int y) {
    LL ret = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ret += segQuery(1, 1, n, id[top[x]], id[x]);
        ret %= MOD;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    ret = (ret % MOD + segQuery(1, 1, n, id[x], id[y])) % MOD;
    return (int) ret;
}

void AddOp3(int x, int z) {
    z %= MOD;
    segAdd(1, 1, n, id[x], id[x]+sz[x]-1, z);
}

int QueryOp4(int x) {
    LL ret = segQuery(1, 1, n, id[x], id[x] + sz[x] -1);
    ret = (ret % MOD + MOD) % MOD;
    return ret;
}

int main() {
    cin >> n >> m >> r >> MOD;
    for (int i = 1; i <= n; ++i) scanf("%d", w+i);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dep[r] = fa[r] = 0;
    dfs1(r);
    dfs2(r, r);
//    for (int i = 1; i <= n; ++i) {cout << id[i] << " " << top[i] << " " << sz[i] << " " << dep[i] << endl;}
    segBuild(1, 1, n);
    while (m--) {
        int op, x, y, z;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d %d", &x, &y, &z);
            AddOp1(x, y, z);
        } else if (op == 2) {
            scanf("%d %d", &x, &y);
            printf("%d\n", QueryOp2(x, y));
        } else if (op == 3) {
            scanf("%d %d", &x, &z);
            AddOp3(x, z);
        } else if (op == 4) {
            scanf("%d", &x);
            printf("%d\n", QueryOp4(x));
        }
    }
}