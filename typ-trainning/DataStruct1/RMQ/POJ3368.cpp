#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<memory>
#include<vector>
#include<cassert>
#include<map>

using namespace std;
const int MAXN = 100010;
int n, a[MAXN], d[MAXN][20];
// id->node
struct node {
	int val, L, R;
};

vector<node> v;
map<int, int> ID;

void init() {
	for (int i = 0; i < v.size(); ++i) d[i][0] = v[i].R - v[i].L + 1;
	for (int k = 1; (1 << k) <= v.size(); ++k) 
		for (int i = 0; i + (1<<k) -1 < v.size(); ++i) 
			d[i][k] = max(d[i][k-1], d[i+(1<<k-1)][k-1]);
}

int RMQQ(int l, int r) {
	int k = 0;
	while ((1 << k) <= r - l + 1) ++k;
	return max(d[l][k-1], d[r-(1<<k-1)+1][k-1]);
}

int query(int l, int r) {
	if (a[l] == a[r]) return r - l + 1;
	int x = ID[a[l]];
	int y = ID[a[r]];
	int ans = max(v[x].R - l + 1, r - v[y].L + 1);
	if (x + 1 < y) {
		++x;
		--y;
		ans = max(ans, RMQQ(x, y));
	}
	return ans;
}

int main() {
	while (~scanf("%d", &n) && n) {
		ID.clear();
		v.clear();
		int q;
		scanf("%d", &q);
		int tot = 0;
		for (int i = 1; i <= n; ++i) scanf("%d", a + i);
		for (int i = 1, j; i <= n; i = j) {
			assert(!ID.count(a[i]));
			int id = ID.size();
			ID[a[i]] = id;
			j = upper_bound(a+1, a+n+1, a[i]) - a;
			v.push_back(node{a[i], i, j-1});
		}
		init();
		while (q--) {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n", query(x, y));
		}
	}
}
