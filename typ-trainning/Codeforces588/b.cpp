#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;

int n, k;
char s[MAXN];

void solve() {
	if (k == 0) {
		printf("%s", s);
		return;
	} 
	if (n == 1) {
		puts("0");
		return;
	}
	// n > 1 && k > 0
	if (s[0] != '1') {
		s[0] = '1';
		--k;
	}
	for (int i = 1, j = 0; i < n && j < k; ++i) {
		if (s[i] != '0') {
			s[i] = '0';
			++j;
		}
	}
	printf("%s\n", s);
}

int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	solve();
}
