//#define double long double
const double EPS = 1e-8;
const double PI = acos(-1);
#define equals(a,b) (fabs((a)-(b)) < EPS)
#define next(P,i) P[(i+1)%P.size()]
#define prev(P,i) P[(i+P.size()-1)%P.size()]

// 点
struct Point {
	double x, y;
	Point() :x(0.0), y(0.0) {}
	Point(double x, double y) :x(x), y(y) {}

	double abs() { return sqrt(norm()); }
	double norm() { return x * x + y * y; }
};
Point operator+(const Point &p1, const Point &p2) { return Point(p1.x + p2.x, p1.y + p2.y); }
Point operator-(const Point &p1, const Point &p2) { return Point(p1.x - p2.x, p1.y - p2.y); }
Point operator*(const Point &p, double a) { return Point(p.x * a, p.y * a); }
Point operator/(const Point &p, double a) { return Point(p.x / a, p.y / a); }
bool operator==(const Point &p1, const Point &p2) { return equals(p1.x, p2.x) && equals(p1.y, p2.y); }
bool cmpx(const Point &p1, const Point &p2) {
	return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y; // x昇順 -> y昇順
}
bool cmpy(const Point &p1, const Point &p2) {
	return p1.y != p2.y ? p1.y < p2.y : p1.x < p2.x; // y昇順 -> x昇順
}
bool operator<(const Point &p1, const Point &p2) {
	return cmpx(p1, p2); // 問題に応じて cmpy
}
bool operator>(const Point &p1, const Point &p2) { return p2 < p1; }
inline istream &operator >> (istream &is, Point &p) { double x, y; is >> x >> y; p = Point(x, y); return is; }
inline ostream &operator << (ostream &os, const Point &p) { os << p.x << ' ' << p.y; return os; }

// ベクトル
struct Vector :public Point {
	using Point::Point;
	Vector() {}
	Vector(const Point &P) { x = P.x; y = P.y; }
	Vector rotate(double rad) { return Vector(x*cos(rad) - y * sin(rad), x*sin(rad) + y * cos(rad)); }
	Vector unit() { return *this / abs(); }
};

// 内積（dot product）
double dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }
// 外積（cross product）の大きさ（正負あり）
double cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }

// 直線
struct Line {
	Point p1, p2;
	Line() {}
	Line(Point p1, Point p2) :p1(p1), p2(p2) {}
};

// 線分
struct Segment :public Line {
	using Line::Line;
	Segment() {}
	Segment(const Line &L) { p1 = L.p1; p2 = L.p2; }
	Vector vec() { return p2 - p1; }
};
inline ostream &operator << (ostream &os, const Segment &s) { os << s.p1 << ' ' << s.p2; return os; }

// 円
struct Circle {
	Point c; // center
	double r; // radius
	Circle() {}
	Circle(Point c, double r) :c(c), r(r) {}
};

// 多角形
using Polygon = vector<Point>;

// degree to radian
double rad(double deg) { return PI * deg / 180; }
// radian to degree
double deg(double rad) { return rad / PI * 180; }

// 偏角 argument
double arg(Vector p) { return atan2(p.y, p.x); }

// 極形式 polar form
Vector polar(double r, double a) { return Point(cos(a)*r, sin(a)*r); }

// 2つのベクトルの角度
double angle(Vector a, Vector b) {
	double lena = a.abs(), lenb = b.abs();
	if (lena == 0 || lenb == 0)return 0; //解なし
	double costheta = dot(a, b) / (lena*lenb);
	if (equals(costheta, 1))costheta = 1; //誤差対策
	return acos(costheta);
}

bool inrange(Point p, double x1, double y1, double x2, double y2) {
	return x1 <= p.x&&p.x <= x2 && y1 <= p.y&&p.y <= y2;
}

// 直交判定
bool is_orthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }
bool is_orthogonal(Segment s1, Segment s2) { return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }

// 平行判定（非交差判定）
bool is_parallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }
bool is_parallel(Segment s1, Segment s2) { return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0); }

// 射影
Point project(Segment s, Point p) {
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / base.norm();
	return s.p1 + base * r;
}
// 反射
Point reflect(Segment s, Point p) { return p + (project(s, p) - p)*2.0; }

