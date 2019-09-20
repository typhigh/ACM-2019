#include <bits/stdc++.h>
using namespace std;
const int MAXN = 305;

int n, m;
unsigned int d[MAXN][MAXN][9][9];
void init() {
	for (int k1= 0; (1 << k1) <= n; ++k1) 
		for (int k2 = 0; (1 << k2) <= m; ++k2) {
			if (k1 + k2 == 0) continue; 
			for (int i = 1; i + (1<<k1) - 1 <= n; ++i)
				for (int j = 1; j + (1<<k2) - 1 <= m; ++j) {
					if (k1) 
						d[i][j][k1][k2] = max(d[i][j][k1-1][k2], d[i+(1<<k1-1)][j][k1-1][k2]);
					else
						d[i][j][k1][k2] = max(d[i][j][k1][k2-1], d[i][j+(1<<k2-1)][k1][k2-1]);
				}
		}
}
			
unsigned int query(int x1, int y1, int x2, int y2) {
	int k1 = 0, k2= 0;
	while ((1<<k1) <= x2 - x1 + 1) ++k1;
	while ((1<<k2) <= y2 - y1 + 1) ++k2;
	unsigned int ans = max(d[x1][y1][k1-1][k2-1], d[x2 -(1<<k1-1)+1][y1][k1-1][k2-1]);
	ans = max(ans, d[x1][y2-(1<<k2-1)+1][k1-1][k2-1]);
	ans = max(ans, d[x2-(1<<k1-1)+1][y2-(1<<k2-1)+1][k1-1][k2-1]);
	return ans;
}

int val[MAXN][MAXN];
int main() {
	while(~scanf("%d %d", &n, &m)) {
		for (int i = 1; i <= n; ++i) 
			for(int j = 1; j <= m; ++j) {
				scanf("%ud", &val[i][j]);
				d[i][j][0][0] = val[i][j];
			}
		init();
		int q;
		scanf("%d", &q);
		while (q--) {
			int x1, y1, x2, y2; 
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			unsigned int maxv = query(x1, y1, x2, y2);
			bool ok = val[x1][y1] == maxv || val[x1][y2] == maxv || val[x2][y1] == maxv || val[x2][y2] == maxv;
			printf("%d %s\n", maxv, ok ? "yes":"no");
		}
	}
}
	
