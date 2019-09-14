#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
typedef long long LL;
const LL INF64 = 1LL << 60;

int m, n;
pair<LL, int> a[MAXN], b[MAXN];
int v2[MAXN], ans[MAXN];
LL d[MAXN];

void update1(int l, int r, int id, LL val) {
	if (l > r) return;
	int L = (l + n - id) % n;
	int R = (r + n - id) % n;
	// L : 0, 1, ... n-1
	if (L > R) {
		d[L] += val;
		d[n] -= val;
		d[0] += val;
		d[R+1] -= val;
	} else {
		d[L] += val;
		d[R+1] -= val;
	}
}

void update2(int l, int r, int id, LL val) {
	if (l > r) return;
	int L = (id - r + n) % n;
	int R = (id - l + n) % n;
	if (L > R) {
		d[L] += val;
		d[n] -= val;
		d[0] += val;
		d[R+1] -= val;
	} else {
		d[L] += val;
		d[R+1] -= val;
	}
}

int main() {
	scanf("%d%d", &m ,&n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i].first);
		b[i].second = i;
	}
	sort(a+1, a+n+1);
	sort(b+1, b+n+1);
	for (int i = 1; i <= n; ++i) v2[i] = 2 * b[i].first;
	// calc a
	for (int i = 1; i <= n; ++i) {
		int p1 = upper_bound(v2+1, v2+n+1, 2*a[i].first-m) - v2;
		update1(1, p1-1, i, -a[i].first);
		int p2 = upper_bound(v2+1, v2+n+1, 2*a[i].first) - v2;
		update1(p1, p2-1, i, a[i].first);
		int p3 = upper_bound(v2+1, v2+n+1, 2*a[i].first+m) - v2;
		update1(p2, p3-1, i, -a[i].first);
		update1(p3, n, i, a[i].first+m);
	}
	for (int i = 1; i <= n; ++i) v2[i] = 2 * a[i].first;
	// calc b
	for (int i = 1; i <= n; ++i) {
		int p1 = upper_bound(v2+1, v2+n+1, 2*b[i].first-m-1) - v2;
		update2(1, p1-1, i, -b[i].first);
		int p2 = upper_bound(v2+1, v2+n+1, 2*b[i].first-1) - v2;
		update2(p1, p2-1, i, b[i].first);
		int p3 = upper_bound(v2+1, v2+n+1, 2*b[i].first+m-1) - v2;
		update2(p2, p3-1, i, -b[i].first);
		update2(p3, n, i, b[i].first+m);
	}
	LL minv = INF64;
	int id = -1;
	for (int i = 0; i < n; ++i) {
		if (d[i] < minv) {
			minv = d[i];
			id = i;
		}
		d[i+1] += d[i];
	}
	cout << minv << endl;
	for (int i = 1, j = id+1; i <= n; ++i, j = (j == n? 1 : j +1)) ans[a[i].second] = b[j].second;
	for (int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i==n]);
}
