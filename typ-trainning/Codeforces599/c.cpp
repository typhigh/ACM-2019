#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;

int main() {
    cin >> n;
    LL m = sqrt(n+0.5) + 1;
    LL ans = n;
    for (int i = 2; i <= m && i < n; ++i) {
        if (n % i == 0) {
            ans = __gcd(ans, (LL)i);
            ans = __gcd(ans, n / i);
        }
    }
    cout << ans << endl;
}