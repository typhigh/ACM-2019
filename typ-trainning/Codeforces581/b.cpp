#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, l, r;
	cin >> n >> l >> r;
	int one = n - l + 1;
	int minv = one;
	for (int x = 2, i = 0; i < n - one; ++i, x = x * 2) {
		minv += x;
	}
	
	one = 1;
	int maxv = one;
	int x = 2;
	for (int i = 0; i < r - one; ++i, x = x * 2) {
		maxv += x;
	}
	maxv += (n - r) * (x / 2);
	cout << minv << " " << maxv << endl;
}
