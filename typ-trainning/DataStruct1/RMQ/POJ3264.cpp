#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<memory>
using namespace std;

const int MAXN = 50010;
int maxv[MAXN][20];
int minv[MAXN][20];
int n, a[MAXN];

void init() {
	for (int i = 1; i <= n; ++i) maxv[i][0] = minv[i][0] = a[i];
	for (int k = 1; (1 << k) <= n; ++k) 
		for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
			minv[i][k] = min(minv[i][k-1], minv[i+(1<<k-1)][k-1]);
			maxv[i][k] = max(maxv[i][k-1], maxv[i+(1<<k-1)][k-1]);
		}
}

int query(int L, int R) {
	int k = 0;
	while ((1 << k) <= R - L + 1) ++k;
	int b = max(maxv[L][k-1], maxv[R-(1<<k-1)+1][k-1]);
	int c = min(minv[L][k-1], minv[R-(1<<k-1)+1][k-1]);
	return b - c;
}

int main() {
	int q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	init();
	while (q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", query(x, y));
	}
}
