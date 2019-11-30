#include <bits/stdc++.h>
using namespace std;
int a, b, c;

int solve() {
    if (a < b) swap(a, b);
    if (a < c) swap(a, c);
    if (a > b + c) return b + c;
    return (a + b + c) / 2;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", solve());
    }
}