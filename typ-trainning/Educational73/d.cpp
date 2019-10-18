#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF64 = (1LL << 60);
const int MAXN = 500010;
int n, a[MAXN], b[MAXN];
LL dp[MAXN][3];


int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) 
			scanf("%d %d", a+i, b+i);
		//memset(dp, INF32, sizeof(dp));
		for (int i = 0; i <= n; ++i) dp[i][0] = dp[i][1] = dp[i][2] = INF64;	
		dp[0][0] = 0;
		a[0] = b[0] = 0;
		for (int i = 1; i <= n; ++i)
			for (int k = 0; k < 3; ++k) 
				for (int j = 0; j < 3; ++j) 
					if (a[i]+k != a[i-1]+j)
						dp[i][k] = min(dp[i][k], dp[i-1][j] + b[i]*k);
		LL ans = min(min(dp[n][0], dp[n][1]), dp[n][2]);
		cout << ans << endl;
	}
}
