#include <bits/stdc++.h>
using namespace std;

int  Calc(int a, int b) {
	if (b == 1) return a;
	else return (a + b - 1) / b;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b, c, d, k;
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		int x = Calc(a, c);
		int y = Calc(b, d);
		if (x + y <= k) {
			printf("%d %d\n", x, y);
		} else {
			puts("-1");
		}
	}
}
