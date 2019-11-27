#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000010;
int n, R[MAXN], a[MAXN], vis[MAXN];
int kase;

int DFS(int u) {
    ++kase;
    set<int> s;
    if (a[u] < 0) return -1;
    s.insert(a[u]);
    vis[a[u]] = kase;
    for (int v = u+1; v <= n; ++v) {
        if (a[v] > 0) {
            if (vis[a[v]] == kase) return -1;
            s.insert(a[v]);
            vis[a[v]] = kase;
        } else {
            if (!s.count(-a[v])) return -1;
            s.erase(-a[v]);
        }
        if (s.empty()) return v; 
    }
    return -1;
} 

void solve() {
    vector<int> ans;
    int u = 0;
    while (u < n) {
        int v = DFS(u+1);
        if (v == -1) {
            puts("-1");
            return;
        }
        ans.push_back(v-u);
        u = v;
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%d%c", ans[i], " \n"[i==ans.size()-1]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    solve();
}