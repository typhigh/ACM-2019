#include <bits/stdc++.h>
using namespace std;

bool check(int x, int y) {
    if (x >= y) return true;
    if (x >= 4) return true;
    if (x == 1) return y == 1;
    return y <= 3;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (check(x, y)) puts("YES");
        else puts("NO");
    }
}