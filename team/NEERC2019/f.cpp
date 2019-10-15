#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100100;
bool vis[MAXN];
vector<int> prime;
int n;

void exgcd(LL a, LL b, LL& d, LL& x, LL& y) {
	if (!b) { d = a; x = 1; y = 0;}
	else { exgcd(b, a%b, d, y, x); y -= x * (a/b);}
}

void init() {
	int m = sqrt(MAXN + 0.5);
	for (int i = 2; i <= m; ++i) if (!vis[i]) 
		for (int j = i*i; j < MAXN; j += i) vis[j] = 1;
	for (int i = 2; i < MAXN; ++i) if (!vis[i]) prime.push_back(i);
}

bool check(int x, int& p1, int& p2) {
	for (int i = 0; i < prime.size() && prime[i] * prime[i] <= x; ++i) {
		if (x % prime[i] == 0) {
			p1 = prime[i];
			x /= prime[i];
			while (x % prime[i] == 0) {
				x /= prime[i];
				p1 *= prime[i];
			}
			p2 = x;
			if (x == 1) return false;
			return true;
		}
	}
	return false;
}

int main() {
	init();
	scanf("%d", &n);
	int p1, p2;
	if (check(n, p1, p2)) {
		puts("YES");
//		printf("%d %d\n", p1, p2);
		cout << 2 << endl;
		LL d, x, y;
		exgcd(p1, p2, d, y, x);
		assert(d == 1);
		x = -x, y =-y;
//		cout << x << " " << y << endl;
		if (x < 0) x += p1;
		else y += p2;
		cout << x << " " << p1 << endl;
		cout << y << " " << p2 << endl;
	} else puts("NO");
}
