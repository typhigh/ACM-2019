#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
typedef long long LL;
int n, k, p;
LL fac[MAXN];
void init() {
	fac[0] = 1;
	for (int i = 1; i < MAXN; ++i) fac[i] = 1LL * fac[i-1] * i % p;
}

LL sum(int k) {
	return (1LL * (k-1) * (k-1) % p + 1) % p;
}

LL solve() {
	init();
	k = min(k, n);
	if (k == n) return fac[k];
	if (k <= 1) return sum(n);
	
	LL ans = 1LL * fac[k] * sum(n-k) % p;
	ans = ans + k * fac[k] % p * (n-k) % p;
	ans = ans + fac[k] * (n-k-1) % p;
	ans = (ans % p + p) % p;
	return ans;
}

int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &k, &p);
		cout << "Case #" << ++ kase << ": " << solve() << endl;
	}
}
		
