#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100010;

int n, ans[MAXN];
int main() {
    for (int i = 2; i < MAXN; ++i) {
        int sum = 1;
        int cur = 1;
        while ((LL)cur * i + sum < MAXN) {
            cur = cur * i;
            sum += cur;
            ++ans[sum];
        }
    }
    
    scanf("%d", &n);
    if (n == 1) {
        puts("0");
        return 0;
    }
    LL ret = 0;
    for (int a = 1; a < n; ++a) {
        if (n % a == 0) 
            ret += ans[n/a]+1;
    }
    cout << ret << endl; 
}