#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
int n, m, a[MAXN];
long long sum[MAXN];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) sum[i] = a[i];
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (i > m) sum[i] += sum[i-m];
        ans += sum[i];
        cout << ans << " \n"[i==n];
    }
//    cout << ans << endl;
}