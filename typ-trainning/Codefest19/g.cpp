#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000100;

int phi[MAXN];
void Init() {
	phi[1] = 1;
	for (int i = 2; i < MAXN; ++i) if (!phi[i]) {
		for (int j = i; j < MAXN; j += i) {
			if (!phi[j]) phi[j] = j;
			phi[j] = phi[j] / i * (i-1);
		}
	}
}

int main() {
	Init();
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << 3 << endl;
		return 0;
	}
	k += 2;
	sort(phi+1, phi+1+n);
	LL ans = 0;
	for (int i = 1; i <= k; ++i) ans += phi[i];
	cout << ans << endl;
}
