#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL sum(LL x, LL y) {
	return (y - x + 1) * (x + y) / 2;
}

LL solve(LL x, LL y) {
	LL ans = 0;
//	cout << x << " " << y << endl;
	for (LL g = 1, ng; g <= x; g = ng+1) {
		ng = min(x / (x / g), y / (y / g)) ;
		ans += sum (g, ng) * ((y / g) - (x / g));
	}
	
	for (LL g = x + 1; g <= y; ++g) ans += g * (y / g);
	return  ans;
}

int main() {
	LL a, b;
	cin >> a >> b;
	--a;
	LL ans = solve(a, b);
	cout << ans << endl;
}
