#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
typedef long long LL;

int n;
LL sum[MAXN];
int ans[MAXN];
LL t[MAXN << 2];
void build(int id, int l, int r) {
	if (l == r) {
		t[id] = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
	t[id] = t[id<<1] + t[id<<1|1];
}
	
void add(int id, int l, int r, int x, int d) {
	if (l == r) {
		t[id] += d;
		return;
	}
	int mid = (l+r) >> 1;
	if (x <= mid) add(id<<1, l, mid, x, d);
	else add(id<<1|1, mid+1, r, x, d);
	t[id] = t[id<<1] + t[id<<1|1];
}

int query(int id, int l, int r, LL v) {
	if (l == r) {
		return l;
	}
	int mid = (l+r) >> 1;
	if (t[id<<1] > v) return query(id<<1, l, mid, v);
	else return query(id<<1|1, mid+1, r, v - t[id<<1]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%I64d", sum + i);
	}
	build(1, 1, n);
	for (int i = n - 1; i >= 0; --i) {
		ans[i] = query(1, 1, n, sum[i]);
		add(1, 1, n, ans[i], -ans[i]);
	}
	for (int i = 0; i < n; ++i) printf("%d%c", ans[i], " \n"[i == n - 1]);
}

