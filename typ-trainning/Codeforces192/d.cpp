#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
char s[MAXN][MAXN];
int n, m, sx, sy;
bool vis[MAXN][MAXN];
void GetExit() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) if (s[i][j] == 'E') {
            sx = i;
            sy = j;
            return;
        }
    }
}

void GetStart() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) if (s[i][j] == 'S') {
            sx = i;
            sy = j;
            return;
        }
    }   
}

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int d[MAXN][MAXN];

int solve() {
    memset(d, 0x3f, sizeof(d));
    GetExit();
    queue<pair<int, int>> q;
    q.emplace(sx, sy);
    d[sx][sy] = 0;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int x = p.first;
        int y = p.second;
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        for (int k = 0; k < 4; ++k) {
            int nx = p.first+dx[k];
            int ny = p.second+dy[k];
            if (vis[nx][ny] || s[nx][ny] == 'T') continue;
            if (d[nx][ny] > d[x][y] + 1) {
                d[nx][ny] = d[x][y] + 1;
                q.emplace(nx, ny);
            } 
        }
    }
    GetStart();
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (d[i][j] <= d[sx][sy] && s[i][j] > '0' && s[i][j] <= '9') {
                ans += s[i][j] - '0';
            }  
        }
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%s", s[i]+1);
    for (int i = 0; i <= n+1; ++i) s[i][0] = s[i][m+1] = 'T';
    for (int j = 0; j <= m+1; ++j) s[0][j] = s[n+1][j] = 'T';
    printf("%d\n", solve());
}