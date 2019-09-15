#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400100;
const int MAXC= 20;
typedef long long LL;
const LL INF64 = 1LL << 60;
int n, size[1<<MAXC];
vector<int> a[MAXC];
vector<LL> sum[MAXC];
LL dp[1<<MAXC];

void update(LL& x, LL d) {
	x = min(x, d);
}

LL SegSum(int from, int to) {
	if (to < from) return 0;
	return 1LL * (from + to) * (to - from + 1) / 2;
}

LL Calc(int c, int from) {
	vector<int> & p = a[c];
	vector<LL> & pp = sum[c];
	cout << c << " " << from << " " << p.size() << endl;
	assert(pp.size() == p.size());
	if (p.size() == 0) return 0;
	int l = 0, r = p.size() - 1;
	if (p[0] >= from) 
		return pp[r] - SegSum(from, from + r);
	if (p[r] <= from+ r) 
		return SegSum(from, from + r) - pp[r];
	while (l < r) {
		int mid = (l+r) >> 1;
		if (p[mid] > from + mid) r = mid;
		else l = mid + 1;
	}
	return pp[pp.size()-1] - pp[l-1] - SegSum(from + l, from + p.size() - 1) + (SegSum(from, from + l-1) - pp[l-1]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int c;
		scanf("%d", &c);
		--c;
		a[c].push_back(i);
	}
	for (int i = 0; i < MAXC; ++i) {
		LL x = 0;
		for (int j = 0; j < a[i].size(); ++j) {
			x += a[i][j];
			sum[i].push_back(x);
		}
	}
//	int S0 = (1 << MAXC) - 1;
	int S0 = 7;
	memset(dp, 0x3f, sizeof(dp));
	size[0] = dp[0] = 0;
	for (int s = 1; s <= S0; ++s) {
		for (int i = 0; i < MAXC; ++i) 
			if ((1<<i) & s) {
				size[s] = size[s^(1<<i)] + a[i].size();
//				printf("[%d]: %d\n", s, size[s]);
				break;
			}
		for (int i = 0 ;i < MAXC; ++i) {
			if ((1<<i) & s) {
//				cout << i << endl;
				update(dp[s], dp[s^(1<<i)] + Calc(i, size[s^(1<<i)]));
			}
		}
	}
	for (int i = 0; i < 8; ++i) cout << dp[i] << " \n"[i==7];
	cout << dp[S0] / 2 << endl;
}
