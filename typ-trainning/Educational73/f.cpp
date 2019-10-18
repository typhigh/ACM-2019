#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
typedef long long LL;
const LL INF64 = 1LL << 60;

namespace SegTree {
	
LL lazy[MAXN*8];

struct Ans {
	LL val;
	int id;
	bool operator < (const Ans& rhs) const {
		return val < rhs.val;
	}
} a[MAXN*8];

void pushUp(int id) {
	a[id] = max(a[id<<1], a[id<<1|1]);
}

void pushDown(int id) {
	if (lazy[id]) {
		lazy[id<<1] += lazy[id];
		a[id<<1].val += lazy[id];
		lazy[id<<1|1] += lazy[id];
		a[id<<1|1].val += lazy[id];
		lazy[id] = 0;
	}
}

void build(int id, int l, int r, vector<int>& nums) {
	lazy[id] = 0;
	if (l == r) {
		a[id].val = -nums[l];
		a[id].id = l;
//		cout << a[id].val << endl;
		return;
	}
	int mid = (l+r) >> 1;
	build(id<<1, l, mid, nums);
	build(id<<1|1, mid+1, r, nums);
	pushUp(id);
//	cout << a[id].val << endl;
}

void update(int id, int l, int r, int L, int R, LL d) {
	if (L <= l && r <= R) {
		lazy[id] += d;
		a[id].val += d;
		return;
	}
	pushDown(id);
	int mid = (l+r) >> 1;
	if (L <= mid) update(id<<1, l, mid, L, R, d);
	if (R > mid) update(id<<1|1, mid+1, r, L, R, d);
	pushUp(id);
}

Ans query(int id, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return a[id];
	}
	pushDown(id);
	int mid = (l+r) >> 1;
	Ans ans = Ans {-INF64, -1};
	if (L <= mid) ans = max(ans, query(id<<1, l, mid, L, R));
	if (R > mid) ans = max(ans, query(id<<1|1, mid+1, r, L, R));
	pushUp(id);
	return ans;
}
}
struct Seg {
	int l, r, val;
	void read() {
		scanf("%d %d %d", &l, &r, &val);
		if (l > r) swap(l, r);
	}
	bool operator < (const Seg& rhs) const {
		return l < rhs.l;
	}
}s[MAXN];
int n;

vector<int> nums;
int getID(int val) {
	auto it = lower_bound(nums.begin(), nums.end(), val);
	if (it == nums.end()) {
		while(1);
	}
	return it-nums.begin();
}

void out(vector<int>& nums) {
	for (auto x: nums) cout << " " << x ;
	cout << endl;
}

void init() {	
	sort(s+1, s+n+1);
	nums.push_back(-1);
	for (int i = 1; i <= n; ++i) {
		nums.push_back(s[i].l);
		nums.push_back(s[i].r);
	}
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
//	out(nums);
	SegTree::build(1, 1, nums.size()-1, nums);
	for (int i = 1; i <= n; ++i) {
		int L = getID(s[i].r);
		int R = nums.size()-1;
		SegTree::update(1, 1, R, L, R, s[i].val);
	}
	int x = 1e9+7, y = 1e9+7;
	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == 1 || s[i].l != s[i-1].l) {
			using Ans = SegTree::Ans;
			Ans t = SegTree::query(1, 1, nums.size()-1, getID(s[i].l), nums.size()-1);
			LL now = t.val + s[i].l;
//			cout << s[i].l << " " << nums[t.id] << " " << now << endl;
			if (now > ans) {
				x = s[i].l;
				y = nums[t.id];
				ans = now;
			}
		}
		int L = getID(s[i].r);
		int R = nums.size()-1;
		SegTree::update(1, 1, R, L, R, -s[i].val);
	}
	cout << ans << '\n' << x << " " << x << " " << y << " " << y << endl;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		s[i].read();
	s[++n] = Seg {(int)(1e9+7), (int)(1e9+7), 0};
	init();
}
