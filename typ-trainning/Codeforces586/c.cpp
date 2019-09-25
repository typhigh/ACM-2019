#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500010;
char s[MAXN];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	char ch = s[0];
	puts("Mike");
	for (int i = 1; i < n; ++i) {
		if (s[i] > ch) puts("Ann");
		else puts("Mike");
		ch = min(ch, s[i]);
	}
}
