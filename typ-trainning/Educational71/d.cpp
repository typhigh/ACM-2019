#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 998244353;
const int MAXN = 300010;
vector<pair<int, int>> s;
vector<int> xs, ys;
LL fac[MAXN];
int n;
void Init() {
	fac[0] = 1;
	for (int i = 1; i < MAXN; ++i) fac[i] = fac[i-1] * i % mod;
}

LL Calc(vector<int> &x) {
	sort(x.begin(), x.end());
	LL ret = 1;
	int count = 1;
	for (int i = 1; i < x.size(); ++i) {
		if (x[i] == x[i-1]) ++count;
		else {
			ret = ret * fac[count] % mod;
			count = 1;
		}
	}
	ret = ret * fac[count] % mod;
	return ret;
}

LL Calc(vector<pair<int, int>> x) {
	sort(x.begin(), x.end());
	for (int i = 0; i < x.size() - 1; ++i) {
		if (!(x[i].first <= x[i+1].first && x[i].second <= x[i+1].second)) 
			return 0;
	}
	LL ret = 1;
	int count = 1;
	for (int i = 1; i < x.size(); ++i) {
		if (x[i] == x[i-1]) ++count;
		else {
			ret = ret * fac[count] % mod;
			count = 1;
		}
	}
	ret = ret * fac[count] % mod;
	return ret;
}

int main() {
	Init();
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		s.emplace_back(x, y);
		xs.push_back(x);
		ys.push_back(y);
	}
	LL ans = fac[n];
	ans -= Calc(xs);
	ans -= Calc(ys);
	ans %= mod;
	ans += Calc(s);
	ans = (ans % mod + mod) % mod;
	cout << ans << endl;
}