// 線分(p0,p1)に対するp2の位置関係
enum { ONLINE_FRONT = -2, CLOCKWISE, ON_SEGMENT, COUNTER_CLOCKWISE, ONLINE_BACK };
int ccw(Point p0, Point p1, Point p2) {
	Vector a = p1 - p0, b = p2 - p0;
	if (cross(a, b) > EPS)return COUNTER_CLOCKWISE;
	if (cross(a, b) < -EPS)return CLOCKWISE;
	if (dot(a, b) < -EPS)return ONLINE_BACK; //p2 p0 p1
	if (a.norm() < b.norm())return ONLINE_FRONT; //p0 p1 p2
	return ON_SEGMENT;
}
int ccw(Vector a, Vector b) {
	if (cross(a, b) > EPS)return COUNTER_CLOCKWISE;
	if (cross(a, b) < -EPS)return CLOCKWISE;
	if (dot(a, b) < -EPS)return ONLINE_BACK; //p2 p0 p1
	if (a.norm() < b.norm())return ONLINE_FRONT; //p0 p1 p2
	return ON_SEGMENT;
}

// 線分と線分の交差判定
bool intersect(Segment a, Segment b) {
	Point p1 = a.p1, p2 = a.p2, p3 = b.p1, p4 = b.p2;
	return (ccw(p1, p2, p3)*ccw(p1, p2, p4) <= 0 &&
		ccw(p3, p4, p1)*ccw(p3, p4, p2) <= 0);
}
// (交差判定続く)

// 2点間の距離
double get_distance(Point a, Point b) { return (a - b).abs(); }

// 直線と点の距離
double get_distance(Line l, Point p) { return abs(cross(l.p2 - l.p1, p - l.p1) / (l.p2 - l.p1).abs()); }

// 線分と点の距離
double get_distance(Segment s, Point p) {
	if (dot(s.p2 - s.p1, p - s.p1) < 0.0)return (p - s.p1).abs();
	if (dot(s.p1 - s.p2, p - s.p2) < 0.0)return (p - s.p2).abs();
	return get_distance(Line(s), p);
}

// 線分と線分の距離
double get_distance(Segment s1, Segment s2) {
	if (intersect(s1, s2))return 0.0;
	return	min(
		min(get_distance(s1, s2.p1), get_distance(s1, s2.p2)),
		min(get_distance(s2, s1.p1), get_distance(s2, s1.p2))
	);
}

// 円と直線の交差判定
bool intersect(Circle c, Line l) { return get_distance(l, c.c) <= c.r + EPS; }

// 円と円の交差判定 共通接線の数
int intersect(Circle c1, Circle c2) {
	double d = get_distance(c1.c, c2.c);
	if (d > c1.r + c2.r)return 4;
	if (d == c1.r + c2.r)return 3;
	if (d + c1.r == c2.r || d + c2.r == c1.r)return 1;
	if (d + c1.r < c2.r || d + c2.r < c1.r)return 0;
	return 2;
}

// 線分と線分の交点
Point get_cross_point(Segment a, Segment b) {
	assert(intersect(a, b));
	Vector base = b.p2 - b.p1;
	double area1 = abs(cross(base, a.p1 - b.p1));
	double area2 = abs(cross(base, a.p2 - b.p1));
	double t = area1 / (area1 + area2);
	return a.p1 + (a.p2 - a.p1)*t;
}

// 円と直線の交点
pair<Point, Point> get_cross_points(Circle c, Line l) {
	assert(intersect(c, l));
	Vector pr = project(l, c.c);
	Vector e = (l.p2 - l.p1) / (l.p2 - l.p1).abs();
	double base = sqrt(c.r*c.r - (pr - c.c).norm());
	return make_pair(pr + e * base, pr - e * base);
}

