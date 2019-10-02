#include <bits/stdc++.h>
using namespace std;
const int MAXN = 205;
int p;
double f[MAXN];
bool vis[MAXN];

double DFS(int q2) {
	if (q2 >= 200) q2 = 200;
	if (vis[q2]) return f[q2];
	vis[q2] = true;
	double &d = f[q2];
	double q = q2 / 200.0;
	if (q2 == 200) {
		d = 100.0 / p;
	} else {
		d = 1.0 * p / 100 * (q + (1-q) * (1 + DFS(q2+4))) 
				+ (1.0 - p / 100.0) * (1 + DFS(q2+3));
	}
//	cout << q << " " << d << endl;
	return d;
}

int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &p);
		memset(vis, 0, sizeof(vis));
		printf("Case %d: %.7f\n", ++kase, DFS(4));
	}
}	
