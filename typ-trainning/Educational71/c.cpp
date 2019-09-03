#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200010;
char s[MAXN];
int n;
LL a, b;
LL dp[MAXN][2];

void update(LL& x, LL val) {
	x = min(x, val);
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		cin >> n >> a >> b;
		scanf("%s", s+1);
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0] = 0;
		dp[0][1] = a;
		for (int i = 1; i <= n; ++i) {
			update(dp[i][1], dp[i-1][1]+b);
			if (s[i] == '0') {
				update(dp[i][1], dp[i-1][0]+a);
				update(dp[i][0], dp[i-1][0]);
				update(dp[i][0], dp[i-1][1]+a+b);
			}
//			cout << i << ":" << dp[i][0] << " " << dp[i][1] << endl;
		}
		LL ans = dp[n][0]+n*a+(n+1)*b;
		// 8 * 2 + 9 * 5 = 61
		// dp 33 = 4 * 2 + 5 * 5
		cout << ans << endl;
	}
}
