#include <bits/stdc++.h>
using namespace std;
const int MAXN = 81;
const int INF = 0x3f3f3f3f;
const int MAXM = 100010;
int n, m, dp[2][MAXM];

pair<int, int> p[MAXN];
void update(int& x, int d) {
//    cout << x << '\n';
    x = min(x, d);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &p[i].first, &p[i].second);
    }
    p[++n] = make_pair(++m, 0);
    sort(p+1, p+n+1);
    memset(dp, 0x3f, sizeof(dp));
    int t = 0;
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        memset(dp[t^1], INF, sizeof(dp[t^1]));
        for (int j = 0; j <= m; ++j) {
            if (dp[t][j] >= INF) continue;
            update(dp[t^1][j], dp[t][j]);
            auto c = p[i+1];
            if (c.first - c.second <= j + 1) update(dp[t^1][max(j, min(m,c.first+c.second))], dp[t][j]);
            else {
                int x = -(j + 1 - c.first + c.second);
                update(dp[t^1][min(m, max(j, x+c.first+c.second))], dp[t][j] + x);
            }
        }
        t ^= 1;
    }
    printf("%d\n", dp[t][m]);
}