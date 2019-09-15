#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
char s[MAXN], t[MAXN];
int n;
vector<pair<int, int>> v, ans;
int main() {
	scanf("%d", &n);
	scanf("%s%s", s, t);
	for (int i = 0; i < n; ++i) {
		if (s[i] == t[i]) continue;
		v.emplace_back(s[i]-'a', i);
	}
	sort(v.begin(), v.end());
	if (v.size() % 2) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < v.size(); i += 2) {
		int j = i + 1;
		if (v[i].first == v[j].first) {
			ans.emplace_back(v[i].second, v[j].second);
		} else {
			ans.emplace_back(v[i].second, v[i].second);
			ans.emplace_back(v[i].second, v[j].second);
		}
	}
	printf ("%d\n", ans.size());
	for (auto p: ans) {
		printf("%d %d\n", p.first+1, p.second+1);
	}
}

