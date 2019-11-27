#include <cstdio>
#include <iostream>
using namespace std;

int a, b, c, w, h, tot, x[1000], y[1000];

void work(int a, int b, int c) {
	x[++ tot] = 2 * c + b;
	y[tot]= 2 * c + 2 * a;
	
	x[++ tot] = b + 2 * c;
  y[tot] = 2 * a + c + b;

  x[++ tot] = 3 * b + a + c;
  y[tot] = a + c;

  x[++ tot] = 2 * c + a + b;
  y[tot] = a + b + c;

  x[++ tot] = a + b + c;
  y[tot] = 2 * a + 2 * c;

  x[++ tot] = 2 * c + a + b;
  y[tot] = 2 * a + b;
}

int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	cin >> a >> b >> c;
	cin >> w >> h;
	work(a, b, c);
	work(b, a, c);
	work(a, c, b);
	work(b, c, a);
	work(c, b, a);
	work(c, a, b);
  string ans = "No";
  for (int i = 1; i <= tot; i ++) {
    if (w <= x[i] && h <= y[i]) ans = "Yes";
    if (h <= x[i] && w <= y[i]) ans = "Yes";
  }
  cout << ans;	
	return 0;
}