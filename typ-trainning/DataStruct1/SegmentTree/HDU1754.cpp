#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int INF32 = 0x3f3f3f3f;
int t[MAXN<<2];

int n, m, a[MAXN];

void pushUp(int id) {
	t[id] = max(t[id<<1], t[id<<1|1]);
}

void build(int id, int l, int r) {
	if (l == r) {
		t[id] = a[l];
		return;
	}
	int mid = (l+r) >> 1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
	pushUp(id);
}

void update(int id, int l, int r, int x, int d) {
	if (l == r) {
		t[id] = d;
		return;
	}
	int mid = (l+r) >> 1;
	if (x <= mid) update(id<<1, l, mid, x, d);
	else update(id<<1|1, mid+1, r, x, d);
	pushUp(id);
}

int query(int id, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return t[id];
	}
	int mid = (l+r) >> 1;
	int ans = -INF32;
	if (L <= mid) ans = max(ans, query(id<<1, l, mid, L, R));
	if (mid < R) ans = max(ans, query(id<<1|1, mid+1, r, L, R));
	return ans;
}

int main() {
	while (~scanf("%d %d", &n, &m)) {
		for (int i = 1; i <= n; ++i) scanf("%d", a + i);
		build(1, 1, n);
		while (m--) {
			char s[10];
			int x, y;
			scanf("%s %d %d", s, &x, &y);
			if (s[0] == 'Q') 
				printf("%d\n", query(1, 1, n, x, y));
			else 
				update(1, 1, n, x, y);
		}
	}
}

