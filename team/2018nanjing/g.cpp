#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
const LL inv2 = 5e8 + 4;

LL quick_pow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

int main() {
    LL e = quick_pow(24, MOD-2);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        LL ans = 1LL * n * (n+1) % MOD * (n+2) % MOD * (n+3) % MOD * e % MOD;
        printf("%d\n", (int)ans);
    }
}