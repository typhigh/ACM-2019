#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int a1, b1, c1, n;
        int a2 = 0, b2 = 0, c2 = 0;
        cin >> n >> a1 >> b1 >> c1;
        string RPS;
        cin >> RPS;
        string ans;
        ans.resize(n);
        for (int i = 0; i < n; ++i) ans[i] = 0;
        for (int i = 0; i < n; ++i) {
            if (RPS[i] == 'R') {
                if (b1) {
                    --b1;
                    ans[i] = 'P';
                }
            } else if (RPS[i] == 'P') {
                if (c1) {
                    --c1;
                    ans[i] = 'S';
                }
            }
            else {
                if (a1) {
                    --a1;
                    ans[i] = 'R';
                }
            }
        }
        int m = 0;
        for (int i = 0; i < n; ++i) m += ans[i]!= 0;
//        cout << m << endl;
        if (m * 2 >= n) {
            puts("YES");
            for (int i = 0; i < n; ++i) {
                if (ans[i] != 0) continue;
                if (a1) {
                    ans[i] = 'R';
                    --a1;
                } else if (b1) {
                    ans[i] = 'P';
                    --b1;
                } else {
                    ans[i] = 'S';
                    --c1;
                }
            }
            cout << ans << endl;
        }
        else puts("NO");
    }
}