#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int n, L[MAXN], R[MAXN];

char ans[MAXN];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            L[x] = R[x] = i;
        }
        for (int i = 2; i <= n; ++i) {
            L[i] = min(L[i], L[i-1]);
            R[i] = max(R[i], R[i-1]);
        }
        for (int i = 1; i <= n; ++i) {
            if (R[i] - L[i] + 1 == i) ans[i] = '1';
            else ans[i] = '0';
        }
        ans[n+1] = 0;
        printf("%s\n", ans+1);
    }
}