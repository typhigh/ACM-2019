#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
char s[MAXN], t[MAXN];
int n;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s %s", s, t);
        int cnt = 0, last = -1, now = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                ++cnt;
                last = now;
                now = i;
            }
            
        }
        if (cnt == 1 || cnt > 2) puts("No");
        else if (cnt == 0) puts("Yes");
        else {
//            cout << now << " " << last << endl;
            swap(s[now], t[last]);
            int yes = true;
            for (int i = 0; i < n; ++i) if (s[i] != t[i]) yes = false;
            if (yes) puts("Yes");
            else puts("No");
        }
    }
}