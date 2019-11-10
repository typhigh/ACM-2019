#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int k, n, d, a[MAXN], cnt[MAXN];
map<int, int> mp;
int getColor(int x) {
    if (!mp.count(x)) {
        int m = mp.size();
        mp[x] = m;
        return m;
    }
    return mp[x];
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        mp.clear();
        scanf("%d%d%d", &n, &k, &d);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
            a[i] = getColor(a[i]);
        }
        int cur = 0;
        for (int i = 1; i <= d; ++i) {
            if (!cnt[a[i]]) ++cur;
            ++cnt[a[i]];
        }
        int mval = cur;
        for (int i = d+1; i <= n; ++i) {
            if (!cnt[a[i]]) ++cur;
            ++cnt[a[i]];
            if (--cnt[a[i-d]] == 0) --cur;
            mval = min(cur, mval);
        }
        for (int i = n; i >= n - d + 1; --i) --cnt[a[i]];
        printf("%d\n", mval);
    }
}