#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000;

struct Line {
	int x, y1, y2, flag;
	Line(){}
	Line(int x, int y1, int y2, int flag) : x(x), y1(y1), y2(y2), flag(flag) {}
	bool operator < (const Line& rhs) const {
		return x < rhs.x;
//		return flag < rhs.flag;
	}
};

struct Cube {
	int x1, y1, z1, x2, y2, z2;
};

int t[MAXN<<2][4], flag[MAXN<<2];
map<int, int> idy;
vector<int> y;
vector<int> z;

void build(int id, int l, int r) {
	t[id][1] = t[id][2] = t[id][3] = flag[id] = 0;
	t[id][0] = y[r] - y[l];
	if (l + 1 != r) {
		int mid = (l+r) >> 1;
		build(id<<1, l, mid);
		build(id<<1|1, mid, r);
	}
}

void Calc(int id, int l, int r) {
	if (flag[id] >= 3) {
		t[id][3] = t[id][0];
		t[id][1] = t[id][2] = 0;
	} else if (flag[id] == 2) {
		if (l + 1 == r) {
			t[id][1] = t[id][3] = 0;
		} else {
			t[id][3] = t[id<<1][3] + t[id<<1|1][3] + t[id<<1][2] + t[id<<1|1][2] + t[id<<1][1] + t[id<<1|1][1];
			t[id][1] = 0; 
		}
		t[id][2] = t[id][0] - t[id][1] - t[id][3];
	} else if (flag[id] == 1) {
		if (l + 1 == r) {
			t[id][1] = t[id][0];
			t[id][2] = t[id][3] = 0;
		} else {
			t[id][3] = t[id<<1][3] + t[id<<1|1][3] + t[id<<1][2] + t[id<<1|1][2];
			t[id][2] = t[id<<1][1] + t[id<<1|1][1];
			t[id][1] = t[id][0] - t[id][2] - t[id][3];
		}
	} else {
		if (flag[id] != 0) while(1);
		if (l + 1 == r) t[id][3] = t[id][2] = t[id][1] = 0;
		else {
			t[id][3] = t[id<<1][3] + t[id<<1|1][3];
			t[id][2] = t[id<<1][2] + t[id<<1|1][2];
			t[id][1] = t[id<<1][1] + t[id<<1|1][1];
		}
	}
}
void update(int id, int l, int r, int L, int R, int d) {
//	cout << id << " " << l << " " << r << " " << L << " " << R << " " << d << endl;
	if (L <= l && r <= R) {
		flag[id] += d;
	} else {
		int mid = (l+r) >> 1;
		if (L < mid) update(id<<1, l, mid, L, R, d);
		if (R > mid) update(id<<1|1, mid, r, L, R, d);
	}
	Calc(id, l, r);
}

void Debug(vector<Line>& lines) {
	cout << "lines has:" << endl;
	for (auto e: lines) {
		cout << e.x << " " << e.y1 << " " <<e.y2 << " " << e.flag << endl;
	}
}
int n, m;
int main() {
//	freopen("test", "r", stdin);
//	freopen("wrong", "w", stdout);
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
//		cout << kase << endl;
		scanf("%d", &m);
		vector<Cube> cubes; 
		y.clear();
		z.clear();
		idy.clear();
		for (int i = 0; i < m; ++i) {
			int x1, y1, z1, x2, y2, z2;
			scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
			z.push_back(z1);
			z.push_back(z2);
			y.push_back(y1);
			y.push_back(y2);
			cubes.push_back(Cube {x1, y1, z1, x2, y2, z2});
		}
//		cout << "1" << endl;
		sort(z.begin(), z.end());
		z.erase(unique(z.begin(), z.end()), z.end());
		sort(y.begin(), y.end());
		y.erase(unique(y.begin(), y.end()), y.end());
		n = y.size();
//		cout << n << endl;
		vector<Line> lines;
		for (int i = 0; i < y.size(); ++i) idy[y[i]] = i;
		long long ans = 0;
		for (int i = 0; i < z.size() - 1; ++i) {
			int zval = z[i];
//			cout << "[z[i]] is " << z[i] << endl;
			lines.clear();
			for (int j = 0; j < cubes.size(); ++j) {
				Cube& e = cubes[j];
				if (e.z1 <= zval && zval < e.z2) {
					lines.emplace_back(e.x1, e.y1, e.y2, 1);
					lines.emplace_back(e.x2, e.y1, e.y2, -1);
				}
			}
			sort(lines.begin(), lines.end());
//			Debug(lines);
			build(1, 0, n-1);	
			long long cans = 0;
//			int old = cans;
			for (int j = 0; j < lines.size(); ++j) {
				if (j) cans += 1LL * (lines[j].x - lines[j-1].x) * t[1][3];
				update(1, 0, n-1, idy[lines[j].y1], idy[lines[j].y2], lines[j].flag);
//				if (cans != old) {
//					cout << "[add] : " << cans - old << endl;
//				}
//				old = cans;	
//				cout << lines[j].x << " " << lines[j].y1 << " " << lines[j].y2 << " " << lines[j].flag << endl;
			}
			ans += cans * (z[i+1] - z[i]);
//			cout << "[ans] is " << ans << endl;
		}
		cout << "Case " << ++kase <<": " << ans << endl;
	}
}
