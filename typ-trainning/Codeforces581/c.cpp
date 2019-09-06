#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MAXM = 1000100;
const int INF = 0x3f3f3f3f;
char g[MAXN];
int n, d[MAXN][MAXN], p[MAXM];
int top, st[MAXM];

void Init() {
	for (int k = 1; k <= n; ++k) 
		for (int i = 1; i <= n; ++i) 
			for (int j = 1; j <= n; ++j) 
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	
//	cout << n << endl;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) 
//			cout << d[i][j] << " ";
//		cout << endl;
//	}
}


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", g+1);
		for (int j = 1; j <= n; ++j) 
			d[i][j] = g[j] == '1' ? 1 : INF;
		d[i][i] = 0;
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) scanf("%d", p + i);	
	Init();
	st[top++] = p[0];
	st[top++] = p[1];
	for (int i = 2; i < m; ++i) {
		while (top >= 2 && d[st[top-2]][st[top-1]] + d[st[top-1]][p[i]] == d[st[top-2]][p[i]]) 
			--top;
		st[top++] = p[i];
	}
	printf("%d\n", top);
	for (int i = 0; i < top; ++i) printf("%d%c", st[i], " \n"[i == top - 1]);
}
