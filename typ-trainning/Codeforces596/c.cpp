#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 20;
LL n, p;

int bitcnt(LL x) {
	int ret = 0;
	while (x) {
		x = x & (x - 1);
		++ret;
	}
	return ret;
}

LL solve() {
	for (int i = 1; n - p * i > 0; ++i) {
		LL nn = n - p * i;
		if (bitcnt(nn) <= i && nn >= i) return i;
	}
	return -1;
}

int main() {
	cin >> n >> p;
	cout << solve() << endl; 
}
