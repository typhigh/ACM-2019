#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int n, a[MAXN], lazy[MAXN<<2], t[MAXN<<2];

void build(int id, int l, int r) {
	if (l == r) {
		t[id] = a[l];
		return;
	}
	int mid = (l+r) >> 1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
}

void updateLazy(int id, int tag) {
	lazy[id] = max(lazy[id], tag);
	t[id] = max(t[id], lazy[id]);
}

void pushDown(int id) {
	if (lazy[id]) {
		updateLazy(id<<1, lazy[id]);
		updateLazy(id<<1|1, lazy[id]);
		lazy[id] = 0;
	}
}

void update(int id, int l, int r, int x, int d) {
	if (l == r) {
		t[id] = d;
		lazy[id] = 0;
		return;
	}
	int mid = (l+r) >> 1;
	pushDown(id);
	if (mid >= x) update(id<<1, l, mid, x, d);
	else update(id<<1|1, mid+1, r, x, d);
}

void Query(int id, int l, int r) {
	if (l == r) {
		printf("%d ", t[id]);
		return;
	}
	pushDown(id);
	int mid = (l+r) >> 1;
	Query(id<<1, l, mid);
	Query(id<<1|1, mid+1, r);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	build(1, 1, n);
	int q;
	scanf("%d", &q);
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int p, x;
			scanf("%d%d", &p, &x);
			update(1, 1, n, p, x);
		} else {
			int x;
			scanf("%d", &x);
			updateLazy(1,  x);
		}
		// Query(1, 1, n);
	}
	Query(1, 1, n);
	puts("");
}
