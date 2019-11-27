#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1<<20;
const int A = 487237;
const int B = 1011807;
const int LIM = 39;
map<long long, int> mp;

int Read(int vote) {
    printf("%d\n", vote);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

void solve() {
    int sum = 0;
    scanf("%d", &sum);
    long long ans = 0;
    for (int i = 0; i < LIM; ++i) {
        int now = Read(1);
        if (now == -1) exit(0);
        ans = ans * 2 + (now > sum ? 1 : 0);
        sum = now; 
    }
    unsigned x = mp[ans];
    for (int i = 0; i < LIM; ++i) x = (x * A + B) & (MAXN - 1);
    for (int i = 0; i < 100; ++i) {
        x = (x * A + B) & (MAXN - 1);
        if (__builtin_popcount(x) & 1) {
            int now = Read(min(sum-1, 200-sum));
            if (now == -1) exit(0);
            sum = now;
        } else {
            int now = Read(1);
            if (now == -1) exit(0);
            sum = now;
        }
    }
//    while(1);
}

int main() {
    for (int x = 0; x < MAXN; ++x) {
        unsigned y = x;
        long long ans = 0;
        for (int i = 0; i < LIM; ++i) {
            y = (y * A + B) & (MAXN-1);
            ans = ans * 2 + (__builtin_popcount(y) & 1);
        }
//        if (mp.count(ans)) puts("!");
        mp[ans] = x;
    }       
//    cout << mp.count(0) << endl;
    solve();
}