#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;
const int MAXN = 200010;
int t[MAXN<<2][3];
int Add[MAXN<<2], Mul[MAXN<<2], Set[MAXN<<2];
int Cnt[MAXN<<2];

int n, m;

void SetTag(int id, int val) {
	Set[id] = val;
	Add[id] = Mul[id] = 0;
	t[id][0] = val * Cnt[id] % mod;
	t[id][1] = val * t[id][0] % mod;
	t[id][2] = val * t[id][1] % mod;
}

void MulTag(int id, int mul) {
	if (~Set[id]) {
		SetTag(id, mul * Set[id] % mod);
		return ;
	}
	// (a * ai + add) * mul
	Add[id] = Add[id] * mul % mod;
	if (Mul[id]) Mul[id] = Mul[id] * mul % mod;
	else /*Mul[id] == 0 means Mul[id] = 1*/ Mul[id] = mul;
	t[id][0] = t[id][0] * mul % mod;
	t[id][1] = t[id][1] * mul % mod * mul % mod;
	t[id][2] = t[id][2] * mul % mod * mul % mod * mul % mod;
}

void AddTag(int id, int add) {
	if (~Set[id]) {
		SetTag(id, add + Set[id]);
		return;
	}
	Add[id] = (Add[id] + add) % mod;
	t[id][2] = (t[id][2] + add * add % mod * add % mod * Cnt[id] % mod 
			+ 3 * add * add % mod * t[id][0] % mod 
			+ 3 * add * t[id][1] % mod) % mod;
	t[id][1] = (t[id][1] + add * add % mod * Cnt[id] % mod + 2 * add * t[id][0] % mod) % mod;
	t[id][0] = (t[id][0] + add * Cnt[id]) % mod;
}

void Tag(int id, int val, int op) {
	if (op == 1) AddTag(id, val);
	else if (op == 2) MulTag(id, val);
	else if (op == 3) SetTag(id, val);
	else {
		// impossible reach
		while(1);
		assert(0);
	}
}

void pushDown(int id) {
	if (~Set[id]) {
		if (Mul[id] || Add[id]) {
			while(1);
		}
		SetTag(id<<1, Set[id]);
		SetTag(id<<1|1, Set[id]);
		Set[id] = -1;
		return;
	}
	// we define a
	// with a * mul + add
	if (Mul[id]) {
		MulTag(id<<1, Mul[id]);
		MulTag(id<<1|1, Mul[id]);
		Mul[id] = 0;
	}
	if (Add[id]) {
		AddTag(id<<1, Add[id]);
		AddTag(id<<1|1, Add[id]);
		Add[id] = 0;
	}
}

void pushUp(int id) {
	t[id][0] = (t[id<<1][0] + t[id<<1|1][0]) % mod;
	t[id][1] = (t[id<<1][1] + t[id<<1|1][1]) % mod;
	t[id][2] = (t[id<<1][2] + t[id<<1|1][2]) % mod;
}

void build(int id, int l, int r) {
	Cnt[id] = r - l + 1;
	Cnt[id] %= mod;
	if (l == r) {
		SetTag(id, 0);		
		Set[id] = -1;
		return;
	}
	int mid = (l+r) >> 1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
	SetTag(id, 0);
	Set[id] = -1;
//	pushUp(id);
}

void update(int id, int l, int r, int L, int R, int d, int op) {
	if (L <= l && r <= R) {
		Tag(id, d, op);
		return ;
	}
	pushDown(id);
	int mid = (l+r) >> 1;
	if (L <= mid) update(id<<1, l, mid, L, R, d, op);
	if (R > mid) update(id<<1|1, mid+1, r, L, R, d, op);
	pushUp(id);
}

int query(int id, int l, int r, int L, int R, int p) {
	if (L <= l && r <= R) {
//		cout << l << " " << r << " " << t[id][p] << " " << Cnt[id] << endl;
		return t[id][p];
	}
	pushDown(id);
	int mid = (l+r) >> 1;
	int ans = 0;
	if (L <= mid) ans += query(id<<1, l, mid, L, R, p);
	if (R > mid) ans += query(id<<1|1, mid+1, r, L, R, p);
	return ans % mod;
}

int main() {
	while (~scanf("%d %d", &n, &m) && n + m > 0) {
		build(1, 1, n);
		while (m--) {
			int op, x, y, c;
			scanf("%d %d %d %d", &op, &x, &y, &c);
			if (op <= 3) update(1, 1, n, x, y, c, op);
			else {
				int ans = query(1, 1, n, x, y, c - 1);
				printf("%d\n", (ans % mod + mod) % mod);
			}
		}
	}
}
