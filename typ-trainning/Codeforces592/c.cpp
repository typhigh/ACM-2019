#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, p, w, d;

void gcd(LL a, LL b, LL& d, LL& x, LL& y)  {
	if (!b) {d = a; x = 1; y = 0;}
	else { gcd(b, a%b, d, y, x); y -= x*(a/b);}  
}

__int128 Calc(__int128 x, LL y) {
	if (y == 1) return x;
	else return (x + y - 1) / y;
}

int main() {
	cin >> n >> p >> w >> d;
	LL g = __gcd(w, d);
	if (p % g) {
		puts("-1");
		return 0;
	}
	w /= g, d /= g, p /= g;
	LL tmp, y, x;
	gcd(w, d, tmp, x, y);
//	cout << x << " " << y << " " << p << endl;
	__int128 xx = x;
	__int128 yy = y;
	xx *= p, yy *= p;
	
	if (yy < 0) {
		__int128 add = Calc(-yy, w); 
		yy += (__int128) w * add;
		xx -= (__int128) d * add;
		x = xx, y = yy;
		if (xx < 0 || xx + yy > n) puts("-1");
		else cout << x << " " << y << " " << n - x - y << endl;
		return 0;
	}

	__int128 add = yy/w;
//	cout << add << endl;
	yy -= (__int128) w*add;
	xx += (__int128) d*add;
	x = xx, y = yy;
	if (xx < 0 || xx + yy > n) puts("-1");
	else cout << x << " " << y << " " << n - x - y << endl;
}
