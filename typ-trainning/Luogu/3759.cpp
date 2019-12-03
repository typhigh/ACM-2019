#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int RANK = 50010;
const LL MOD = 1e9 + 7;
const int N = 256 * RANK;
int n, m, rk[RANK], sum[RANK];
int tot, root[N], ch[N][2];
int cnt[N];
LL sz[N];
queue<int> nodes;

void Add(pair<int, LL>& x, pair<int, LL> d) {
    x.first += d.first;
    x.second += d.second;
    if (x.second <= -MOD || x.second >= MOD) x.second %= MOD;
}

int newNode() {
    if (nodes.empty()) return ++tot;
    int ret = nodes.front();
    nodes.pop();
    return ret;
}

void destroy(int& id) {
    ch[id][0] = ch[id][1] = cnt[id] = sz[id] = 0;
    nodes.push(id);
    id = 0; 
}

void add(int &id, int l, int r, int pos, int a1, LL a2) {
    if (!id) id = newNode();
    cnt[id] += a1;
    sz[id] = (sz[id] + a2) % MOD;
    if (l == r) {
        if (!cnt[id]) destroy(id);
        return;
    }
    int mid = l + (r-l) / 2;
    if (pos <= mid) add(ch[id][0], l, mid, pos, a1, a2);
    else add(ch[id][1], mid+1, r, pos, a1, a2);
    if (!cnt[id]) destroy(id);
} 

pair<int, LL> Query(int id, int l, int r, int L, int R) {
//    cout << id << " " << l << " " << r << " " << L << " " << R << endl;
    if (l > r || L > R || !id) return make_pair(0, 0);
    if (L <= l && r <= R) return make_pair(cnt[id], sz[id]);
    int mid = l + (r - l) / 2;
    pair<int, LL> ret = make_pair(0, 0LL);
    if (L <= mid) Add(ret, Query(ch[id][0], l, mid, L, R));
    if (R >= mid+1) Add(ret, Query(ch[id][1], mid+1, r, L, R));
    return ret;
}
//
void insert(int id, int l, int r, int pos, int rk, LL a2) {
    add(root[id], 1, RANK, rk, 1, a2);
    if (l == r) return;
    int mid = l + (r - l) / 2;
    if (pos <= mid) insert(id<<1, l, mid, pos, rk, a2);
    else insert(id<<1|1, mid+1, r, pos, rk, a2);
}

void del(int id, int l, int r, int pos, int rk, LL a2) {
    add(root[id], 1, RANK, rk, -1, -a2);
    if (l == r) return;
    int mid = l + (r - l) / 2;
    if (pos <= mid) del(id<<1, l, mid, pos, rk, a2);
    else del(id<<1|1, mid+1, r, pos, rk, a2);
}

pair<int, LL> query(int id, int l, int r, int L, int R, int Lval, int Rval) {
    if (l > r || L > R || Lval > Rval) return make_pair(0, 0);
    if (L <= l && r <= R) return Query(root[id], 1, RANK, Lval, Rval); 
    int mid = l + (r - l) / 2;
    pair<int, LL> ret = make_pair(0, 0LL);
    if (mid >= L) Add(ret, query(id<<1, l, mid, L, R, Lval, Rval));
    if (mid +1 <= R) Add(ret, query(id<<1|1, mid+1, r, L, R, Lval, Rval));
    return ret;
}

void Out(LL x) {
    x = (x % MOD + MOD) % MOD;
    printf("%d\n", (int)x);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d %d", rk+i, sum+i);
    for (int i = 1; i <= n; ++i) insert(1, 1, n, i, rk[i], sum[i]);
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        pair<int, LL> cur = query(1, 1, n, i+1, n, 1, rk[i]);
//        cout << cur.first << " " << cur.second << endl;
        ans += 1LL * cur.first * sum[i] + cur.second;
        ans %= MOD;
    }

    while (m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x > y) swap(x, y);
        if (x == y) {
            Out(ans);
            continue;    
        }

        int minrk = min(rk[x], rk[y]);
        int maxrk = max(rk[x], rk[y]);
        pair<int, LL> cur = query(1, 1, n, x, y, minrk+1, maxrk-1);
        LL tmp = 2 * cur.second + 1LL * (cur.first + 1) * (sum[x] + sum[y]) % MOD;
        tmp %= MOD;
        if (minrk == rk[x]) ans += tmp;
        else ans -= tmp;
        ans %= MOD;

        cur = query(1, 1, n, x, y, 1, minrk-1);
        ans = (1LL * (sum[y] - sum[x]) * cur.first % MOD + ans) % MOD;
        
        cur = query(1, 1, n, x, y, maxrk+1, n);
        ans = (1LL * (sum[x] - sum[y]) * cur.first % MOD + ans) % MOD;

        Out(ans);
        del(1, 1, n, x, rk[x], sum[x]);
        del(1, 1, n, y, rk[y], sum[y]);
        insert(1, 1, n, x, rk[y], sum[y]);
        insert(1, 1, n, y, rk[x], sum[x]);
        swap(rk[x], rk[y]);
        swap(sum[x], sum[y]);
    }
}
/*
1 2 3 4 5 6
6 2 5 4 3 1
5 *6 + 15 + 4 + 14 + 5*2 + 4 + 3 + 4 + 3 = 30 + 15 + 18 + 10 + 14 = 87
*/