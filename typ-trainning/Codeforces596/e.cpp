#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;
const int MAXN = 2010;
int n, m;

LL sum[MAXN][MAXN][2], d[MAXN][MAXN][2], f[MAXN][MAXN][2];
char s[MAXN][MAXN];
void init() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum[i][j][0] = sum[i][j-1][0] + (s[i][j] == 'R');
            sum[i][j][1] = sum[i-1][j][1] + (s[i][j] == 'R');
        }
    }
}

void add(LL& x, LL d) {
    x += d;
    if (x >= MOD || x <= -MOD) x %= MOD;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%s", s[i]+1);
    init();
    int tmp = sum[1][m][0];
    add(d[1][1][0], 1);
    add(d[1][m-tmp+1][0], -1);
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            f[x][y][0] = f[x][y-1][0] + d[x][y][0];
            f[x][y][1] = f[x-1][y][1] + d[x][y][1];
            int cnt = sum[n][y][1] - sum[x][y][1];
            add(d[x+1][y][1], f[x][y][0]);
            add(d[n-cnt+1][y][1], -f[x][y][0]);
            cnt = sum[x][m][0] - sum[x][y][0];
            add(d[x][y+1][0], f[x][y][1]);
            add(d[x][m-cnt+1][0], -f[x][y][1]);
        }
    }
    LL ans = f[n][m][0] + f[n][m][1];
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << endl;
} 