#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1<<18;
int n, a[MAXN];

long long solve() {
    int cnt;
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) {
            cnt = i;
            break;
        }
    }
    int times = 0;
    for (int i = 0; i <= 18; ++i) if ((1<<i) & n) times = i;
    
    long long ret = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    int l = cnt+1;
    int r = n-1;
    int rest = r - l + 1;
    if (l <= r) {
        q.push(a[r]);
        --r;
    }
    for (int i = 0, span = (1<<times-1); i < times; ++i, span >>= 1) {
        if (rest) {
//            cout << l << " " << r << " " << rest << endl;
            ret += q.top();        
            q.pop();
            rest = max(0, rest-span);
//            cout << (1<<times-i-1) << endl;
            for (int j = r, cnt = 0; j >= l && cnt < span; --j, ++cnt) {
                q.push(a[j]);
                --r;
            }
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
//    printf("%I64d\n", solve());
    cout << solve() << '\n';
}