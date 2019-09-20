#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1003;

LL M[MAXN][MAXN];
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= 3; ++i) 
		for (int j = 1; j <= n; ++j) cin >> M[i][j];
	LL x = M[3][1];
	LL y = M[3][2];
	LL d = x * M[1][2] / y;
	d = sqrt(d+0.5);
	vector<LL> ans;
	ans.push_back(d);
	for (int i = 2; i <= n; ++i) 
		ans.push_back(M[1][i] / d);
	for (auto x : ans)
		cout << x << " ";
	cout << endl;
}
