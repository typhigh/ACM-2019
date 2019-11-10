#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 300100;
const LL MOD = 1e9 + 7;
int n, k;
LL fac[MAXN], inv[MAXN];

LL quick_pow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; ++i) fac[i] = fac[i-1] * i % MOD;
    inv[MAXN-1] = quick_pow(fac[MAXN-1], MOD-2);
    for (int i = MAXN-2; i >= 0; --i) inv[i] = inv[i+1] * (i+1) % MOD;
    assert(inv[0]==1);
}

LL C(int n, int m) {
    if (m > n) return 0;
    return fac[n] * inv[m] % MOD * inv[n-m] % MOD;
}

LL S(int m, int n) {
//    cout << "!! " << n << " " << m << endl;
    if (n > m) return 0;
    LL ret = 0;
    for (int i = 0; i <= n; ++i) {
        int flag = (i & 1) ? -1 : 1;
        LL now = C(n, i) * flag * quick_pow(n - i, m) % MOD;
//        cout << C(n, i) << " " << quick_pow(n-i, m) << endl;
        ret = (ret + now) % MOD; 
    }
//    cout << ret << endl;
    return ret * inv[n] % MOD;
}

int main() {
    init();
    scanf("%d %d", &n, &k);
    LL sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sum = (sum + x) % MOD;
    }    
    sum = sum * (S(n-1, k-1) + (n + k -1) * S(n-1, k) % MOD) % MOD;
    sum = (sum % MOD + MOD) % MOD;
    cout << sum << endl;
}
