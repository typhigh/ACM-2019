#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300010;
char s[MAXN];
int A, B;

bool solve() {
	int n = strlen(s);
	s[n] = 'X';
	int cnt = 0;
	int nowc = 0;
	int now = -1;
	int odd = 0;
	for (int i = 0; i <= n; ++i) {
		if (s[i] == 'X') {
			if (cnt < B) {
				cnt = 0;
				continue;
			}
			// cnt >= B
			if (cnt < A) return false;
			// cnt >= A
			if (cnt < 2 * B) {
				odd ^= 1;
				cnt = 0;
				continue;
			}
			// cnt >= A && cnt >= 2B
			now = cnt;
			nowc++;
			cnt = 0;
		} else 
			++cnt;
	}
//	cout << now << " " << nowc << endl;
	if (nowc >= 2) return false;
	if (nowc == 0) return odd;
	if (now == -1) while(1);
	// now != -1 now >= 2B
	now -= A;
	if (A >= 2*B) {
		if (now <= 2*B-2) return odd ^ 1;
		return false;
	}
	// A < 2B and now + A >= 2B
	if (now >= 4*B-1) return false;
	int flag = 0;
	if (now >= A && now <= 3*B-2) flag |= 2;
	if (now >= 2 * A && now <= 4*B-2) flag |= 1;
	if (now <= 2*B-2) flag |= 1;
//	cout << flag << " " << odd << " " << now << endl;
	if (flag == 3) return true;
	if (flag == 1) return odd ^ 1;
	if (flag == 2) return odd;
	return false;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
//		int a, b;
		scanf("%d %d", &A, &B);
		scanf("%s", s);
		if (solve()) puts("YES");
		else puts("NO");
	}
}
