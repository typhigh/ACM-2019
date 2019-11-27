#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int MAXN = 1000100;
bool check[MAXN];
int prime[MAXN], mu[MAXN];
LL Ans[MAXN];

void Moblus() {
    memset(Ans, -1, sizeof(Ans));
    memset(check, false, sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for (int i = 2; i < MAXN; ++i) {
        if (!check[i]) {
            prime[tot++] = i;
            mu[i] = -1;
        } 
        for (int j = 0; j < tot; ++j) {
            if (i * prime[j] >= MAXN) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}

LL f(LL n) {
    if (n < MAXN && ~Ans[n]) return Ans[n];
    LL ans = 0;
    for (LL i = 1, la = 0; i <= n; i = la + 1) {
        la = n/(n/i);
        ans += (la - i + 1) * (n / i);
        ans %= MOD;
    }
    if (n < MAXN) Ans[n] = ans;
    return ans;
}

LL n;
int main() {
    Moblus();
    int T, kase = 0;
    scanf("%d", &T);
    while (T--) {
        cin >> n;
        LL ans = 0;
        for (int i = 1; (LL) i * i <= n; ++i) {
            if (mu[i]) ans = (ans + mu[i] * f(n / i / i)) % MOD; 
        }
        ans = (ans % MOD + MOD) % MOD;
        printf("Case #%d: %lld\n", ++kase, ans);
    }
}