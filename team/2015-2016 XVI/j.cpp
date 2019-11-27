#include <bits/stdc++.h>
using namespace std;
const int N = 101;
const int MAXN = 1000100;
int n, dp[MAXN][2], a[N][2], lim[2];
bitset<N> way[MAXN][2];
int main() {
    scanf("%d", &n);
    scanf("%d", lim+0);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i][0]);
    scanf("%d", lim+1);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i][1]);
    for (int t = 0; t < 2; ++t) {
        for (int i = 1; i <= n; ++i) {
            for (int j = lim[t]-1; j >= a[i][t]; --j) {
                if (dp[j-a[i][t]][t] + a[i][t^1] > dp[j][t]) {
                    dp[j][t] = dp[j-a[i][t]][t] + a[i][t^1];
                    way[j][t] = way[j-a[i][t]][t];
                    way[j][t].set(i);
                    if (dp[j][t] >= lim[t^1]) {
                        puts("NO");
                        for (int k = 1; k <= n; ++k) cout << way[j][t][k];
                        puts("\n");
                        return 0; 
                    } 
                }
            }
        }
    }
    puts("YES");
}