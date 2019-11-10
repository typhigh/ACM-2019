#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int l[MAXN], r[MAXN];
long double rv[MAXN];

int main() {
	int n, X;
	long double v;
	long double sumv = 0;
	int sumr = 0;
	cin >> n >> X >> v;
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i] >> rv[i];
		sumv += (r[i] - l[i]) * rv[i];
	}
	long double vy = -sumv / X;
	double ans = 0;
//	cout << vy << endl;
	if (vy * vy * 4 <= 3 * v * v ) {
		long double vx = sqrt(v * v - vy * vy);
		ans = X / vx;
		printf("%.3f\n", ans);
		return 0;
	}
	puts("Too hard");
}
