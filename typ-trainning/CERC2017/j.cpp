#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000100;
vector<int> fac, G[MAXN];
int n, Size[MAXN], cnt[MAXN];

void DFS(int u, int fa) {
    Size[u] = 1;
    for (int v: G[u]) {
        if (v == fa) continue;
        DFS(v, u);
        Size[u] += Size[v];
    }
    int g = __gcd(Size[u], n);
    ++cnt[g]; 
    for (int i = 0; i < fac.size() && fac[i] * fac[i] <= g; ++i) {
        if (g % fac[i]) continue;
        ++cnt[fac[i]];
        if (g / fac[i] != fac[i]) ++cnt[g / fac[i]]; 
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) { 
            fac.push_back(i);
            if (n / i != i) fac.push_back(n / i); 
        }
    }
    sort(fac.begin(), fac.end());
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int root = rand() % n + 1;
    DFS(root, 0);
    vector<int> ans;
    for (int i = 2; i < n; ++i) {
        if (cnt[i] * i == n) ans.push_back(cnt[i]-1); 
    }
    ans.push_back(n-1);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) printf("%d%c", ans[i], " \n"[i==ans.size()-1]);
}