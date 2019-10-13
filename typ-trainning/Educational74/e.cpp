#include <bits/stdc++.h>
using namespace std;
const int MAXM = 20;
const int MAXN = 100010;
const int INF32 = 0x3f3f3f3f;

int n, m;
int dp[1<<MAXM], bc[1<<MAXM], g[MAXM][MAXM];
char s[MAXN];

int main() {
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	for (int i = 1; i < n; ++i) 
		if (s[i-1] != s[i]) ++g[s[i-1]-'a'][s[i]-'a'];
	int S0 = (1 << m);
	memset(dp, INF32, sizeof(dp));
	dp[0] = 0;
	for (int s = 0; s < S0 - 1; ++s) {
		if (s) bc[s] = bc[s ^ (s & -s)] + 1;
		for (int i = 0; i < m; ++i) if (!((1 << i) & s)) {
			int d = 0;
			for (int j = 0; j < m; ++j) 
				if ((1 << j) & s) d += (g[i][j] + g[j][i]) * bc[s];
				else d -= (g[i][j] + g[j][i]) * bc[s];
			dp[s | (1<<i)] = min(dp[s|(1<<i)], dp[s] + d);
		}
	}
	cout << dp[(1<<m)-1] << endl;
}
