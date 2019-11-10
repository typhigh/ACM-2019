#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50010;
struct node {
    int x, y, z, id;
    bool operator < (const node& rhs) const {
        if (x != rhs.x) return x < rhs.x;
        if (y != rhs.y) return y < rhs.y;
        return z < rhs.z;
    }
} a[MAXN];
int n;
bool vis[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[i] = node {x, y, z, i};
    }
    sort(a+1, a+n+1);
    vector<pair<int, int>> ans;
    for (int i = 1; i < n; ++i) {
        if (a[i].x == a[i+1].x && a[i].y == a[i+1].y) {
            vis[i] = vis[i+1] = true;
            ans.emplace_back(a[i].id, a[i+1].id);
            ++i;
        }
    }
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            vis[i] = 0;
            continue;
        }
        a[++cur] = a[i];
    } 
    n = cur;
    for (int i = 1; i < n; ++i) {
        if (a[i].x == a[i+1].x) {
            vis[i] = vis[i+1] = true;
            ans.emplace_back(a[i].id, a[i+1].id);
            ++i;
        }
    }

    cur = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            vis[i] = 0;
            continue;
        }
        a[++cur] = a[i];
    }
    n = cur;
    for (int i = 1; i < n; i += 2) 
        ans.emplace_back(a[i].id, a[i+1].id);
    for (auto p: ans) printf("%d %d\n", p.first, p.second);
}