#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;


struct node{
	int L;
	int R;
	int v;
	int tag;
};

struct Tree {
	node t[MAXN<<2];

	void SetTag(int id, int d, int l, int r) {
		t[id].tag = d;
		t[id].v = (r - l + 1) * d;
		t[id].L = t[id].R = t[id].v;
	}
	void init(int n) {
		SetTag(1, 1, 1, n);
	}

	void pushDown(int id, int l, int r) {
		if (~t[id].tag) {
			int mid = (l+r) >> 1;
			SetTag(id<<1, t[id].tag, l, mid);
			SetTag(id<<1|1, t[id].tag, mid+1, r);
			t[id].tag = -1;
		}
	}

	void pushUp(int id, int l, int r) {
		int mid = (l+r) >> 1;
		t[id].L = t[id<<1].L;
		if (t[id<<1].v == mid - l + 1) t[id].L += t[id<<1|1].L;
		t[id].R = t[id<<1|1].R;
		if (t[id<<1|1].v == r - mid) t[id].R += t[id<<1].R;
		t[id].v = max(t[id<<1].v, t[id<<1|1].v);
		t[id].v = max(t[id].v, t[id<<1].R + t[id<<1|1].L);
	}

	void update(int id, int l, int r, int L, int R, int d) {
		if (L <= l && r <= R) {
			SetTag(id, d, l, r);
			return;
		}
		int mid = (l+r) >> 1;
		pushDown(id, l, r);
		if (L <= mid) update(id<<1, l, mid, L, R, d);
		if (R > mid) update(id<<1|1, mid+1, r, L, R, d);
		pushUp(id, l, r);
	}

	int query(int id, int l, int r, int x) {
		if (t[id].v < x) return -1;
		// t[id].v >= x
		if (l == r) {
			return l;
		}
		pushDown(id, l, r);
		int mid = (l+r) >> 1;
		if (t[id<<1].v >= x) return query(id<<1, l, mid, x);
		int L = t[id<<1].R;
		if (L + t[id<<1|1].L >= x) return mid+1 - L;
		assert(t[id<<1|1].v >= x);
		return query(id<<1|1, mid+1, r, x);
	}
}boy, gf;

int n, m;
char s[20];
int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		printf("Case %d:\n", ++kase);
		scanf("%d %d", &n, &m);
		boy.init(n);
		gf.init(n);
		while (m--) {
			int x, y;
			scanf("%s", s);
			if (s[0] == 'D') {
				scanf("%d", &x);
				int l = boy.query(1, 1, n, x);
				if (l == -1) {
					puts("fly with yourself");
					continue;
				} else {
					printf("%d,let's fly\n", l);
					boy.update(1, 1, n, l, l+x-1, 0);
				}
			} else if (s[0] == 'N') {
				scanf ("%d", &x);
				int l = boy.query(1, 1, n, x);
				if (l == -1)
					l = gf.query(1, 1, n, x);
				if (l == -1) {
					puts("wait for me");
					continue;
				} else {
					printf("%d,don't put my gezi\n", l);
					boy.update(1, 1, n, l, l+x-1, 0);
					gf.update(1, 1, n, l, l+x-1, 0);
				}
			} else if (s[0] == 'S') {
				scanf("%d %d", &x, &y);
				boy.update(1, 1, n, x, y, 1);
				gf.update(1, 1, n, x, y, 1);
				puts("I am the hope of chinese chengxuyuan!!");
			}
		}
	}
}
