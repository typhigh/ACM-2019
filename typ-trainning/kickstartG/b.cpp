#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 105;
LL a[MAXN];
const int LIM = 51;
int n, cnt[MAXN];
LL M;

int main() {
    int T, kase = 0;
    scanf("%d", &T);
    while (T--) {
    	memset(cnt, 0, sizeof(cnt));
		cin >> n >> M;
        LL sum = 0;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            LL x = a[i];
            for (int j = 0; j < LIM && x; ++j, x /= 2) {
                if (x & 1) ++cnt[j];
            }  
		}
//		for (int i = 0; i < LIM; ++i) cout << cnt[i] << " \n"[i==LIM-1]; 
        LL k = 0;
        for (int i = 0; i < LIM; ++i) {
            if (cnt[i] >= n - cnt[i]) { 
                k |= (1LL<<i);
                sum -= (cnt[i] - n + cnt[i]) * (1LL << i);
            }
        }
        LL ans = -1;
        if (sum <= M) {
            for (int i = LIM-1; i >= 0; --i) if (cnt[i] < n - cnt[i]) {
                if (sum + (1LL << i) * (n - 2*cnt[i]) <= M) {
                    k |= (1LL << i);
                    sum += (1LL << i) * (n - 2*cnt[i]);
                }
            }
            ans = k;
        } 
        cout << "Case #" << (++kase) << ": " << ans << endl;
    }
}
