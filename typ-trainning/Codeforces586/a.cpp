#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
char s[MAXN];

int main() {
	int n, zero = 0;
	scanf ("%d %s", &n, s);
	for (int i = 0; i < n; ++i) zero += s[i] == 'z';
	int one = (n - 4*zero) / 3;
	for (int i = 0; i < one; ++i) printf("1 ");
	for (int i = 0; i < zero; ++i) printf("0 ");
	puts("");
}
