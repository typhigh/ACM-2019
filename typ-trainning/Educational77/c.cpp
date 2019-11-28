#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x, y, k;
        scanf("%d %d %d", &x, &y, &k);
        if (x > y) swap(x, y);
        int g = __gcd(x, y);
        x /= g, y /= g;
        if (y == 1) {
            puts("OBEY");
            continue;
        }
        int ans = (y - 2) / x + 1;
        if (ans >= k) puts("REBEL");
        else puts("OBEY");
    }
} 