#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200010;
int n;
LL s;

struct Node {
    int l, r;
} a[MAXN];

bool check(int mid) {
    LL sum = 0;
    int LCnt = 0, MidCnt = 0, RCnt = 0;
    vector<int> ls;
    for (int i = 0; i < n; ++i) {
//        cout << a[i].l << " " << a[i].r << endl;
        if (a[i].r < mid) {
            sum += a[i].l;
            LCnt++;
        } else if (a[i].l <= mid && mid <= a[i].r) {
            MidCnt++;
            ls.push_back(a[i].l);
        } else {
            sum += a[i].l;
            RCnt++;
        }
    }
    if (LCnt > n / 2 || RCnt > n / 2) return false;
    for (int i = 0; i < n / 2 - LCnt; ++i) sum += ls[i];
    sum += 1LL * (n - (n / 2) - RCnt) * mid;
//    cout << mid << " " << sum << endl;
    return sum <= s;
}

int solve() {
    sort(a, a+n, [](const Node& a, const Node& b){
        return a.r < b.r;
    });
    int R = a[n/2].r;
    sort(a, a+n, [](const Node& a, const Node& b) {
        return a.l < b.l;
    });
    int L = a[n/2].l;
//    cout << L << " and " << R << endl;
    int ans = L;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (check(mid)) {
            ans = mid;
            L = mid+1;
        }
        else {
            R = mid-1;
        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        cin >> n >> s;
        for (int i = 0; i < n; ++i) scanf("%d %d", &a[i].l, &a[i].r);
        printf("%d\n", solve());
    }
}