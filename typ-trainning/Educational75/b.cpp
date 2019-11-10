#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;
char s[MAXN];
int n;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        bool flag = false;
        int one = 0, zero = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            int m = strlen(s);
            if (m & 1) {
                flag = true;
            }
            for (int i = 0; i < m; ++i) {
                if (s[i] == '1') ++one;
                else ++zero;
            } 
        }
        if (flag) printf("%d\n", n);
        else if (one & 1) printf("%d\n", n-1);
        else printf("%d\n", n);
    }
}