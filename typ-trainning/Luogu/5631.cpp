#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000100;
const int MAXW = 100100;
int read(){
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9') ch=='-'&&(f=-1),ch=getchar();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int n, m, top, fa[MAXN], st[MAXN], sz[MAXN];

int find(int x) {
    return x == fa[x] ? x : find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    st[++top] = y;
    fa[y] = x, sz[x] += sz[y];
}

void undo(int pos) {
    while (top > pos) {
        int x = st[top--];
        sz[fa[x]] -= sz[x];
        fa[x] = x; 
    }
}
pair<int, int> edges[MAXN];

/**/
vector<int> es[(MAXW+10)<<2];
void segUpdate(int id, int l, int r, int L, int R, int eid) {
    if (L <= l && r <= R) {
        es[id].push_back(eid);
        return;
    }
    int mid = (l+r) >> 1;
    if (L <= mid) segUpdate(id<<1, l, mid, L, R, eid);
    if (R >= mid+1) segUpdate(id<<1|1, mid+1, r, L, R, eid);
}

int ans;
void solve(int id, int l, int r) {
    int tmp = top;
    for (int i = 0; i < es[id].size(); ++i) {
        pair<int, int>& e = edges[es[id][i]];
        merge(e.first, e.second);
    }
    if (l == r) {
        if (sz[find(1)] == n) ans = min(ans, l);
    } else {
        int mid = (l+r)>>1;
        solve(id<<1, l, mid);
        solve(id<<1|1, mid+1, r);
    }
    undo(tmp);
}
int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;
    for (int i = 0; i < m; ++i) {
        int u = read(), v = read(), w = read();
        edges[i].first = u;
        edges[i].second = v;
        if (w > 0) segUpdate(1, 0, MAXW, 0, w-1, i);
        if (w < MAXW) segUpdate(1, 0, MAXW, w+1, MAXW, i);
    }
    ans = MAXW+1;
    solve(1, 0, MAXW);
    printf("%d\n", ans);
}