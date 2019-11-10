#include <bits/stdc++.h>
using namespace std;
const int MAXN = 310;
int n, a[MAXN][MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i & 1) a[i][j] = (i - 1) * n + j;
            else if (j == 1) a[i][j] = a[i-1][n]+n;
            else a[i][j] = a[i][j-1]-1;
        }
    }
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= n; ++i) cout << a[i][j] << " \n"[i==n];
    }
}