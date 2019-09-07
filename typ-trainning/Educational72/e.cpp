# include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 200010;
int n, m, t[MAXN<<2][10][2], tmp[4];
int a[MAXN];

void add(int dest[10][2], int t1[10][2], int t2[10][2]) {
	for (int i = 0; i < 10; ++i) {
		int cur = 0;
		for (int j = 0; j < 2; ++j) {
			tmp[cur++] = t1[i][j];
			tmp[cur++] = t2[i][j];
		}
		sort(tmp, tmp+cur);
		dest[i][0] = tmp[0];
		dest[i][1] = tmp[1];
	}
}

void push_up(int id) {
	add(t[id], t[id<<1], t[id<<1|1]);
}

void build(int id, int l, int r) {
	if (l == r) {
		int val = a[l];
		for (int j = 0; j < 10; ++j) {
			int r = val % 10;
			val /= 10;
			if (r) t[id][j][0] = a[l];
		}
		return; 
	}

	int mid = (l+r) >> 1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
	push_up(id);
}

void update(int id, int l, int r, int p, int x) {
	if (l == r) {
		for (int i = 0; i < 10; ++i)
			t[id][i][0] = t[id][i][1] = INF;
		int val = x;
		for (int j = 0; j < 10; ++j) {
			int r = val % 10;
			val /= 10;
			if (r) t[id][j][0] = x;
		}
		return;
	}

	int mid = (l+r) >> 1;
	if (p <= mid) update(id<<1, l, mid, p, x);
	else update(id<<1|1, mid+1, r, p, x);
	push_up(id);
}

int Ans[10][2];
void query(int id, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		add(Ans, Ans, t[id]);
		return;
	}
	int mid = (l+r) >> 1;
	if (mid >= L) query(id<<1, l, mid, L, R);
	if (mid < R) query(id<<1|1, mid+1, r, L, R);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	memset(t, INF, sizeof(t));
	build(1, 1, n);
	for (int i = 0; i < m; ++i) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			update(1, 1, n, x, y);
		} else {
			memset(Ans, INF, sizeof(Ans));
			query(1, 1, n, x, y);
			int ans = -1;
			for (int i = 0; i < 10; ++i) {
				if (Ans[i][0] != INF && Ans[i][1] != INF) 
					if (ans == -1) ans = Ans[i][0] + Ans[i][1];
					else ans = min(ans, Ans[i][0] + Ans[i][1]);
			}
			printf("%d\n", ans);
		}
	}
}

