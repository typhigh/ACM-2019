#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int n;
char s[MAXN];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", s);
		int Len = n+1;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '1') Len = min(Len, min(i, n - i - 1));
		}
		int ans;
		if (Len == n+1) ans = n;
		else ans = 2 * (n - Len);
		cout << ans << endl;
	}
}
