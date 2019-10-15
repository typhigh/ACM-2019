#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
char s[MAXN][MAXN];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) 
			if ((i+j) & 1) s[i][j] = 'W';
			else s[i][j] = 'B';
	for (int i = 0; i < n; ++i) printf("%s\n", s[i]);
}
