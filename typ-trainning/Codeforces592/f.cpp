#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400010;
char s[MAXN];
int n, k;

struct node {
	int L, R;
	bool operator < (const node& rhs) const {
		return R - L < rhs.R - rhs.L;
	}
};

void solve() {
	for (int i = 0; i < n; ++i) s[i+n] = s[i];
	s[n+n] = s[0];
	vector<node> q;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] != s[i-1] && s[i] != s[i+1]) {
			++cnt;
			continue;
		}
		else if (cnt) {
			q.push_back(node{i-cnt, i-1});
		}
		cnt = 0;
	}
	if (cnt) q.push_back(node{n-cnt+1 , n});
	
	if (q.size() == 1 && q[0].L == 1 && q[0].R == n) {
		if (k&1) for (int i = 0; i < n; ++i) {
			s[i] = s[i+1];
		}
		s[n] = 0;
		printf("%s\n", s);
		return;
	}
	int from = 1;
	if (q.size() > 1 && q[0].L == 1 && q[q.size()-1].R == n) {
		from = q[0].R+1;
		q[0].L = q[q.size()-1].L;
		q[0].R = q[0].R+n;;
		q.pop_back();
	}
//	cout << from << endl;
	sort(q.begin(), q.end());
//	for (auto p: q) cout << p.L << " " << p.R << " ";
//	cout << endl;
	int L = 0;
	int kk = k;
	while (L < q.size() && kk--) {
		for (int i = L; i < q.size(); ++i) {
			int l = q[i].L;
			int r = q[i].R;
			s[l] = s[l-1];
			s[r] = s[r+1];
			if (r - l + 1 <= 2) ++L;
			else ++q[i].L, --q[i].R;
		}
//		printf("%s\n", s); 
//		cout << kk << endl;
	}
	
//	printf("%s\n", s);
	if (k & 1) {
//		puts("yes");
//		printf("%d %d\n", L, q.size());
		for (int i = L; i < q.size(); ++i) {
//			cout << q[i].L << " " << q[i].R << endl;
			for (int x = q[i].L; x <= q[i].R; ++x) {
				if (s[x] == 'B') s[x] = 'W';
				else s[x] = 'B';
			}
		}
	}
//	printf("%s\n", s);
	for (int i = 0; i < from; ++i) s[i] = s[i+n];
	s[n] = 0;
	printf("%s\n", s);
}
int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	solve();
}
