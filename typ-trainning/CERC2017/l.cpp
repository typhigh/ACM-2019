#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3010;
const int N = 3002;
int n, a[MAXN][MAXN], b[MAXN][MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char op[3];
        int x, y, z;
        scanf("%s %d %d %d", op, &x, &y, &z);
        if (op[0] == 'A') {
            x += N / 2 - z / 2;
            y += N / 2 - z / 2;
            a[x][y] = max(a[x][y], z);
        } else {
            x += N / 2 - z / 2;
            y += N / 2;
            b[x][y] = max(b[x][y], z);
        }
    }
    for (int x = 1; x <= N; ++x) 
        for (int y = 1; y <= N; ++y) {
            a[x][y] = max(max(a[x][y], a[x-1][y-1]-1), max(a[x-1][y]-1, a[x][y-1]-1));
            b[x][y] = max(max(b[x][y], b[x-1][y]-1), max(b[x-1][y-1]-2, b[x-1][y+1]-2));
        }
    double ans = 0;
    for (int x = 1; x <= N; ++x) 
        for (int y = 1; y <= N; ++y) {
            if (a[x][y]) {
                ++ans;
                continue;
            }

            if (b[x][y]) ans += 0.25;
            if (b[x][y+1]) ans += 0.25;
            if (b[x][y] > 1 || b[x][y+1] > 1) ans += 0.25;
            if (b[x-1][y] > 1|| b[x-1][y+1] > 1) ans += 0.25;
        }
    printf("%.2f\n", ans);
}