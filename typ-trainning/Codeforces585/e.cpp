#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXC = 20;
vector<int> a[MAXC];
LL dp[1<<MAXC], cal[MAXC][MAXC];
int n;

LL Calc(int x, int y) {
	LL ret = 0;
	if (x == y) {
		return ret;
	}
	vector<int>& L = a[x];
	vector<int>& R = a[y];
	for (int i = 0, j = -1; i < L.size(); ++i) {
		while(j + 1 < R.size() && L[i] > R[j+1]) ++j;
		ret += j + 1;
	}
	return ret;
}

void init() {
	for (int i = 0; i < MAXC; ++i) {
		for (int j = 0; j < MAXC; ++j) {
			cal[i][j] = Calc(i, j);		
//			cout << cal[i][j] << " ";
		}
//		cout << endl;
	}
}

void update(LL& x, LL d) {
//	cout << x << " " << d << endl;
	x = min(x, d);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int u;
		scanf("%d", &u);
		a[u-1].push_back(i);
	}
	init();
	int S0 = (1 << MAXC) - 1;
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int s = 0; s < S0; ++s) {
		for (int i = 0; i < MAXC; ++i) if (!((1<<i)&s)) {
			LL sum = 0;
			for (int j = 0; j < MAXC; ++j) if ((1<<j)&s)
				sum += cal[i][j];
			update(dp[s|(1<<i)], dp[s] + sum); 
		}
	}
	cout << dp[S0] << endl;
}
