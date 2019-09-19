#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000;

struct Line {
	double x, y1, y2;
	int flag;
	Line() {}
	Line(double x, double y1, double y2, int flag): x(x), y1(y1), y2(y2), flag(flag) {}
	bool operator < (const Line& rhs) const {
		return x < rhs.x;
	}
};

vector<double> y;
map<double, int> idy;
double t[MAXN<<2][2];
int flag[MAXN<<2];

void build(int id, int l, int r) {
	flag[id] = 0;
	t[id][1] = 0;
	t[id][0] = y[r] - y[l];
	if (l+1 != r) {
		int mid = (l+r) >> 1;
		build(id<<1, l, mid);
		build(id<<1|1, mid, r);
	}
}

void Calc(int id, int l, int r) {
	if (flag[id] >= 1) {
		t[id][1] = t[id][0];
	} else {
		assert(flag[id] == 0);
		if (l+1 == r) t[id][1] = 0;
		else t[id][1] = t[id<<1][1] + t[id<<1|1][1];
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
int n, m;
int main() {
	int kase = 0;
	while (~scanf("%d", &m) && m) {
		vector<Line> lines;
		idy.clear();
		y.clear();
		for (int i = 0; i < m; ++i) {
			double x1, y1, x2, y2;
			scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
			lines.emplace_back(x1, y1, y2, 1);
			lines.emplace_back(x2, y1, y2, -1);
			y.push_back(y1);
			y.push_back(y2);
		}
//		cout << "1" << endl;
		sort(y.begin(), y.end());
		y.erase(unique(y.begin(), y.end()), y.end());
		sort(lines.begin(), lines.end());
		n = y.size();
		for (int i = 0; i < y.size(); ++i) idy[y[i]] = i;
//		cout << "2" << endl;
	    build(1, 0, n-1);
//		cout << "3" << endl;
		double ans = 0;
		for (int i = 0; i < lines.size(); ++i) {
			if (i) ans += (lines[i].x - lines[i-1].x) * t[1][1];
			update(1, 0, n-1, idy[lines[i].y1], idy[lines[i].y2], lines[i].flag);
		}
//		cout << "4" << endl;
//		long long cans = ans * 100;
		printf("Test case #%d\nTotal explored area: %.2f\n\n", ++kase, ans);
	}
}
