#include <bits/stdc++.h>
using namespace std;
int a[4];

bool yes() {
	int sum = a[0] + a[1] + a[2] + a[3];
	if (a[0] == a[1] && a[1] == a[2] && a[3] == a[4]) return true;
	if (sum & 1) return false;
	if (a[0] + a[3] == sum / 2) return true;
	if (a[0] + a[2] == sum / 2) return true;
	if (a[0] + a[1] + a[2] == sum / 2) return true;
	return false;

}

int main() {
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(a, a + 4);
	if (yes()) puts("YES");
	else puts("NO");
}
