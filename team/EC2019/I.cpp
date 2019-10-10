#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 105;
LL dp[2][MAXN][MAXN*MAXN];
int n, a[MAXN], b[MAXN], c[MAXN];

void update(LL &x, LL d) {
	x = max(x, d);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d %d %d", a + i, b + i, c + i);
		LL ans = 0;
		int t = 0;
		memset(dp, 0, sizeof(dp));
		for (int day = 1; day <= n; ++day) {
			memset(dp[t^1], 0, sizeof(dp[t^1]));
			for (int cnt = 0; cnt <= n; ++cnt) {
				for (int sum = 0; sum <= n * n; ++sum) {
					if (cnt && sum >= cnt - 1) update(dp[t^1][cnt-1][sum-cnt+1], dp[t][cnt][sum] + a[day]);
					if (sum >= cnt) {
						update(dp[t^1][cnt][sum-cnt], dp[t][cnt][sum] + 1LL * c[day] * cnt);
						update(dp[t^1][cnt][sum-cnt], dp[t][cnt][sum] + 1LL * b[day] * sum);
					}
				}
			}
			t ^= 1;
		}
		cout << dp[t][0][0] << endl;
	}
}
