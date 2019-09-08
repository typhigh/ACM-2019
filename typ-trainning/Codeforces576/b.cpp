#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	LL H, L;
	cin >> H >> L;
	double x = (L * L - H * H) / (2.0 * H);
	printf("%.7f\n", x);
}
