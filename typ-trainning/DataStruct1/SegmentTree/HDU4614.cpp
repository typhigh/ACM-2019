#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50010;
int n, m, t[MAXN<<2], lazy[MAXN<<2];

void init() {
	t[1] = lazy[1] = 0;
}

void pushUp(int id) {
	t[id] = t[id<<1] + t[id<<1|1];
}

void SetTag(int id, int val, int l, int r) {
	lazy[id] = val;
	t[id] = val * (r - l + 1);
}

void pushDown(int id, int l, int r) {
	if (~lazy[id]) {
		int mid = (l+r) >> 1;
		SetTag(id<<1, lazy[id], l, mid);
		SetTag(id<<1|1, lazy[id], mid+1, r);
		lazy[id] = -1;
	}
}

void update(int id, int l, int r, int L, int R, int d) {
	if (L <= l && r <= R) {
		SetTag(id, d, l, r);
		return ;
	}
	pushDown(id, l, r);
	int mid = (l+r) >> 1;
	if (mid >= L) update(id<<1, l, mid, L, R, d);
	if (mid < R) update(id<<1|1, mid+1, r, L, R, d);
	pushUp(id);
}

int query(int id, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return t[id];
	}
	pushDown(id, l, r);
	int mid = (l+r) >> 1;
	int ans = 0;
	if (mid >= L) ans += query(id<<1, l, mid, L, R);
	if (mid < R) ans += query(id<<1|1, mid+1, r, L, R);
	return ans;
}

int Query(int x, int val) {
	int l = x, r = n;
	while (l < r) {
		int mid = (l+r) >> 1;
		if (query(1, 1, n, x, mid) <= mid - x + 1 - val) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		init();
		while (m--) {
			int op, x, y;
			scanf("%d %d %d", &op, &x, &y);
			if (op == 1) {
				++x;
				int lim = n - x + 1 - query(1, 1, n, x, n);
				if (lim == 0) puts("Can not put any one.");
				else {
					if (lim < y) y = lim;
					int L = Query(x, 1);
					int R = Query(x, y);
					printf("%d %d\n", L-1, R-1);
					update(1, 1, n, L, R, 1);
				}
			} else {
				++x, ++y;
				int ans = query(1, 1, n, x, y);
				update(1, 1, n, x, y, 0);
				printf("%d\n", ans);
			}
		}
		puts("");
	}
}
