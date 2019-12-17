#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
pair<int, int> edges[MAXN];
int n, m, k;
int fa[MAXN], sz[MAXN];
int top, st[MAXN];
int find(int x) {
    return x == fa[x] ? x : find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    fa[y] = x, sz[x] += sz[y];
    st[++top] = y;
}

void undo(int tmp) {
    while (top > tmp) {
        int x = st[top--];
        sz[fa[x]] -= sz[x];
        fa[x] = x;
    }
} 

vector<int> es[MAXN<<1];
void segAdd(int id, int l, int r, int L, int R, int eid) {
    if (L <= l && r <= R) {
        es[id].push_back(eid);
        return ;
    }
    int mid = (l+r) >> 1;
    if (L <= mid) segAdd(id<<1, l, mid, L, R, eid);
    if (R >= mid+1) segAdd(id<<1|1, mid+1, r, L, R, eid);
}

void DFS(int id, int l, int r) {
    int tmp = top;
    for (int i = 0; i < es[id].size(); ++i) {
        int eid = es[id][i];
        merge(edges[eid].first, edges[eid].second);
    }

    if (l == r) {
        if (sz[find(1)] == n) {
            puts("Connected");
        } else {
            puts("Disconnected");
        }
    } else {
        int mid = (l+r) >> 1;
        DFS(id<<1, l, mid);
        DFS(id<<1|1, mid+1, r);
    }
    undo(tmp);
}

int Prev[MAXN];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[i] = make_pair(u, v);
    }   
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
        int c;
        scanf("%d", &c);
        while (c--) {
            int eid;
            scanf("%d", &eid);
            int L = Prev[eid];
            if (L + 1 <= i - 1) {
                segAdd(1, 1, k, L + 1, i - 1, eid);
            }
            Prev[eid] = i;
        }
    }
//    puts("!");
    for (int i = 1; i <= m; ++i) {
        if (Prev[i] + 1 <= k) segAdd(1, 1, k, Prev[i]+1, k, i);
    }
    DFS(1, 1, k);
}