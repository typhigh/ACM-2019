#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int x = b / a;
        int cnt = b - a * x;
        printf("%d\n", cnt * (x+1) * (x+1) + (a - cnt) * x * x);
    }
}