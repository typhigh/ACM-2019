#include <bits/stdc++.h>
using namespace std;
const int MAXN = 600100;
char s[MAXN];
int n, from, st[MAXN], L[MAXN], R[MAXN], top;

void debug() {
    cout << from << endl;
    for (int i = from; i < from + n; ++i) {
        cout << s[i];
    } 
    cout << endl;
}

struct Ans {
    int bea;
    int a, b;
    bool operator < (const Ans& rhs) const {
        return bea < rhs.bea;
    }
};

int Cnt(int l, int r) {
    int ret = 0;
    for (int i = l; i <= r; i = R[i]+1) ++ret;
    return ret;
}

Ans Calc(int l, int r, vector<pair<int,int>>& p) {
    Ans ret = Ans {Cnt(l+1, r-1) + 1, l, r};
    if (l+1 < r-1) 
        for (int i = l+1; i <= r-1; i = R[i]+1) 
            ret = max(ret, Ans {Cnt(i+1, R[i]-1) + (int)p.size()+1, i, R[i]});
    return ret;
}

void solve() {
    vector<pair<int, int>> p;   
    for (int i = from; i < from + n; i = R[i]+1) p.emplace_back(i, R[i]);
    Ans ans = Ans {(int)p.size(), 1, 1};
    for (int i = 0; i < p.size(); ++i) {
        Ans now = Calc(p[i].first, p[i].second, p);
        ans = max(ans, now);
    }
    printf("%d\n", ans.bea);
    printf("%d %d\n", ans.a % n + 1, ans.b % n + 1);
}
int main() {
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) s[i+n] = s[i];
    int cur = 0;
    for (int i = 0; i < n; ++i) cur += s[i] == '(' ? 1: -1;
    if (cur) {
        puts("0");
        puts("1 1");
        return 0;
    }
//    int from = 0;
    for (int i = 0; i < from + n; ++i) {
        if (s[i] == ')') {
            if (!top) {
                from = i+1;
                continue;
            }
            L[i] = st[top-1];
            R[st[top-1]] = i;
            --top;
        } else {
            st[top++] = i;
        }
    }
//    debug();
    solve();
}