#include "NumericalAnalysis.cpp"

// 二分法
// 方程式の求根アルゴリズム
// f(l) < 0 かつ 0 < f(r) の場合に限る
double bisectionMethod(double l, double r, function<double(double)> f) {
	double yl = f(l), yr = f(r);
	if (yl > yr)swap(l, r);
	assert((yl - EPS) * (yr + EPS) <= 0);
	for (int i = 0; i < 200; i++) {
		double m = (l + r) / 2;
		if (f(m) > 0)
			r = m;
		else
			l = m;
	}
	return l;
}