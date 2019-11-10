#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200;
const int INF32 = 0x3f3f3f3f;
int n, k, a[MAXN];
int dp[MAXN][MAXN];
int sum[MAXN][MAXN];
void init() {
    for (int i = 1; i <= n; ++i) {
        sum[i][i] = 1;
        map<int, int> cnt;
        cnt[a[i]]++;
        int maxv = 1;
        for (int j = i+1; j <= n; ++j) {
            int now = ++cnt[a[j]];
            if (now > maxv) 
                maxv = now;
            sum[i][j] = maxv;
        }
    }
}
int main() {
    int T, kase = 0;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        init();
        for (int t = 1; t <= k+1; ++t) {
            for (int i = 1; i <= n; ++i) { 
                dp[i][t] = INF32;
                if (t >= 2) dp[i][t] = dp[i][t-1];
                
                if (t == 1) dp[i][t] = i - sum[1][i];
                else {
                    for (int j = 1; j < i; ++j) 
                        dp[i][t] = min(dp[i][t], dp[j][t-1] + (i-j) - sum[j+1][i]);
                }
            }
        }
        cout << "Case #" << (++kase) << ": " << dp[n][k+1] << endl;
    }
}