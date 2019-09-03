#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;
bool noplace[MAXN][MAXN];
int n, m, a[MAXN][MAXN], b[MAXN][MAXN];
int dx[4] = {0, -1, 0, -1};
int dy[4] = {0, 0, -1, -1};

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) 
			if (!a[i][j]) {
				for (int k = 0; k < 4; ++k) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (x >= 0 && y >= 0) noplace[x][y] = true;
				}
			}
	for (int i = 0; i < n; ++i) noplace[i][m-1] = true;
	for (int i = 0; i < m; ++i) noplace[n-1][i] = true;
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) 
			if (!noplace[i][j]) {
				ans.emplace_back(i, j);
				for (int k = 0; k < 4; ++k) {
					int x = i - dx[k];
					int y = j - dy[k];
					if (x < n && y < m) b[x][y] = 1;
				}
			}
	bool yes = true;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j)
			if (a[i][j] != b[i][j]) yes = false;
	if (!yes) {
		puts("-1");
	} else {
		printf("%d\n", ans.size());
		for (auto p: ans) {
			printf("%d %d\n", p.first+1, p.second+1);
		}
	}
}
