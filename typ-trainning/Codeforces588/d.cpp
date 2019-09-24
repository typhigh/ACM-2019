#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 7500;
pair<LL,int> a[MAXN];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) cin >> a[i].first;
	for (int i = 0; i < n; ++i) scanf("%d", &a[i].second);
	sort(a, a + n);
	LL ans = 0;
	vector<LL> q;
//	set<LL> s;
	for (int i = 0; i < n; ++i) {
		if (i && a[i-1].first == a[i].first) {
			ans += a[i].second;
//			cout << i << endl;
			continue;
		}
		if (i+1 < n && a[i].first == a[i+1].first) { 
			ans += a[i].second;
			q.push_back(a[i].first);
//			cout << i << endl;
//			s.insert(a[i].first):
		}
	}
	
	for (int i = 0; i < n; ++i) {
		auto iter = lower_bound(q.begin(), q.end(), a[i].first);
		if (iter == q.end()) continue;
		if (*iter == a[i].first) continue;
		for (;iter != q.end(); ++iter) {
			LL x = *iter;
			if ((x & a[i].first) == a[i].first) {
				ans += a[i].second;
//				cout << i << endl;
				break;
			}
		}
	}
	cout << ans << endl;
}
