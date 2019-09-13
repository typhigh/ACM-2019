#include <bits/stdc++.h>
using namespace std;

int main() {
	int b, g, n;
	scanf("%d%d%d", &b, &g, &n);
	int ans = 0;
	for (int i = 0 ; i <= min(n, b); ++i) 
		if (n - i <= g) ++ans;
	cout << ans << endl;
}
