#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	int T;
	cin >> T;
	while (T--) {
		LL a, b, c;
		cin >> a >> b >> c;
		LL ans;
		if (a + c <= b) ans = 0;
		else if (a > c + b) ans = c+1;
		else {
			LL x = (c + b - a + 1) / 2;
			if (x + x < c + b - a + 1) ++x;
			ans = c - x + 1;
		}
		cout << ans << endl;
	}
}
