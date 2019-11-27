#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int c = __gcd(a, b);
        if (c > 1) puts("Infinite");
        else puts("Finite");
    }
}