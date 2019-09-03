#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int b, p, f, h, c;
		cin >> b >> p >> f >> h >> c;
		int ans = 0;
		for (int i = 0; i <= p; ++i) 
			for (int j = 0; j <= f; ++j) 
				if (2 * i + 2 * j <= b) 
					ans = max(ans, h * i + c * j);
		cout << ans << endl;
	}
}
