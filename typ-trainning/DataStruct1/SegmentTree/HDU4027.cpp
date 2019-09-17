#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
typedef long long LL;

LL t[MAXN<<2], a[MAXN];
bool one[MAXN<<2];

void pushUp(int id) {
	one[id] = one[id<<1] && one[id<<1|1];
	t[id] = t[id<<1] + t[id<<1|1];
}

void build(int id, int l, int r) {
	if (l == r) {
		t[id] = a[l];
		one[id] = false;
//		cout << t[id] << endl;
		return;
	}
	int mid = (l+r) >> 1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
	pushUp(id);
//	cout << t[id] << endl;
}

void update(int id, int l, int r, int L, int R) {
	if (one[id]) return;
	if (l == r) {
		t[id] = (LL) sqrt(t[id] + 0.1);
		one[id] = (t[id] == 1);
		return;
	}
	int mid = (l+r) >> 1;
	if (L <= mid) update(id<<1, l, mid, L, R);
	if (R > mid) update(id<<1|1, mid+1, r, L, R);
	pushUp(id);
}

LL query(int id, int l, int r, int L, int R) {
	// if (one[id]) return  r - l + 1;
	if (L <= l && r <= R) {
		return t[id];
	}
	int mid = (l + r) >> 1;
	LL ans = 0;
	if (L <= mid) ans += query(id<<1, l, mid, L, R);
	if (mid < R) ans += query(id<<1|1, mid+1, r, L, R);
	return ans;
}

int n, m;
int main() {
	int kase = 0;
	while (~scanf("%d", &n)) {
		printf("Case #%d:\n", ++kase);
		for (int i = 1; i <= n; ++i) cin >> a[i];
		build(1, 1, n);
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			int op, l, r;
			scanf("%d %d %d", &op, &l, &r);
			if (l > r) swap(l, r);
			if (op == 0) 
				update(1, 1, n, l, r);
			else 
				cout << query(1, 1, n, l, r) << endl;	
		}
		puts("");
	}
}

