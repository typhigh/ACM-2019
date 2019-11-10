#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
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
    LL a, b;
    cin >> a >> b;
    LL ans = (quick_pow(2, b) - 1);
    ans = quick_pow(ans, a);
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << endl;
}