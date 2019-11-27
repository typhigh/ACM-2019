#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3010;
char s[MAXN][MAXN];
int n;
bool vis[MAXN][2];

map<char, int> mp[MAXN][2];

struct Ans {
    char type;
    int ind;
    char ch;
};
vector<Ans> ans;

void Out(int type, int ind, char ch) {
    char _type = 'h';
    if (type == 1) _type = 'v';
    ans.push_back(Ans{_type, ind, ch}); 
}

void solve() {
    int cnt = n + n;
    while (cnt) {
        bool yes = false;
        for (int i = 0; i < n; ++i) {
            if (vis[i][0]) continue;
            auto& m = mp[i][0];
            if (m.size() <= 1) {
                char ch = m.size() ? m.begin()->first : 'a'; 
                Out(0, i, ch);
                for (int j = 0; j < n; ++j) {
                    if (s[i][j] == '?') continue;
                    if(--mp[j][1][s[i][j]] == 0) mp[j][1].erase(s[i][j]);
                    s[i][j] = '?';
                }
                --cnt;
                vis[i][0] = true;
                yes = true;
                break;
            }
        }
        if (yes) continue;
        for (int j = 0; j < n; ++j) {
            if (vis[j][1]) continue;
            auto& m = mp[j][1];
            if (m.size() <= 1) {
                char ch = m.size() ? m.begin()->first : 'a'; 
                Out(1, j, ch);
                for (int i = 0; i < n; ++i) {
                    if (s[i][j] == '?') continue;
                    if (--mp[i][0][s[i][j]] == 0) mp[i][0].erase(s[i][j]);
                    s[i][j] = '?';
                }
                --cnt;
                vis[j][1] = true;
                yes = true;
                break;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", s+i);
    for (int i = 0; i < n; ++i) {
        auto& m = mp[i][0];
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '?') continue;
            ++m[s[i][j]];
        }
    }
    for (int j = 0; j < n; ++j) {
        auto& m = mp[j][1];
        for (int i = 0; i < n; ++i) {
            if (s[i][j] == '?') continue;
            ++m[s[i][j]];
        }
    }
    solve();
    reverse(ans.begin(), ans.end());
    for (auto p: ans) {
        cout << p.type << " " << p.ind+1 << " " << p.ch << '\n';
    }
}