#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400010;
int n, p[MAXN];

void solve() {
    vector<int> a;
    p[n+1] = -1;
    int cur = 1;
    for (int i = 2; i <= n+1; ++i) {
        if (p[i] == p[i-1]) ++cur;
        else {
            a.push_back(cur);
            cur = 1;
        }
    }
    if (a.size() <= 3) {
        puts("0 0 0");
        return;
    } 
    
    int one = a[0];
    int two = 0;
    cur = 0;
    while (cur+1 < a.size() && two <= one) {
        two += a[++cur];
    }
    if (cur == n) {
        puts("0 0 0");
        return;
    }
    int three = 0;
    while (cur+1 < a.size() && three <= one) {
        three += a[++cur];
    }
    if (three <= one || 2*(one + two + three) > n ) {
        puts("0 0 0");
        return;
    }
    while (cur + 1 < a.size() && 2*(one+two+three+a[cur+1]) <= n) {
        three += a[++cur];
    }
    printf("%d %d %d\n", one, two, three);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", p+i);
        solve();        
    }
}