#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500;
char s[MAXN], t[MAXN];
int n, vis[MAXN];
int other[MAXN];

struct Info{
    int pos;
    char ch;
    int other;
}info[MAXN];
int pos[MAXN];
map<char, int> mp; 

void init() {
    mp.clear();
}

void Swap(int i, int j, vector<pair<int, int>>& ans) {
//    cout << i << " " << j << endl;
    ans.emplace_back(i, j-n);
    swap(pos[i], pos[j]);
    swap(info[pos[i]].pos, info[pos[j]].pos);
}

void solve() {
    for (int i = 0; i < 2 * n; ++i) {
        pos[i] = i;
        char val = s[i];
        info[i] = Info {i, val, -1};
        if (mp.count(val)) {
            int p = mp[val];
            info[p].other = i;
            info[i].other = p;
            mp.erase(val);
        } else {
            mp[val] = i;
        }
    }
    if (mp.size()) {
        puts("No");
        return;
    }
//    for (int i = 0; i < 2 * n; ++i) cout << info[i].ch << " " << info[i].other << endl;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < 2 * n; ++j) cout << info[i].ch << " " << info[i].other << endl;
        int p = pos[i];
        int op = info[p].other;
        Info& now = info[p];
        Info& other = info[op];
//        cout << now.ch << " " << other.ch << " " << now.pos << " " << other.pos << " " << p << " " << op << endl;
        assert(now.pos == i);
        if (other.pos == i + n) {
            ans.emplace_back(i, i);
            continue;
        }
        if (other.pos >= n) {
            Swap(n-1, other.pos, ans);
            Swap(n-1, i+n, ans);
            continue;
        }
        Swap(other.pos, i + n, ans);
    }
    puts("Yes");
    printf("%d\n", ans.size());
    for (auto p: ans) {
        printf("%d %d\n", p.first+1, p.second+1);
    }
}
int main() {
    int T, kase = 0;
    scanf("%d", &T);
    while (T--) {
        ++kase;
        init();
        scanf("%d", &n);
        scanf("%s %s", s, t);
        for (int i = 0; i < n; ++i) s[i+n] = t[i];
        solve();
    }
}