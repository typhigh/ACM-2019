#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d, e;
	scanf("%d%d%d", &n, &d, &e);
	e *= 5;
	int g = __gcd(d, e);
	int ans = n;
	if (n >= d * e) {
		ans = n % g;
	} else {
		for (int i = 0; i <= e; ++i) 
			for (int j = 0; i * d + j * e <= n; ++j)
					ans = min(ans, n - i * d - j * e);
	}
	cout << ans << endl;
}
