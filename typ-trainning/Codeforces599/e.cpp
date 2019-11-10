#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF32 = 0x3f3f3f3f;
const int MAXN = 15;

vector<int> a[MAXN];
int n, dp[1<<MAXN], vis[MAXN];
LL avg, sum[MAXN];
map<LL, int> mp;
int kase;

void Do(int id) {
    for (int val: a[id]) {
        vis[id] = ++kase;
        if (!mp.count(avg - sum[id] + val)) continue;  
        int s = 1 << id;
        int needv = avg - sum[id] + val;
        int v = mp[avg - sum[id] + val];
        while (vis[v] != kase && v > id) {
            vis[v] = kase;
            s |= 1<<v;
            if (mp.count(avg - sum[v] + needv)) {
                needv = avg - sum[v] + needv;
                v = mp[needv];
            } else {
                break;
            }
        }
        if (v != id || needv != val) {
            continue;
        } else {
            dp[s] = val;
        }
    }
}

void InitDP() {
    memset(dp, INF32, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        Do(i);
    }
    for (int s = 1; s < (1<<n); ++s) {
        int id = -1;
        for (int i = 0; i < n; ++i) {
            if ((1 << i) & s) {
                id = i;
                break;
            }
        }
        for (int c = s & (s-1); c >= 1; c = s & (c-1)) {
            if (dp[c] != INF32 && dp[s^c] != INF32) {
                dp[s] = dp[c];
                if (mp[dp[s^c]] == id) dp[s] = dp[s^c];
            }
        }
    }
//    cout << dp[7] << " " << dp[1] << " " << dp[8] << " " << dp[15] << endl;
}

pair<int, int> ans[MAXN];
void solve() {
    if (avg % n) {
        puts("No");
        return;
    }
    avg /= n;
    InitDP();
    if (dp[(1<<n)-1] == INF32) {
        puts("No");
        return;
    }
    for (int s = (1<<n) - 1; s; ) {
        int val = dp[s];
        ++kase;
        int now = 0;
        for (int v = mp[val]; vis[v] != kase;) {
            now |= (1 << v);
            int u = v;
            vis[u] = kase;
            v = mp[avg - sum[u] + val];
            val = avg - sum[u] + val;
            ans[v] = make_pair(val, u);
        }
        s ^= now;
    }
    puts("Yes");
    for (int i = 0; i < n; ++i) {
        auto p = ans[i];
        printf("%d %d\n", p.first, p.second+1);
    }
}

int main() {
    scanf("%d", &n);
    avg = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int x;
            scanf("%d", &x);
            a[i].push_back(x);
            avg += x;
            sum[i] += x;
            mp[x] = i;
        }
        sort(a[i].begin(), a[i].end());
    }
    solve();
}