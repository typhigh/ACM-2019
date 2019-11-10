#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400100;
int n, a[MAXN], ans[MAXN];
map<int, int> mp;

struct node {
    int x, cnt;
    bool operator < (const node& rhs) const {
        return x > rhs.x;
    }
};

void add(int x) {
    ++mp[x];
}

void sub(int x) {
    if (--mp[x] == 0) {
        mp.erase(x);
    } 
}

bool check(int x) {
    auto it = mp.end();
    --it;
    if (it->first <= 2 * x) return true;
    return false;
}

void solve() {
    int minv = a[0], maxv = a[0];
    for (int i = 1; i < n; ++i) {
        minv = min(a[i], minv);
        maxv = max(a[i], maxv);
    }
    if (minv * 2 >= maxv) {
        for (int i = 0; i < n; ++i) ans[i] = -1;
        return; 
    }
    for (int i = 0; i < n; ++i) a[i+n*2] = a[i+n] = a[i];
    int r = 0;
    mp[-1] = 0;
    for (int l = 0; l < n; ++l) {
        while(check(a[r])) {
            add(a[r]);
            ++r;
        }
        ans[l] = r-l;
        sub(a[l]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a+i);
    solve();
    for (int i = 0; i < n; ++i) printf("%d%c", ans[i], " \n"[i==n-1]);
}