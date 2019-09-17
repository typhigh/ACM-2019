#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int INF32 = 0x3f3f3f3f;
int t[MAXN<<2], lazy[MAXN<<2];

int n, m, a[MAXN];

void pushUp(int id) {
	t[id] = t[id<<1] + t[id<<1|1];
}

void pushDown(int id, int l, int r) {
	int mid = (l+r)>>1;
	int tag = lazy[id];
	if (tag) {
		lazy[id<<1] = tag;
		t[id<<1] = (mid - l + 1) * tag;
		lazy[id<<1|1] = tag;
		t[id<<1|1] = (r - mid) * tag;
		lazy[id] = 0;
	}
}

void build(int n) {
	lazy[1] = 1;
	t[1] = n;
}

void update(int id, int l, int r, int L, int R, int d) {
	if (L <= l && r <= R) {
		t[id] = (r - l + 1) * d;
		lazy[id] = d;
		return;
	}
	pushDown(id, l, r);
	int mid = (l+r) >> 1;
	if (L <= mid) update(id<<1, l, mid, L, R, d);
	if (R > mid) update(id<<1|1, mid+1, r, L, R, d);
	pushUp(id);
}

int query() {
	return t[1];
}

int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		build(n);
		while (m--) {
			int x, y, d;
			scanf("%d %d %d", &x, &y, &d);	
			update(1, 1, n, x, y, d);
		}
		printf("Case %d: The total value of the hook is %d.\n", ++kase, query());
	}
}

