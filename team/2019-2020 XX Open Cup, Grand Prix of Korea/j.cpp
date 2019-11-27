#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300010;
vector<int> G[MAXN];
int n;
struct Seg {
    int L, R, val;
    bool operator < (const Seg& rhs) const {
        if (L == rhs.L) return R > rhs.R;
        return L < rhs.L;
    }
}s[MAXN];
int st[MAXN];

int sid[MAXN];
multiset<int> sets[MAXN];

void add(multiset<int>& a, multiset<int>& b) {
    auto it1 = a.rbegin();
    auto it2 = b.rbegin();
    while (it1 != a.rend() && it2 != b.rend()) {
        int v = *it1 + *it2;
        a.emplace_hint(it1, v);
        auto cit1 = it1++;
        ++it2;
    }
}

void DFS(int u) {  
    if (G[u].size() == 0) {
        sid[u] = u;
        auto &su = sets[u];
        su.insert(s[u].val);
        return;
    } 
    int which = -1;
    for (int v: G[u]) {
        DFS(v);
        if (which == -1 || sets[sid[v]].size() > sets[sid[which]].size()) {
            which = v;
        }
    } 
    sid[u] = sid[which];
    for (int v: G[u]) {
        if (v == which) continue;
        add(sets[sid[u]], sets[sid[v]]);
    }
}

void solve() {
    int top = 0;
    st[top++] = 0;
    for (int i = 1; i < n; ++i) {
        while (s[i].L >= s[st[top-1]].R) --top;
        int pa = st[top-1];
        G[pa].push_back(i);
        st[top++] = i;
    }    
    DFS(0);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d %d", &s[i].L, &s[i].R, &s[i].val);
    s[n++] = Seg {1, 1000100, 0};
    sort(s, s+n);
    solve();
}