#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
char s[MAXN];
int n;

bool Solve() {
	stack<int> st;
	bool used = false;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') st.push(1);
		else {
			if (st.empty()) {
				if (used) return false;
				used = true;
				continue;
			}
			st.pop();
		}
	}
	if (used) {
		if (st.empty()) return false;
		st.pop();
	}
	return st.empty();
}

int main() {
	scanf("%d%s", &n, s);
	bool yes = Solve();
	if (yes) puts("Yes");
	else puts("No");
}
