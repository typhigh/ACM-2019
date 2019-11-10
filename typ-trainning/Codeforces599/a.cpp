#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int n, a[MAXN];

int solve() {
    for (int i = 0; i < n; ++i) {
        if (a[i] >= n - i) return n - i;
    }
    while(1);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", a + i);
        sort(a, a + n);
        cout << solve() << endl;
    }
}