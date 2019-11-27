#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int n, m;
bool vis[MAXN];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        vis[u] = vis[v] = true;
    }
    int who = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            who = i;
            break;
        }
    }
    printf("%d\n", n-1);
    for (int i = 1; i <= n; ++i) {
        if (i == who) continue;
        printf("%d %d\n", i, who);
    }
}