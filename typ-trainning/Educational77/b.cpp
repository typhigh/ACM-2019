#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b;
        scanf("%d %d", &a, &b);
        if ((a + b) % 3) {
            puts("NO");
            continue;
        }
        if (2 * a >= b && 2 * b >= a) puts("YES");
        else puts("NO");
    }
}