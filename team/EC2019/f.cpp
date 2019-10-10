#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double PI = acos(-1.0);
const double eps = 1e-7;
struct Point {
	LL x, y, z;
};

typedef Point Vector;
int dcmp(double x) {
	if (fabs(x) < eps) return 0;
	else return x < 0 ? -1 : 1;
}

bool operator == (const Point& a, const Point& b) {
	return a.x == b.x && a.y == b.y && a.z == b.z;
}

Point readPoint() {
	LL x, y, z;
	cin >> x >> y >> z;
	return Point{x, y, z};
}

Vector operator - (const Point& a, const Point& b) {
	return Vector {a.x - b.x, a.y - b.y, a.z - b.z};
}

LL Dot(Point a, Point b) {
	return a.x * b.x + a.y * b.y + a.z * b.z; 
}

double len(Vector a) {
	return sqrt(Dot(a, a));
}

double Angle(Vector a, Vector b) {
	return acos(Dot(a, b) / len(a) / len(b));
}

Vector Cross(Vector a, Vector b) {
	return Vector {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x}; 
}

double DistanceToSegment(Point P, Point A, Point B) {
	if (A == B) return len(P-A);
	Vector v1 = B - A, v2 = P - A, v3 = P - B;
	if (Dot(v1, v2) < 0) return len(v2);
	else if (Dot(v1, v3) > 0) return len(v3);
	else return len(Cross(v1, v2)) / len(v1);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		Point O = readPoint();
		LL r;
		cin >> r;
		Point S = readPoint();
		Point T = readPoint();
		Vector SO = O - S;
		Vector TO = O - T;
		Vector ST = T - S;
		double ans = -1;
		if (dcmp(DistanceToSegment(O, S, T) - r) >= 0) {
			ans = len(ST);
		} else {
			double LenSO = len(SO);
			double LenTO = len(TO);
			double LenSM = sqrt(Dot(SO, SO) - r*r);
			double LenTN = sqrt(Dot(TO, TO) - r*r);
			Vector OS = S - O;
			Vector OT = T - O;
			double sot = Angle(OS, OT);
			double mon = sot -  acos(r/LenSO) - acos(r/LenTO);
			ans = LenSM + LenTN + mon * r;
		}
		printf("%.7f\n", ans);
	}
}
