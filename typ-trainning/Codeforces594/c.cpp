#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int MAXN = 100010;
int n, m;
LL dp[MAXN][4];
void add(LL& x, LL d) {
    x += d;
    if (x >= MOD || -x >= MOD) x %= MOD; 
}
int main() {
    scanf("%d %d", &n, &m);
    if (n < m) swap(n, m);
    dp[1][1] = 1; //01
    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s < 4; ++s) {
            int now = s & 1;
            int prev = (s >> 1) & 1;
            add(dp[i+1][now<<1|(now^1)], dp[i][s]);
            if (now != prev) add(dp[i+1][now<<1|now], dp[i][s]);
        }
    } 
    LL ans = (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3]) % MOD;
    ans = ans - 1 + dp[m][0] + dp[m][1] + dp[m][2] + dp[m][3];
    ans %= MOD;
    ans = (ans * 2 % MOD + MOD) % MOD;
    cout << ans << endl;
}