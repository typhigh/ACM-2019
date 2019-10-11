#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400100;
int n, a[MAXN], L[MAXN], R[MAXN];
int lazy[MAXN<<2], t[MAXN<<2];

namespace segment {
void pushDown(int id) {
	if (lazy[id]) {
		lazy[id<<1] += lazy[id];
		t[id<<1] += lazy[id];
		lazy[id<<1|1] += lazy[id];
		t[id<<1|1] += lazy[id];
		lazy[id] = 0;
	}
}

void pushUp(int id) {
	t[id] = max(t[id<<1], t[id<<1|1]);
}

void add(int id, int l, int r, int L, int R, int d) {
	if (L <= l && r <= R) {
		t[id] += d;
		lazy[id] += d;
		return;
	}
	pushDown(id);
	int mid = (l+r) >> 1;
	if (L <= mid) add(id<<1, l, mid, L, R, d);
	if (R > mid) add(id<<1|1, mid+1, r, L, R, d);
	pushUp(id);
}

int query(int id, int l, int r, int L, int R) {
	int ans;
	if (L <= l && r <= R) {
		ans = t[id];
	} else {
		pushDown(id);
		int mid = (l+r) >> 1;
		ans = 0;
		if (L <= mid) ans = max(ans, query(id<<1, l, mid, L, R));
		if (R > mid) ans = max(ans, query(id<<1|1, mid+1, r, L, R));
//		pushUp(id);
	}
	return ans;
}

}

void solve() {
	int nn = n * 2;
	for (int i = 1; i <= nn; ++i) {
		int j = i;
		while (j > 1 && a[i] > a[j-1]) j = L[j-1];
		L[i] = j;
	}
	
	for (int i = nn; i >= 1; --i) {
		int j = i;
		while (j <= nn - 1 && a[i] > a[j+1]) j = R[j+1];
		R[i] = j;
	}
	for (int i = 1; i <= n; ++i) {
		segment::add(1, 1, nn, L[i], R[i], 1);		
	}
	int shift = 0, dep = n;
	for (int i = 0; i < n; ++i) {
		int now = segment::query(1, 1, nn, i+1, i+n);
//		cout << now << endl;
		if (now < dep) {
			dep = now;
			shift = i;
		}
		int r = R[i+1];
		int l = i+1;
		segment::add(1, 1, nn, l, r, -1);
		segment::add(1, 1, nn, L[i+1+n], R[i+1+n], 1);
	}
	cout << dep << " " << shift << endl;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		a[i] = n - a[i] + 1;
	}
	for (int i = 1; i <= n; ++i) a[i+n] = a[i];
	solve();
}
