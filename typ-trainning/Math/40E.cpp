#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
typedef long long LL;
int n, m, k, p, two[MAXN];
bool Swap;
vector<int> a[MAXN];

LL solve() {
    LL ret = 1;
    if ((n & 1) != (m & 1)) return 0;
    bool flag = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i].size() == 0) {
            if (!flag) {
                flag = true;
                continue;
            }
        }
        
        if (a[i].size() == m) {
            int msum = 1;
            for (int j = 0; j < m; ++j) msum *= a[i][j];
            if (msum != -1) return 0;
            continue;
        }
//        cout << i << endl;
        ret = ret * two[m-1-a[i].size()] % p;
    } 
    return ret;
}

void init() {
    two[0] = 1;
    for (int i = 1; i < MAXN; ++i) two[i] = 2LL * two[i-1] % p;
}
int main() {
    Swap = false;
    scanf("%d %d %d" , &n, &m, &k);
    if (n < m) {
        swap(n, m);
        Swap = true;
    }
    for (int i = 0; i < k; ++i) {
        int x, y, val;
        scanf("%d %d %d", &x, &y, &val);
        if (Swap) swap(x, y);
        a[x].emplace_back(val);
    }
    scanf("%d", &p);
    init();
    cout << solve() << endl;
}