#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 998244353;
const int MAXN = 4010;
int n, m, t, fac[MAXN], inv[MAXN];
LL dp[2][MAXN][MAXN];
bool vis[2][MAXN];

LL quick_pow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD; 
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

LL A(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return 1LL * fac[n] * inv[n-m] % MOD; 
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; ++i) fac[i] = 1LL * fac[i-1] * i % MOD;
    inv[MAXN-1] = quick_pow(fac[MAXN-1], MOD-2);
    for (int i = MAXN-2; i >= 0; --i) inv[i] = 1LL * inv[i+1] * (i+1) % MOD;
    assert(inv[0] == 1);
}

void add(LL &x, LL d) {
    x += d;
    if (x >= MOD || -x >= MOD) x %= MOD;
}

void DP(int dim, LL d[MAXN][MAXN]) {
    int Len = dim == 0 ? n : m;
    d[0][0] = 1;
    for (int k = 0; k <= Len/2; ++k) {
        for (int i = 1; i <= Len; ++i) {
            d[i][k] = d[i-1][k];
            if (!vis[dim][i] && !vis[dim][i-1] && k) add(d[i][k], d[i-2][k-1]);
        }
    }
}

LL solve() {
    int cntx = 0, cnty = 0;
    vis[0][0] = vis[1][0] = true;
    for (int i = 1; i <= n; ++i) cntx += !vis[0][i];
    for (int i = 1; i <= m; ++i) cnty += !vis[1][i];
    DP(0, dp[0]);
    DP(1, dp[1]);
//    cout << dp[0][n][1] << " " << dp[1][m][1] << endl;
    LL ans = 0;
    for (int i = 0; i <= n/2; ++i) {
        for (int j = 0; j <= m/2; ++j) {
            if (!dp[0][n][i] || !dp[1][m][j]) continue;
//            cout << i << " " << j << " " << dp[0][n][i] << " " << dp[1][m][j] << endl;
            add(ans, dp[0][n][i] * dp[1][m][j] % MOD * A(cntx - i*2, j) % MOD * A(cnty - j*2, i) % MOD);
        }
    }
    ans = (ans % MOD + MOD) % MOD;
    return ans;
}

int main() {
    init();
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < 2; ++j) {
            int u, v;
            scanf("%d %d", &u, &v);
            vis[0][u] = vis[1][v] = true;
        }
    }
    cout << solve() << endl;
}