#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int n, a[MAXN], cnt[MAXN];

int solve() {
    ++cnt[a[1]];
    int who = 0;
    int ans = n+1;
    for (int l = 1, r = 1; l <= n; ++l) {
        if (who) {
            ans = min(ans, r - l + 1);
            --cnt[a[l]];
            if (a[l] == who) who = 0;
            continue;
        }

        while (!who && r+1 <= n) {
            ++r;
            if (++cnt[a[r]] == 2) who = a[r];
        }
        if (!who) break;
        ans = min(ans, r - l + 1);
        --cnt[a[l]];
        if (a[l] == who) who = 0;
    }    
    if (ans == n+1) ans = -1;
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", a+i);
        for (int i = 1; i <= n; ++i) cnt[i] = 0;
        printf("%d\n", solve());
    }
}