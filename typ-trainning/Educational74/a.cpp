#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		long long a, b;
		cin >> a >> b;
		if (a - b > 1) puts("YES");
		else puts("NO");
	}
}
