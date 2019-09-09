#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;

char s[MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

int DP(int x1, int y1, int x2, int y2) {
	if (vis[x1][y1][x2][y2]) return dp[x1][y1][x2][y2];
	vis[x1][y1][x2][y2] = true;
	int& d = dp[x1][y1][x2][y2];
	if (x1 == x2 && y1 == y2) 
		d = (s[x1][y1] == '#');
	else {
		d = max(x2 - x1 + 1, y2 - y1 + 1);
		for (int x = x1; x < x2; ++x) 
			d = min(d, DP(x1, y1, x, y2) + DP(x+1, y1, x2, y2));
		for (int y = y1; y < y2; ++y) 
			d = min(d, DP(x1, y1, x2, y) + DP(x1, y+1, x2, y2));
	}
//	printf("(%d,%d) (%d,%d) : %d\n", x1, y1, x2, y2, d); 
	return d;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	printf("%d\n", DP(1, 1, n, n));
//	cout << DP(1, 1, 2, 3) << endl;
}
