#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4010;
int n, a[MAXN][MAXN];

int main() {
	scanf("%d", &n);
	assert(n % 4 == 0);
	int m = n / 2;
	int val = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j) 
			for (int k = 0; k < 4; ++k)
				a[i*2 + k / 2][j*2 + k % 2] =  val++;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			printf("%d%c", a[i][j], " \n"[j == n - 1]);
}
