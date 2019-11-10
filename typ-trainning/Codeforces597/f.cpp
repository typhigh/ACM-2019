#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int l, r;

LL solve(int a, int b) {
    assert(a >= b);
    if (b == 0) return 0;
    
}
LL solve() {
    LL ret = 0;
    if (l == 0) {
        ret += 2 * r + 1;
        ++l;
    }
    
    if (l > r) return ret;
    return solve(r, r) - 2*solve(r, l) + solve(l, l);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &l, &r);
        cout << solve() << endl;
    }

}