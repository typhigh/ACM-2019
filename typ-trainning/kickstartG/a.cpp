#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int n, m, q, sum[MAXN];
bool vis[MAXN];
vector<int> prime;

void init() {
    vis[1] = true;
    int m = sqrt(MAXN+0.5);
    for (int i = 2; i <= m; ++i) if (!vis[i]) {
        for (int j = i * i; j < MAXN; j += i) vis[j] = 1;
    }
}

int main() {
	init();
	int T, kase = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &q);
        for (int i = 1; i <= n; ++i) sum[i] = n / i;
		for (int i = 1; i <= m; ++i) {
            int x;
            scanf("%d", &x);
//			cout << x << endl;
			--sum[1];
            if (x == 1) continue;
            --sum[x];
//			cout << vis[x] << endl;
            if (!vis[x]) continue;
			else {
                for (int j = 2; j * j <= x; ++j) {
                    if (x % j) continue;
					int y = x / j;
//					cout << j << " " << y << endl;
                    if (j == y) --sum[j];
                    else --sum[y], --sum[j];
                }
            }
        }
//		for (int i = 1; i <= n; ++i) cout << sum[i] << " \n"[i==n];
        long long ans = 0;
        while(q--) {
            int x;
            scanf("%d", &x);
            ans += sum[x];
        }
        cout << "Case #" << (++kase) << ": " << ans << endl; 
    }
}
