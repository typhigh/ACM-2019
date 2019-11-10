#include <bits/stdc++.h>
using namespace std;
int solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    for (int x = 0; x <= a; ++x) {
        int y = b - 2*x;
        if (y < 0) continue;
        int z = min(y, c / 2);
        ans = max(ans, x * 3 + z * 3);
    } 
    cout << ans << endl;
};
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}