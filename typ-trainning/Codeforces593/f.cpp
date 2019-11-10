#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 500010;
const int MOD = 1e9 + 7;
const LL inv2 = 5e8 + 4;
vector<int> G[MAXN];
int n, m, vis[MAXN];
LL two[MAXN], inv[MAXN];

void init() {
    two[0] = inv[0] = 1;
    for (int i = 1; i < MAXN; ++i) two[i] = two[i-1] * 2 % MOD, inv[i] = inv[i-1] * inv2 % MOD;
}

int st[MAXN], id[MAXN], p;
vector<vector<int>> cirs;
vector<int> in[MAXN];

void DFS(int u, int fa) {
    vis[u] = 1;
    st[id[u] = ++p] = u;
    for (int v : G[u]) {
        if (v == fa) continue;
        if (vis[v] == 2) continue;
        if (vis[v]) {
            vector<int> tmp;
            for (int i = p; i >= id[v]; --i) tmp.push_back(st[i]);
            cirs.push_back(tmp);
        } else {
            DFS(v, u);
        }
    }
    vis[u] = 2;
    st[p--] = 0;
}

LL sum(LL a, LL b) {
//    a %= MOD;
//    b %= MOD;
    if (a + b >= MOD) return a + b - MOD;
    return a + b;
}

LL sub(LL a, LL b) {
    if (a > b) return a - b;
    return a - b + MOD;
}

LL mul(LL a, LL b) {
//    a %= MOD;
//    b %= MOD;
    return a * b % MOD;
}

LL Ver2() {
    LL ret = sum(mul(mul(n, n-1), inv[2]), mul(n, inv[1]));
//    cout << "Ver2 " << ret << endl;
    return ret;
}

LL Edge2() {
    LL ret = mul(m, inv[2]);
    for (int x = 1; x <= n; ++x) {
        for (int y : G[x]) {
            if (x < y) continue;
            int in = G[x].size() + G[y].size() - 2;
            int out = m - in - 1;
            ret = sum(ret, mul(in, inv[3]));
            ret = sum(ret, mul(out, inv[4]));
        }
    }
//    cout << "Edge2 " << ret << endl;
    return ret;
}

LL Cir2() {
    LL ret = 0, tmp = 0;
    for (auto cir : cirs) tmp = sum(tmp, inv[cir.size()]);
    for (auto cir : cirs) {
        LL siz = cir.size(), val = tmp;
        ret = sum(ret, inv[siz]);
        for (int x: cir) {
            for (int t: in[x]) val = sub(val, inv[t]);
            val = sum(val, inv[siz]);
        } 
        val = sub(val, inv[siz]);
        ret = sum(ret, mul(inv[siz], val));
        val = sub(sub(tmp, val), inv[siz]);
        ret = sum(ret, mul(mul(inv[siz], 2), val));
    } 
//    cout << "Cir2 " << ret << endl; 
    return ret;
}

LL VerEdge() {
    LL ret = 0;
    for (int x = 1; x <= n; ++x) {
        int e = G[x].size();
        ret = sum(ret, mul(e, inv[2]));
        ret = sum(ret, mul(m-e, inv[3]));
    }
//    cout << "VerEdge " << ret << endl;
    return ret;
}

LL VerCir() {
    LL ret = 0, tmp = 0;
    for (auto cir: cirs) tmp = sum(tmp, inv[cir.size()]);
    for (int x = 1; x <= n; ++x) {
        LL val = tmp;
        for (int s: in[x]) val = sum(val, inv[s]);
        ret = sum(ret, mul(val, inv[1]));
    }
//    cout << "VerCir " << ret << endl;
    return ret;
}

LL EdgeCir() {
    LL ret = 0;
    for (auto cir : cirs) {
        LL res = inv[cir.size()];
        LL val = cir.size();
        LL val2 = 0;
        for (int x: cir) val2 += G[x].size() - 2;
        LL val3 = m - val - val2;
        LL tmp = sum(val, sum(mul(val2, inv[1]), mul(val3, inv[2])));
        ret = sum(ret, mul(res, tmp)); 
    }
//    cout << "EdgeCir " << ret << endl;
    return ret;
}

LL calc1() {
    LL ret = sum(Ver2(), sum(Edge2(), Cir2()));
    LL res = sub(VerCir(), sum(VerEdge(), EdgeCir()));
    res = mul(res, 2);
    ret = sum(ret, res);
    return ret;
}

LL calc2() {
    LL ret = sub(mul(n, inv[1]), mul(m, inv[2]));
    for (auto cir: cirs) ret = sum(ret, inv[cir.size()]);
    ret = mul(ret, ret);
//    cout << ret << endl;
    return ret;
}

int main() {
    init();
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    DFS(1, 0);    
    for (auto &cir : cirs) for (int u: cir) in[u].push_back(cir.size());
    LL ans = (calc1() - calc2() + MOD) % MOD;
    cout << ans << endl;
}