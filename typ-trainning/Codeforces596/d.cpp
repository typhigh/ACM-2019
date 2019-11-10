#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100010;
int n, k, a[MAXN], cnt[MAXN];
bool vis[MAXN];
vector<int> prime;

void init() {
    int m = sqrt(MAXN+0.5);
    for (int i = 2; i <= m; ++i) if (!vis[i]) 
        for (int j = i*i; j < MAXN; j += i) vis[j] = true;
    for (int i = 2; i < MAXN; ++i) if (!vis[i]) prime.push_back(i); 
}


LL Mul(LL x, LL y) {
    x = x * y;
    if (x >= MAXN) x = 0;
    return x;
}

LL calc(LL x, int k) {
    LL ret = 1;
    while (k--)
        ret =  Mul(ret, x);
    return ret;
}

LL getFac(int x, int k) {
    LL ret = 1;
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= x; ++i) {
        if (x % prime[i] == 0) {
            int now = 1;
            x /= prime[i];
            while (x % prime[i] == 0) {
                ++now;
                x /= prime[i];
            }
            now %= k;
            if (now) ret = Mul(ret, calc(prime[i], k - now));
            if (ret == 0) return 0;
        }
    }
    if (x != 1) ret = Mul(ret, calc(x, k-1));
    return ret;
}

LL getBase(int x, int k) {
    LL cx = 1;
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= x; ++i) {
//        cout << "!" << endl;
        if (x % prime[i] == 0) {
            int now = 1;
            x /= prime[i];
            while (x % prime[i] == 0) {
                ++now;
                x /= prime[i];
            }
            now %= k;
            cx = Mul(cx, calc(prime[i], now));
        } 
    }
    if (x != 1) cx = Mul(cx, x);
//    cout << x << " " << cx << endl;
    return cx;
}

LL Solve() {
    LL ret = 0;
    init();
    for (int i = 0; i < n; ++i) {
        int x = getFac(a[i], k);
//        cout << x << " " << cnt[x] << endl;
        ret += cnt[x];
        int base = getBase(a[i], k);
        assert(base > 0);
//        cout << base << endl;
        ++cnt[base];
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", a+i);
    cout << Solve() << endl;
}