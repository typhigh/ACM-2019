#include <bits/stdc++.h>
using namespace std;
int x[100];

int Query(int flag) {
	cout <<"?";
	for (int i = 0; i < 100; ++i) {
		cout << " " ;
		if (flag) cout << (x[i] << 7);
		else cout << x[i];
	}
	cout << endl;
	fflush(stdout);
	int ret;
	cin >> ret;
	return ret;
}
int main() {
	for (int i = 0; i < 100; ++i) x[i] = i+1;
	int x = Query(0) & (((1 << 7) - 1) << 7);
	int y = Query(1) & ((1 << 7) - 1);
	cout << "! " << (x|y) << endl;
}
