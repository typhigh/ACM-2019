#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 20;
int n, m, a[MAXN], b[MAXN];
LL f[1<<MAXN];

void DFS1(int x, LL sum, LL s) {
    if (x == n) {
        f[s] = sum >= m;
        return;
    }
    DFS1(x+1, sum + a[x], s | (1LL<<x) );
    DFS1(x+1, sum, s);
}

void DFS2(int x, LL sum, LL s, LL& ans) {
    if (x == n) {
		if (sum < m) return;
        LL t = ((1<<n)-1) ^ s;
        ans += f[t];
        return;
    }    
    DFS2(x+1, sum+b[x], s | (1LL<<x), ans);
    DFS2(x+1, sum, s, ans);
}

LL solve() {
    DFS1(0, 0, 0);
	for (int j = 0; j < n; ++j)
		for (int i = (1<<n)-1; i >= 0; --i)
            if (! ((1 << j) & i) ) f[i] += f[i|(1<<j)];
    LL ans = 0;
    DFS2(0, 0, 0, ans);
    return ans;
}
int main() {
    int T, kase = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) scanf("%d", a+i);
        for (int i = 0; i < n; ++i) scanf("%d", b+i);
        LL ans = solve();
    	cout << "Case #" << (++kase) << ": " << ans << endl;
	}
}
