#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int n, pa[MAXN], sz[MAXN];
bool vis[MAXN];
char s[MAXN][55];
char *ts[MAXN];
map<unsigned long long, int> hashs; 

int fa(int x) {
    return x == pa[x] ? x : pa[x] = fa(pa[x]);
}

unsigned long long hashval(char* s) {
    unsigned long long ans = 0;
    int len = strlen(s);
    for (int i = 0; i < len; ++i) 
        ans = ans * 1007 + s[i] + 7;
    return ans;
}

int solve() {
    int cnt = n + 26;
    for (int i = 0; i < n + 26; ++i) pa[i] = i, sz[i] = 1;
    for (int i = 0; i < n; ++i) {
        int len = strlen(s[i]);
        for (int j = 0; j < len; ++j) {
            int id = s[i][j] - 'a';
            int u = fa(i);
            int v = fa(id+n);
//            cout << u << " " << v << endl;
            if (u == v) continue;
            --cnt;
//            cout << u << " " << v << endl;
            if (sz[u] < sz[v]) swap(u, v);
            sz[u] += sz[v];
            pa[v] = u;
        }
    }

    for (int i = 0; i < 26; ++i) {
        int u = fa(i+n);
        if (sz[u] == 1) --cnt;
    }

    for (int i = 0; i < n; ++i) {
        int u = fa(i);
        if (sz[u] <= 2 && vis[i]) --cnt;
    }
//    cout << '\n';
    return cnt;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        unsigned long long val = hashval(s[i]);
        if (hashs.count(val)) {
            --i;
            --n;
            vis[hashs[val]] = true;
        } else {
            hashs[val] = i;
        }
    }
    printf("%d\n", solve());
}