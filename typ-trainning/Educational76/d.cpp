#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;

pair<int, int> a[MAXN];
int n, k, m[MAXN];
int ans;

void DFS(int cur) {
    if (cur == n) return;
    int mmax = m[cur];
    int now = lower_bound(a, a+k, make_pair(mmax, 0)) - a;
    for (int j = cur+1; j < n; ++j) {
        if (j - cur >= a[now].second) {
            ++ans;
            return DFS(j);
        }
        mmax = max(mmax, m[j]);
        while (mmax > a[now].first) {
            if (now+1 >= k || a[now+1].second < j - cur + 1) {
                ++ans;
                return DFS(j);
            }
            ++now;
        }
    }
    ++ans;
}

int solve() {
    int mmax = 0;
    for (int i = 0; i < n; ++i) mmax = max(mmax, m[i]);
    if (mmax > a[0].first) return -1;
    int tot = 1;
    for (int i = 1; i < k; ++i) {
        if (a[tot-1].second < a[i].second) a[tot++] = a[i];  
    }    
    k = tot;
    reverse(a, a + k);

    ans = 0;
    DFS(0);
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", m + i);
        scanf("%d", &k);
        for (int i = 0; i < k; ++i) scanf("%d %d", &a[i].first, &a[i].second);
        sort(a, a + k);
        reverse(a, a + k);
        printf("%d\n", solve());
    }
}