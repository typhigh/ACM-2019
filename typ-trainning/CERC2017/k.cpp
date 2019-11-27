#include <bits/stdc++.h>
using namespace std;
#define RREP(i, l, r) for (int i = l; i <= r; ++i)
const int MAXN = 550;
const int K = 7;
int n, b[MAXN], cnt[K];

int f[MAXN][MAXN][K], g[MAXN][MAXN][K];

void update(int& x, int d) {
    x = max(x, d);
}

int main() {
    scanf("%d", &n);
    int a[7];
    RREP(i, 1, n) {
        scanf("%d", a+0);
        for (int j = 1; j < 7; ++j) 
            a[j] = a[j-1] / 10 + a[j-1] % 10 * 1000000;
        if (a[0] == a[1]) 
            --i, --n;
        else 
            b[i] = max_element(a, a+7) - a;
    }
    RREP(i, 1, n+1) 
        ++cnt[(b[i]-b[i-1]+7)%7];
    int ret = n + 1 - cnt[0];
    for (int i = 1; i < 4; ++i) {
        int v = min(cnt[i], cnt[7-i]);
        ret -= v;
        cnt[i] -= v;
        cnt[7-i] -= v;
    }
    int x = cnt[1] ? 1 : 6, cx = cnt[1] ? cnt[1] : cnt[6];
    int y = cnt[2] ? 2 : 5, cy = cnt[2] ? cnt[2] : cnt[5];
    int z = cnt[3] ? 3 : 4, cz = cnt[3] ? cnt[3] : cnt[4];
    RREP(i, 0, cy) RREP(j, 0, cz) RREP(k, 0, K-1) f[i][j][k] = -1;
    f[0][0][0] = 0;
    RREP(l, 0, cx) {
        RREP(i, 0, cy) RREP(j, 0, cz) RREP(k, 0, K-1) g[i][j][k] = f[i][j][k], f[i][j][k] = -1;
        RREP(i, 0, cy) RREP(j, 0, cz) RREP(k, 0, K-1) if (~g[i][j][k]) {
            if (l < cx) update(f[i][j][(k+x) %K], g[i][j][k] + ((k+x) % K == 0));
            if (i < cy) update(g[i+1][j][(k+y)%K], g[i][j][k] + ((k+y) % K == 0));
            if (j < cz) update(g[i][j+1][(k+z)%K], g[i][j][k] + ((k+z) % K == 0));
        }   
    }
    ret -= g[cy][cz][0];
    printf("%d\n", ret);
}
/*
6
9689331
1758824
3546327
5682494
9128291
9443696
*/

/*
7
5941186
3871463
8156346
9925977
8836125
9999999
5987743
*/