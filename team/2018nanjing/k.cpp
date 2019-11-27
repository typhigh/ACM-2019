#include <bits/stdc++.h>
using namespace std;
const int MAXN = 25;
char s[MAXN][MAXN];
int n, m;

int main() {
    srand((unsigned) time(NULL));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%s", s[i]+1);
    /*
    for (int i = 0; i <= n+1; ++i) s[i][m+1] = s[i][0] = '0';
    for (int j = 0; j <= m+1; ++j) s[n+1][j] = s[0][j] = '0';
    */
    string ans;
    for (int i = 0; i < 50000; ++i) {
        int u = rand() % 4;
        char ch;
        if (u == 0) ch = 'U';
        if (u == 1) ch = 'L';
        if (u == 2) ch = 'R';
        if (u == 3) ch = 'D';
        ans.push_back(ch); 
    }
    cout << ans << endl;
}