#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, a[MAXN], b[MAXN];

bool check() {
    a[n+1] = a[0] = 0;
    int cnt = 0;
    for (int i = 1; i <= n+1; ++i) {
        if (a[i] != a[i-1]) ++cnt;
        if (a[i] > 0) return false;
    }
    return cnt <= 2;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", a + i);
        for (int i = 1; i <= n; ++i) scanf("%d", b + i);
        for (int i = 1; i <= n; ++i) a[i] -= b[i];
        if (check()) puts("YES");
        else puts("NO");
    }
}