// 円と円の交点
pair<Point, Point> get_cross_points(Circle c1, Circle c2) {
	int m = intersect(c1, c2);
	assert(m != 4 && m != 0);
	double d = (c1.c - c2.c).abs();
	double a = acos((c1.r*c1.r - c2.r*c2.r + d * d) / (2 * c1.r*d));
	double t = arg(c2.c - c1.c);
	return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

// 点の内包
enum { OUT = 0, ON, IN };
int contains(const Polygon &pl, Point p) {
	int n = pl.size();
	bool x = false;
	for (int i = 0; i < n; i++) {
		Point a = pl[i] - p, b = pl[(i + 1) % n] - p;
		if (abs(cross(a, b)) < EPS&&dot(a, b) < EPS)return ON;
		if (a.y > b.y)swap(a, b);
		if (a.y < EPS&&EPS<b.y&&cross(a, b)>EPS)x = !x;
	}
	return (x ? IN : OUT);
}

int contains(Circle c, Point p) {
	double d = get_distance(c.c, p);
	if (equals(d, c.r))return ON;
	if (d < c.r)return IN;
	return OUT;
}

// 多角形の面積
double area(const Polygon &p) {
	double a = 0;
	for (size_t i = 0; i < p.size(); i++)
		a += cross(p[i], p[(i + 1) % p.size()]);
	return fabs(a / 2.0);
}

// 凸性判定（反時計回り）
bool is_convex(Polygon g) {
	for (size_t i = 0; i < g.size(); i++)
		if (ccw(g[i], g[(i + 1) % g.size()], g[(i + 2) % g.size()]) == CLOCKWISE)
			return false;
	return true;
}

// 凸包
// Graham scan https://en.wikipedia.org/wiki/Graham_scan
// 辺上の点を含めない
Polygon convex_hull(Polygon P) {
	sort(P.begin(), P.end());
	Polygon up;
	for (Point &p : P) {
		while (up.size() > 1 && ccw(up[up.size() - 2], up[up.size() - 1], p) != CLOCKWISE)up.pop_back();
		up.emplace_back(p);
	}
	Polygon down;
	for (Point &p : P) {
		while (down.size() > 1 && ccw(down[down.size() - 2], down[down.size() - 1], p) != COUNTER_CLOCKWISE)down.pop_back();
		down.emplace_back(p);
	}
	reverse(up.begin(), up.end()); //反時計回りに
	down.insert(down.end(), up.begin() + 1, up.end() - 1);
	return down;
}

// 凸包
// Graham scan https://en.wikipedia.org/wiki/Graham_scan
// 辺上の点を含む
Polygon convex_hull_with_points_online(Polygon P) {
	sort(P.begin(), P.end());
	Polygon up;
	for (Point &p : P) {
		int _ccw;
		while (up.size() > 1 && (_ccw = ccw(up[up.size() - 2], up[up.size() - 1], p)) != CLOCKWISE && _ccw != ONLINE_FRONT)
			up.pop_back();
		up.emplace_back(p);
	}
	Polygon down;
	for (Point &p : P) {
		int _ccw;
		while (down.size() > 1 && (_ccw = ccw(down[down.size() - 2], down[down.size() - 1], p)) != COUNTER_CLOCKWISE && _ccw != ONLINE_FRONT)
			down.pop_back();
		down.emplace_back(p);
	}
	reverse(up.begin(), up.end()); //反時計回りに
	down.insert(down.end(), up.begin() + 1, up.end() - 1);
	return down;
}

// 凸多角形の最遠頂点対間距離
// calipers https://en.wikipedia.org/wiki/Rotating_calipers
double diameter(Polygon P) {
	P = convex_hull(P);
	auto mima = minmax_element(P.begin(), P.end());
	int I = mima.first - P.begin();
	int J = mima.second - P.begin();
	double maxd = get_distance(P[I], P[J]);

	int maxi, maxj, i, j;
	i = maxi = I;
	j = maxj = J;
	do {
		if (ccw(next(P, i) - P[i], next(P, j) - P[j]) == COUNTER_CLOCKWISE)
			j = (j + 1) % P.size();
		else
			i = (i + 1) % P.size();
		if (maxd < get_distance(P[i], P[j])) {
			maxd = get_distance(P[i], P[j]);
			maxi = i, maxj = j;
		}
	} while (!(i == I && j == J));
	return maxd;
}

// 多角形を(0,0)を中心として回転
Polygon rotate(const Polygon &P, double rad) {
	Polygon ret;
	for (auto &p : P)
		ret.emplace_back(p.x*cos(rad) - p.y*sin(rad), p.x*sin(rad) + p.y*cos(rad));
	return ret;
}

// Heron's formula
double area(double a, double b, double c) {
	double s = (a + b + c) / 2;
	return sqrt(s*(s - a)*(s - b)*(s - c));
}

// 多角形の重心
Point center(const Polygon &P) {
	Point ret;
	for (auto &p : P)ret = ret + p;
	ret = ret / P.size();
	return ret;
}

// 垂直二等分線
Line get_bisection(const Point &p1, const Point &p2) {
	Circle c1(p1, INF), c2(p2, INF); //INF だと誤差が酷い
	auto ps = get_cross_points(c1, c2);
	return Line(ps.first, ps.second);
}

// 3点から距離が等しい点 (3点を円周上に持つ円の中心)
Point get_center(const Point &p1, const Point &p2, const Point &p3) {
	Line l1 = get_bisection(p1, p2), l2 = get_bisection(p2, p3);
	return get_cross_point(l1, l2);
}

// 点pを通る円cの接線における接点
pair<Point, Point> get_tangent(const Circle &c, const Point &p) {
	double d = get_distance(c.c, p);
	Circle c2((c.c + p) / 2, d / 2);
	return get_cross_points(c, c2);
}
