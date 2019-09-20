#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50010;
pair<int, int> a[MAXN];
int n, q, d[MAXN][20];

void init() {
	for (int i = 0; i < n; ++i) d[i][0] = a[i].second;
	for (int k = 1; (1 << k) <= n; ++k) 
		for (int i = 0; i + (1<<k) - 1 < n; ++i) 
			d[i][k] = max(d[i][k-1], d[i+(1<<k-1)][k-1]);
}

int query(int l, int r) {
	int k = 0;
	while ((1<<k) <= r-l+1) ++k;
	return max(d[l][k-1], d[r-(1<<k-1)+1][k-1]);
}

#define MAYBE 0
#define TRUE 1
#define FALSE 2

int solve(int l, int r) {
	if (l == r) while(1);
	int Rid = lower_bound(a, a+n, make_pair(r, 0)) - a;
	int Lid = lower_bound(a, a+n, make_pair(l, 0)) - a;
	bool ryes = Rid < n && a[Rid].first == r;
	bool lyes = Lid < n && a[Lid].first == l;
	if (ryes && lyes && a[Rid].second > a[Lid].second) return FALSE;
	
	// assert ryes = true
	if (l + 1 == r) {
		if (!ryes || !lyes) return MAYBE;
		return TRUE;
	}

	if (ryes) {
		// no need to see Lid
		int lid = lower_bound(a, a+n, make_pair(l+1, 0)) - a;
		int rid = Rid - 1;
		if (lid > rid) return MAYBE;
		int maxv = query(lid, rid);
		if (maxv >= a[Rid].second) return FALSE;
		if (!lyes) return MAYBE;
		if (r - l - 1 != rid - lid + 1) return MAYBE;
		return TRUE;
	}
	
	// ryes no yes
	if (!lyes) return MAYBE;
	
	// ryes no, and lyes yes
	int lid = lower_bound(a, a+n, make_pair(l+1, 0)) - a;
	int rid = Rid - 1;
	if (lid > rid) return MAYBE;
	int maxv = query(lid, rid);
	if (maxv >= a[Lid].second) return FALSE;
	return MAYBE;
}

		

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[i] = make_pair(x, y);
	}
	init();
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		int ans = solve(l, r);
		if (ans == MAYBE) puts("maybe");
		else if (ans == TRUE) puts("true");
		else puts("false");
	}
}
