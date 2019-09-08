#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
int n, x, y, a[MAXN];

bool check(int id) {
	for (int i = 0; i < x; ++i) 
		if (id - i - 1 > 0 && a[id] > a[id-i-1]) return false;
	for (int i = 0; i < y; ++i) 
		if (id + i + 1 <= n && a[id] > a[id+i+1]) return false;
	return true;
}

int main() {
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; ++i) {
		if (check(i)) {
			cout << i << endl;
			break;
		}
	}
}
