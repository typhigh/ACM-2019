#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x + 1 == y) {
        cout << x << " " << y << endl;
    } 
    else if (x == y) {
        x *= 10, y *= 10;
        cout << x << " " << y + 1 << endl;
    }
    else {
        if (x == 9 && y == 1) cout << 9 << " " << 10 << endl;
        else cout << "-1" << endl;
    }
}