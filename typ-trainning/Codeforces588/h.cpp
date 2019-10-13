#include <bits/stdc++.h>
using namespace std;
const int MAXN = 7;
const int MOD = 1e9 + 7;
const int E100 = 570000004;
typedef long long LL;
int n, g[MAXN][MAXN];
LL nxt[1<<MAXN][1<<MAXN];
int bitcnt[1<<MAXN];

vector<int> S[MAXN+1];
int id[1<<MAXN];
map<LL, int> dp[MAXN]; 
int solve(int i, LL msk) {
	if (msk == 0) return 0;
	if (i == n) return 1;
	if (dp[i].count(msk)) return dp[i][msk];
	LL ret = 0;
	for (int s = 0; s < (1<<n); ++s) {
		LL p = 1;
		for (int j = 0; j < n; ++j) 
			if (s & (1 << j)) p = g[i][j] * p % MOD;
			else p = (1 - g[i][j]) * p % MOD;
		LL nmsk = 0;
		for (int j = 0; j < 35; ++j) if ((1LL << j) & msk) nmsk |= nxt[s][S[i][j]];
		ret = ret + p * solve(i+1, nmsk);
		ret %= MOD;
	}
	return dp[i][msk] = ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) { 
			scanf("%d", &g[i][j]);
			g[i][j] = g[i][j] * 1LL * E100 % MOD;
		}
	for (int i = 1; i < (1<<n); ++i) 
		bitcnt[i] = bitcnt[i ^ (i & -i)] + 1;
	for (int i = 0; i < (1<<n); ++i) {
		id[i] = S[bitcnt[i]].size();
		S[bitcnt[i]].push_back(i);
	}
	for (int i = 1; i < (1<<n); ++i) 
		for (int j = 0; j < (1<<n); ++j) 
			for (int k = 0; k < n; ++k) 
				if ((i & (1<<k)) && !(j & (1<<k)))
					nxt[i][j] |= 1LL << id[j|1<<k];
	int ans = solve(0, 1);
	ans = (ans % MOD + MOD) % MOD;
	cout << ans << endl;
}
