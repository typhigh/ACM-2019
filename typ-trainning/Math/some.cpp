#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100010;
char ns[MAXN];
int m, d, k, n1, n2;
const int MOD1 = 643;
const int MOD2 = 93257;

LL quick_pow(LL a, LL b, const int MOD) {
    LL ret = 1;
    while (b) {
        if (b&1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

bool check[MAXN];
int prime[MAXN];
int mu[MAXN];
void Moblus() {
    memset(check, false, sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for (int i = 2; i < MAXN; ++i) {
        if ( !check[i] ) {
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

LL Sum1[MAXN];
LL solve(const int MOD, int n) {
    Sum1[0] = 0;
    for (int i = 1; i <= m; ++i) Sum1[i] = (Sum1[i-1] + quick_pow(i, k, MOD)) % MOD;
    LL dk = quick_pow(d, k, MOD);
    LL dnk = quick_pow(dk, n, MOD);
    int mm = m / d;
    LL ans = 0;
    for (int i = 1; i <= mm; ++i) {
        if (mu[i] == 0) continue;
        ans += mu[i] * quick_pow(Sum1[mm/i] * quick_pow(i, k, MOD) % MOD, n, MOD) % MOD;
        ans %= MOD;
    }
    ans = (ans * dnk % MOD + MOD) % MOD;
    return ans;
}

void exgcd(LL a, LL b, LL& d, LL& x, LL& y) {
	if (!b) {
        d = a; x = 1; y = 0;
    }
    else {
    	exgcd(b, a % b, d, y, x);
        y -= x*(a/b);
    }
}

LL china(int n, int* a, int *m) {
	LL M = 1, d, y, x= 0;
    for (int i = 0; i < n; ++i) M *= m[i];
    for (int i = 0; i < n; ++i) {
        LL w = M / m[i];
        exgcd(m[i], w, d, d, y);
        x = (x + y * w * a[i]) % M;
    }
    return (x + M) % M;
}

int a[2], M[2];
int solve() {
//    cout << n1 << " " << n2 << endl;
	LL ans1 = solve(MOD1, n1);
    LL ans2 = solve(MOD2, n2);
//    cout << ans1 << " " << ans2 << endl;
	a[0] = ans1; a[1] = ans2;
    M[0] = MOD1; M[1] = MOD2;
    LL ans = china(2, a, M);
    ans = (ans % (MOD1 * MOD2)+ MOD1 * MOD2) % (MOD1 * MOD2);
    return ans;
}

int main() {
    Moblus();
    int T;
    scanf("%d", &T);
    while (T--) {
    	scanf("%s", ns);
        int len = strlen(ns);
        n1 = n2 = 0;
        for (int i = 0; i < len; ++i) {
            n1 = n1 * 10 + ns[i] - '0';
            n2 = n2 * 10 + ns[i] - '0';
            if (n1 >= MOD1-1) n1 %= (MOD1-1);
            if (n2 >= MOD2-1) n2 %= (MOD2-1);
        }
        scanf("%d %d %d", &m, &d, &k);
    	printf("%d\n", solve());
    }
}