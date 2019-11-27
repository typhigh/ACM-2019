#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;
char s[MAXN][MAXN];
int n, m;
bool row[MAXN], col[MAXN];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) if (s[i][j] == 'S') {
            row[i] = col[j] = true;
        }
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) c1 += row[i];
    for (int i = 0; i < m; ++i) c2 += col[i];
    cout << n * m - c1 * c2 << endl;
}