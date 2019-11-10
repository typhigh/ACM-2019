#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2020;

struct Point {
	LL x, y;
	Point base() const {
		if (x < 0 || (x == 0 && y < 0)) return Point{-x, -y};
		return *this;
	}
	bool operator < (const Point& rhs) const {
		Point a = base(), b = rhs.base();
		return a.x * b.y < a.y * b.x;
	}
	void read() { cin >> x >> y;}
}P[MAXN], v[MAXN];

typedef Point Vector;
Vector operator - (Point a, Point b) {
	return Point {a.x - b.x, a.y - b.y};
}

Vector rotate90(Vector a) {
	return Vector{a.y, -a.x};
}

map<Vector, int> mp;

LL res[MAXN];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) P[i].read(); 
	for (int q = 0; q < m; ++q) {
		v[q].read();
		mp.clear();
		LL ans = 0;
		for (int i = 0; i < n; ++i) {
			Vector t = P[i] - v[q];
			t = rotate90(t);
			++mp[t];
		}
		for (auto it : mp) {
			Vector p = rotate90(it.first);
			auto iter = mp.find(p);	
			if (iter != mp.end()) ans += 1LL * it.second * iter->second;
		}
		res[q] = ans / 2;
	}
	
	for (int i = 0; i < n; ++i) {
		mp.clear();
		for (int j = 0; j < n; ++j) 
			if (j != i) 
				mp[P[j] - P[i]]++;
		for (int q = 0; q < m; ++q) { 
			Vector t = v[q] - P[i];
			t = rotate90(t);
			auto iter = mp.find(t);
			if (iter != mp.end()) res[q] += iter->second; 
		}
	}

	for (int i = 0; i < m; ++i) cout << res[i] << '\n';
}
