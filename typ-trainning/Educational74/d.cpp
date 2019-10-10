#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 300010;
int n;
char s[MAXN];
int len, a[MAXN];

LL solve() {
	len = 1;
	a[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] == s[i-1]) ++a[len-1];
		else a[len++] = 1;
	}
	LL ans = 1LL * n * (n-1) / 2;
	for (int i = 1; i < len; ++i) 
		ans -= a[i-1] + a[i]-1;
	return ans;
}
int main() {
	scanf("%d %s", &n, s);
	cout << solve() << endl;
}
