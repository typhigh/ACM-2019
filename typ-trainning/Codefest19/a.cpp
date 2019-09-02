#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int a, b, n;
		cin >> a >> b >> n;
		n %= 3;
		int ans;
		if (n == 0) ans = a;
		else if (n == 1) ans = b;
		else ans = a ^ b;	
		cout << ans << endl;
	}	
}
