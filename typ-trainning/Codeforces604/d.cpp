#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int a, b, c, d;
int n, ans[MAXN];

bool solve() {
    if (abs(a + c - b - d) > 1) return false;
    int m = n;
    int tot = 0;
    if (a + c >= b + d) {
        if (c == 0) {
            if (d) return false;
        }
        else if (b < a) return false;
        if (m % 2 == 0) ++c;
        for (int i = 0; i < a; ++i) {
            ans[tot++] = 0;
            ans[tot++] = 1;
        }
        b -= a;
        for (int i = 0; i < c-1; ++i) {
            ans[tot++] = 2;
            if (b) {
                ans[tot++] = 1;
                --b;
            } else {
                ans[tot++] = 3;
            }
        }
        if (c) ans[tot++] = 2;
    } else {
        // a + c < b + d
        if (b == 0) {
            if (a) return false;
        }
        else if (c < d) return false;
        for (int i = 0; i < d; ++i) {
            ans[tot++] = 3;
            ans[tot++] = 2;
        }
        c -= d;
        for (int i = 0; i < b-1; ++i) {
            ans[tot++] = 1;
            if (c) {
                ans[tot++] = 2;
                --c;
            } else {
                ans[tot++] = 0;
            }
        }
        if (b) ans[tot++] = 1;
    }
    return true;
}

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    n = a + b + c + d;
    if (solve()) {
        puts("YES");
        for (int i = 0; i < n; ++i) printf("%d%c", ans[i], " \n"[i==n-1]); 
    } else {
        puts("NO");
    }
}