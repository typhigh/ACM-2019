#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int MAXN = 100010;
char s[MAXN];
int n;

LL fic[MAXN];
void init() {
    fic[0] = 1, fic[1] =1;
    for (int i = 2; i < MAXN; ++i) fic[i] = (fic[i-1] + fic[i-2]) % MOD;
}

LL Calc(int cnt) {
    return fic[cnt];
} 

LL solve() {
    n = strlen(s);
    s[n] = 0;
    int cnt = 1;
    LL res = 1;
    if (s[0] == 'm' || s[0] == 'w') return 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'm' || s[i] == 'w') return 0;

        if (s[i] == s[i-1]) ++cnt;
        else {
            if (s[i-1] == 'u' || s[i-1] == 'n') res = res * Calc(cnt) % MOD;
            cnt = 1;
        }
    }
    return (res % MOD + MOD) % MOD;
}

int main() {
    init();
    scanf("%s", s);
    cout << solve() << endl;
}