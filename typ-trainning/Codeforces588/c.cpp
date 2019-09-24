#include <bits/stdc++.h>
using namespace std;
const int MAXN = 7;
int n, m, a[MAXN][MAXN], col[MAXN];
int pa[MAXN][MAXN];
int ans;

void DFS(int cur) {
	if (cur == n) {
		memset(pa, 0, sizeof(pa));
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < n; ++j) 
				if (a[i][j]) {
					int x = col[i];
					int y = col[j];
					if (x > y) swap(x, y);
					pa[x][y] = 1;
				}
		int cnt = 0;
		for (int i = 0; i < 7; ++i) 
			for (int j = 0; j < 7; ++j) 
				if (pa[i][j]) ++cnt;
//		if (cnt == 21) 
//			for (int i = 0; i < n; ++i) cout << col[i] << " \n"[i == n-1];
		ans = max(ans, cnt);
		return;
	}
	for (int i = 0; i < 6; ++i) {
		col[cur] = i;
		DFS(cur+1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		a[x][y] = 1;
	}
	col[0] = 0;
	DFS(1);
	printf("%d\n", ans);
}
