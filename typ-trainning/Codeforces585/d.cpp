#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
char s[MAXN];
int n;

int main() {
	scanf("%d", &n);
	scanf("%s", s);
	int sum = 0;
	int L = 0, R = 0;
	for (int i = 0; i < n / 2; ++i) {
		if (s[i] == '?') ++L;
		else sum += s[i] - '0';
	}
	for (int i = n / 2; i < n; ++i) {
		if (s[i] == '?') ++R;
		else sum -= s[i] - '0';
	}
	if (L < R) {
		swap(L, R);
		sum = -sum;
	}
	int res = (L - R) / 2;
	if (res * 9 == -sum) puts("Bicarp");
	else puts("Monocarp");
}
		
