#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200010;

int n, a[MAXN], cnt[64];
LL b[MAXN];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		LL c = __builtin_ctzll(b[i]);
//		cout << c << endl;
		a[i] = c;
		cnt[c]++;
	}
	int maxv = cnt[0], id = 0;
	for (int i = 1; i < 64; ++i) {
		if (maxv < cnt[i]) {
			maxv = cnt[i];
			id = i;
		}
	}
//	cout << id << endl;
	vector<LL> ans;
	for (int i = 0; i < n; ++i) {
		if (a[i] != id) ans.push_back(b[i]);
	}
	cout << ans.size() << endl;
	for (auto x: ans) 
		cout << x << " ";
}

