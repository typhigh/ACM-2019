#include <bits/stdc++.h>
using namespace std;

void get_z(char *s, int* z) {
  int l = 1, r = 1, n = strlen(s + 1);
  for (int i = 2; i <= n; i ++) {
    if (i > r) {
      l = r = i;
      while (r <= n && s[r - l + 1] == s[r]) r ++;
      z[i] = r - l; r --;
    } else {
      int k = i - l + 1;
      if (z[k] < r - i + 1) z[i] = z[k];
      else {
        l = i;
        while (r <= n && s[r - l + 1] == s[r]) r ++;
        z[i] = r - l; r --;
      }
    }
    cout << z[i] << ' ';
  }
}

const int MAXN = 1000100;
char s[MAXN];
int z[MAXN];
int main() {
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s+1);
		get_z(s, z);
//		int Len = strlen(s+1);
//		int ans = Len + Len - z[1];
//		cout <<"Case " << (++kase) << ": " << ans << endl;
	}
}
