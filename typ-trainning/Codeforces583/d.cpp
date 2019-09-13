#include <bits/stdc++.h>
using namespace std;
int n, m;
char **s;
int **vis;


int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = { 0,  1, 1, 1, 0, -1,-1,-1}; 
void BFS(int sx, int sy, int flag) {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int x = p.first;
		int y = p.second;
		if (vis[x][y]) continue;
		vis[x][y] = flag;
		for (int k = 0; k < 8; ++k) {
			int nx = dx[k] + x;
			int ny = dy[k] + y;
			if (nx < 0 || nx > n+1 || ny < 0 || ny > m+1 || vis[nx][ny] || s[nx][ny] != '#') continue;
			q.push(make_pair(nx, ny));
		}
	}
}

void init() {
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			if (s[i-1][j] == '#' && s[i][j-1] == '#') 
				s[i][j] = '#';
}

int solve() {
	scanf("%d%d", &n, &m);
	s = new char*[n+2];
	vis = new int*[n+2];
//	flag = new int*[n+2];
	for (int i = 0; i <= n + 1; ++i) {
		s[i] = new char[m+2];
		vis[i] = new int[m+2];
//		flag[i] = new int[m+2];
		for (int j = 0; j <= m + 1; ++j) vis[i][j] = 0;
	}

	for (int i = 1; i <= n; ++i) scanf("%s", s[i]+1);
	for (int i = 2; i <= n+1; ++i) s[i][0] = '#';
	for (int i = 0; i <= n-1; ++i) s[i][m+1] = '#';
	for (int i = 2; i <= m+1; ++i) s[0][i] = '#';
	for (int i = 0; i <= m-1; ++i) s[n+1][i] = '#';
	init();
	BFS(n+1, 0, 1);
	if (vis[0][m+1]) return 0;
	BFS(0, m+1, 2);
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) {
			if (i == 1 && j == 1) continue;
			if (i == n && j == m) continue;
			int flag = 0;
			for (int k = 0; k < 8; ++k) {
				int x = dx[k] + i;
				int y = dy[k] + j;
				if (vis[x][y]) flag|= vis[x][y];
			}
			if (flag == 3) return 1;
		}
	return 2;
}

void Delete() {
	for (int i = 0; i <= n+1; ++i) {
		delete[] s[i];
		delete[] vis[i];
	}	
	delete[] s;
	delete[] vis;
}

int main() {
	printf("%d\n", solve());
	Delete();
}
