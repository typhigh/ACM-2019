#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000100;

int n, w;
int a[MAXN], q[MAXN];
LL d[MAXN];

int main() {
	scanf("%d%d", &n, &w);
	for (int id = 0; id < n; ++id) {
		int L;
		scanf("%d", &L);
		int kase = 0;
		if (2 * L <= w) kase = 1;
		for (int i = 0; i < L; ++i) {
			scanf("%d", a + i);
			if (kase) a[i] = max(0, a[i]);
		}
		if (kase) {
			int cur = 0;
			for (int i = 0; i < L; ++i) {
				int now = max(cur, a[i]);
				d[i] += now - cur;
				cur = now;
			}
			cur = a[L-1];
			for (int i = L - 1; i >= 1; --i) {
				int now = max(a[i-1], cur);
				d[w - L + i] -= now - cur;
				cur = now;
			}
		} else {
			int h = 0, p = 0;
			LL cur = 0;
			for (int i = 0; i < w; ++i) {
				if (i == w) break;
				if (i > w - L && h < p && q[h] + w - L < i) ++h;
				if (i < L) {
					while (p > h && a[i] >= a[q[p-1]]) --p;
					q[p++] = i;
				}
				assert(h < p);
				LL now = a[q[h]];
				if (i < w - L || i >= L) now = max(now, 0LL);
				d[i] += now - cur;
				cur = now;
//				cout << d[i] << endl;
			}
			
		}
	}
	LL ans = 0;
	for (int i = 0; i < w; ++i) {
		ans += d[i];
		cout << ans << " ";
	}
	cout << endl;
}
