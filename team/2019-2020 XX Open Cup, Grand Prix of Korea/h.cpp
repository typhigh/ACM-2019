#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300100;
typedef long long LL;
int n, a[MAXN], b[MAXN];
bool vis[MAXN];

LL solve1() {
    vector<int> v, to;
    for (int i = 1; i <= n; ++i) if (a[i] <= (n+1)/ 2) v.push_back(i);
    for (int i = 1; i <= n; ++i) if (b[i] > n / 2) to.push_back(i);
    LL ans = 0;
    for (int i = 0; i < v.size(); ++i) ans += abs(v[i] - to[i]);
    return ans;
}

LL solve2() {
    vector<int> v, to;
    for (int i = 1; i <= n; ++i) if (a[i] <= n / 2) v.push_back(i);
    for (int i = 1; i <= n; ++i) if (b[i] > (n+1) / 2) to.push_back(i);
    LL ans = 0;
    for (int i = 0; i < v.size(); ++i) ans += abs(v[i] - to[i]);
    return ans;
}
int main() {
    vector<int> v, to;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", b+i);
    }
    cout << min(solve1(), solve2()) << endl;;
}