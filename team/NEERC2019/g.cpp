#include <bits/stdc++.h>
using namespace std;
const int MAXN = 14;
int n, a[MAXN];

int Calc(int a, int b) {
	if (a <= 0) return 0;
	if (b == 1) return a;
	return (a + b - 1) / b;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int b = 0;
		for (int i = 0; i < 7; ++i) {
			scanf("%d", a + i);
			a[i+7] = a[i];
			b += a[i];
		}
//		puts("!");
		int ans = 0x3f3f3f3f;
		for (int L = 0; L <= 6; ++L) {
			int maxv = 0;
			for (int j = 0; j < 7; ++j) {
				int sum = 0;
				for (int i = j; i < j + L; ++i) 
					sum += a[i];
				maxv = max(maxv, sum);
			}
			int now  = Calc((n - maxv), b) * 7 + L; 
			ans = min(ans, now);
		}
		cout << ans << endl;
	}
}
