#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
char s[MAXN][MAXN];
int n, m, row[MAXN], col[MAXN];
int main() {
    scanf("%d", &n);
    m = n;
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) if (s[i][j] == 'E') {
            ++row[i];
            ++col[j];
        }
    }
    bool ryes = true, cyes = true;
    for (int i = 0; i < n; ++i) if (row[i] == m) ryes = false;
    for (int i = 0; i < m; ++i) if (col[i] == n) cyes = false;
    if (!ryes && !cyes) {
        puts("-1");
        return 0;
    }
    vector<pair<int, int>> ans;
    if (ryes && n < m || (!cyes)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '.') {
                    ans.emplace_back(i+1, j+1);
                    break;
                }
            }
        }
    } else {
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (s[i][j] == '.') {
                    ans.emplace_back(i+1, j+1);
                    break;
                }
            }
        }
    }
    for (auto p: ans) printf("%d %d\n", p.first, p.second);
}