#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000100;

int n, p[MAXN];
LL k;
int main() {
	cin >> n >> k;
	int L = 1, R = n;
	if (k < 1LL * (1+n) * n / 2) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; ++i) p[i] = i;
	LL kk = k - 1LL * n * (n+1) /2;
	while (kk && L < R) {
		if (kk <= R - L) {
			swap(p[R], p[R-kk]);
			kk = 0;
			break;
		}
		kk -= R-L;
		swap(p[R], p[L]);
		--R, ++L;
	}
	k -= kk;
	cout << k << endl;
	for (int i = 1; i <= n; ++i) printf("%d%c", i, " \n"[i == n]);
	for (int i = 1; i <= n; ++i) printf("%d%c", p[i], " \n"[i == n]);
}
