#include <bits/stdc++.h>
using namespace std;
string s;

string solve() {
    string ret;
    int cnt = 1;
    s.push_back('1');
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i-1]) ++cnt;
        else {
            if (cnt & 1) ret.push_back(s[i-1]);
            cnt = 1;
        }
    }
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    return ret;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        cout << solve() << "\n";
    }
}