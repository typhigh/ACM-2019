#include <cstdio>
#include <iostream>
#define N 1100
#define MOD 1000000007
using namespace std;
typedef long long ll;

char s[N][N];
int n, m, g[N][N][2];
ll f[N][N][2], c[N][N][2];

//0 hengzhe, 1 shuzhe

void add(ll &x, ll k) {
    x = (x + k) % MOD;
}

int main() {
    freopen("1.in", "r", stdin);
    cin >> n >> m;
    for (int i  = 1; i <= n; i ++) cin >> s[i] + 1;
    for (int i  = 1; i <= n; i ++)  
      for (int j = 1; j <= m; j ++) {
          g[i][j][0] = g[i][j - 1][0] + (s[i][j] == 'R');
          g[i][j][1] = g[i - 1][j][1] + (s[i][j] == 'R');
      }
    
    //cout << g[4][2][1] - g[2][2][1] << endl;
    int k = g[1][m][0];
    c[1][1][0] ++;
    c[1][m - k + 1][0] --;
    for (int i = 1; i <= n; i ++) {
      for (int j = 1; j <= m; j ++) {
        f[i][j][0] = (f[i][j - 1][0] + c[i][j][0]) % MOD;
        f[i][j][1] = (f[i - 1][j][1] + c[i][j][1]) % MOD;
        int k = g[n][j][1] - g[i][j][1];
        add(c[i + 1][j][1], f[i][j][0]); add(c[n - k + 1][j][1], -f[i][j][0]);
        k = g[i][m][0] - g[i][j][0];
        add(c[i][j + 1][0], f[i][j][1]); add(c[i][m - k + 1][0], -f[i][j][1]);
      }
     // cout << endl;
    }
    ll ans = (f[n][m][0] + f[n][m][1]) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
}