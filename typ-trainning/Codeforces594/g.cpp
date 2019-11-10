#include <bits/stdc++.h>
using namespace std;
const int MAXN = 51;
int n;
vector<int> v[2];
vector<pair<int, int>> s[MAXN];

int bitcnt(int x) {
    int ret = 0;
    while (x) {
        x = x & (x-1);
        ++ret;
    }
    return ret;
}

int m;
void DFS(int u, int sum, int eles) {
    if (u == m) {
        int bcnt = bitcnt(eles);
        s[bcnt].emplace_back(sum, eles);
        return ;
    }
    DFS(u+1, sum, eles);
    DFS(u+1, sum + v[0][u], eles|(1<<u));
}

int ans;
pair<int, int> ansState;
void DFS2(int u, int sum, int eles, int msum) {
    if (u == m) {
        int bcnt = bitcnt(eles);
        vector<pair<int,int>>& now = s[m-bcnt];
        auto it = lower_bound(now.begin(), now.end(), make_pair(msum - sum, 0));
        if (it == now.end()) return;
        int cur = it->first + sum;
        if (ans > cur) {
            ans = cur;
            ansState = make_pair(it->second, eles);
        }
        return;
    }
    DFS2(u+1, sum, eles, msum);
    DFS2(u+1, sum + v[1][u], eles|(1<<u), msum);
}

int a[MAXN], g[2][MAXN];
void solve() {
//    vector<int> v;
    int sum = 0;
    for (int i = 2; i < n+1; ++i) v[0].push_back(a[i]), sum += a[i];
    for (int i = n+1; i < 2*n; ++i) v[1].push_back(a[i]), sum += a[i];
    ans = sum+1;
    sum = (sum + 1) / 2;
    m = n - 1;
    DFS(0, 0, 0);
    for (int i = 0; i <= m; ++i) sort(s[i].begin(), s[i].end());
    DFS2(0, 0, 0, sum);
    int cur0 = 1, cur1 = n-2;
//    cout << ans << " " << ansState.first << " " << ansState.second << endl;
    for (int i = 0; i < m; ++i) {
//        cout << v[0][i] << " ";
        if (ansState.first & (1 << i)) g[0][cur0++] = v[0][i];
        else g[1][cur1--] = v[0][i];
    }
//    cout << endl;
    for (int i = 0; i < m; ++i) {
//        cout << v[1][i] << " ";
        if (ansState.second & (1 << i)) g[0][cur0++] = v[1][i];
        else g[1][cur1--] = v[1][i];
    }
//    cout << endl;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n + n; ++i) scanf("%d", a + i);
    sort(a, a + 2*n);
    g[0][0] = a[0];
    g[1][n-1] = a[1];
    solve();
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) printf("%d%c", g[i][j], " \n"[j == n-1]);
    }
}