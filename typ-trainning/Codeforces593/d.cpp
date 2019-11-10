#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN = 100010;
int n, m, k;
vector<int> stone[2][MAXN];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int x, y, X1, Y1, X2, Y2, dir;

bool check() {
    return X1 <= X2 && Y1 <= Y2;
}
LL Calc() {
    LL ret = 0;
    X1 = 1, Y1 = 1, X2 = n, Y2 = m, dir = 0;
    x = 1, y = 0;
    while (check()) {
//        cout << x << " " << y << " " << dir << endl;
        int nx = x, ny = y;
        switch (dir)
        {
        case 0:
        {
            vector<int>& v = stone[0][x];
            auto it = upper_bound(v.begin(), v.end(), y);
            ny = min(Y2, (*it)-1);
            X1 = nx + 1;    
            Y2 = ny;
            break;
        }
        case 1:
        {
            vector<int>& v = stone[1][y];
            auto it = upper_bound(v.begin(), v.end(), x);
            nx = min(X2, (*it)-1);
            X2 = nx;
            Y2 = ny - 1;
            break;
        }
        case 2: 
        {
            vector<int>& v = stone[0][x];
            auto it = lower_bound(v.begin(), v.end(), y);
            --it;
            ny = max(Y1, (*it)+1);
            X2 = nx - 1;
            Y1 = ny;
            break;
        }
        case 3:
        {
            vector<int>& v = stone[1][y];
            auto it = lower_bound(v.begin(), v.end(), x);
            --it;
            nx = max(X1, (*it)+1);
            X1 = nx;
            Y1 = ny  +1;
            break;
        }
        default:
            break;
        }
        ret += abs(nx - x) + abs(ny - y);
        x = nx, y = ny;
        dir = (dir + 1) % 4;
    }
//    cout << ret << endl;
    return ret;
}

LL cnt;
bool solve() {
    if (cnt + Calc() == (LL) n * m) return true;
    return false;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        stone[0][x].push_back(y);
        stone[1][y].push_back(x);
        ++cnt;
    }
    for (int t = 0; t < 2; ++t) {
        int a = t ? n : m;
        int b = t ? m : n;
        for (int i = 1; i <= b; ++i) {
            vector<int>& v = stone[t][i];
            v.push_back(0);
            v.push_back(a+1);
            sort(v.begin(), v.end());
        }
    }
    if (solve()) puts("Yes");
    else puts("No");
}