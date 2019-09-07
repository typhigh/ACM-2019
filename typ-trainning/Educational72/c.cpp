#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
char s[MAXN];
int n;

int solve() {
	int ret = 0;
	int zero = 0;
	s[n] = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') ++zero;
		else {
			++ret; // 1
			int val = 1;
			int j = i + 1;
			while (j < n) {
				val = val * 2 + s[j] - '0';
				if (j - i + 1 + zero < val) break;
				else /* j - i + 1 +zero >= val*/ {
					++ret;
					++j;
				}
			}
			zero = 0;
		}
	}
	return ret;
}

			
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		n = strlen(s);
		printf("%d\n", solve());
	}
}
