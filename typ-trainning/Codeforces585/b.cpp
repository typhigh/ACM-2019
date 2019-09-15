#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
typedef long long LL;

int n, a, sum[MAXN];
int main() {
	scanf("%d", &n);
	sum[0] = 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		if (a>0) sum[i] = sum[i-1];
		else sum[i] = -sum[i-1];
	}
	int plus = 1, neg = 0;
	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (sum[i] > 0) {
			ans += plus;
			++plus;
		} else {
			ans += neg;
			++neg;
		}
	}
	cout << 1LL * n * (n+1) / 2 - ans << " " << ans << endl;
}

