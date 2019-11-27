#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101;
pair<int, int> a[3];
int cnt[MAXN][MAXN];
vector<vector<int>> ans;
void PushAns(int x, int y, int z) {
    vector<int> v;
    v.resize(3);
    v[a[0].second] = z;
    v[a[1].second] = y;
    v[a[2].second] = x;
    ans.push_back(v);
}

void Out() {
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            for (int k = 0; k < cnt[i][j]; ++k) {
                PushAns(i, j, k);
            }
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto v: ans) {
        printf("%d %d %d\n", v[0], v[1], v[2]);
    }
}
void solve() {
    for (int i = 0; i < 3; ++i) a[i].second = 2-i;
    sort(a, a+3);
    int x = a[0].first, y = a[1].first, z = a[2].first;
    if (y == z) {
        for (int i = 0; i < x; ++i) ++cnt[i][i];
        cnt[0][0] += y - x;
        return Out();
    }
    if (x == 1) {
        puts("-1");
        return;
    }
    // x <= y < z && x >= 2

    int d = z - y + 1;
    if (d <= x) {
        for (int i = 0; i < d; ++i) ++cnt[0][i];
        for (int i = d; i < x; ++i) ++cnt[i][i];
        cnt[0][0] += z - x;
    } else {
        for (int i = 0; i < x; ++i) ++cnt[0][i];
        y -= 1;
        z -= x;
        if (z > y * x) {
            puts("-1");
            return;
        }
        cnt[0][0] += y;
        z -= y;
        for (int i = 1; i < x; ++i) {
            int v = min(y, z);
            cnt[0][i] += v;
            z -= v;
        }
    }
    /*
    y -= (x-1);
    z -= x;
    int minv = min(y, z);
    cnt[0][0] += minv;
    y -= minv;
    z -= minv;
    cnt[0][1] += z;
    if (cnt[0][0] < cnt[0][1]) {
        puts("-1");
        return;
    }
    */
    return Out();
}
int main() {
    scanf("%d %d %d", &a[0].first, &a[1].first, &a[2].first);
    solve();
}