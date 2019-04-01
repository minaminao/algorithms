#include "NumericalAnalysis.cpp"
#include "BisectionMethod.cpp"
#include "QuadraticEquation.cpp"

// 三次方程式
// 二分法でまず1つの解pを求める
// (x-p)(ax^2+b'x+c) と式変形して二次方程式で残りの解を求める
// 計算量: 二分法の計算量
// Verified:
//   https://yukicoder.me/submissions/331206
//   http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3453373
vector<double> cubicEquation(double a, double b, double c, double d) {
	if (abs(a) < EPS)
		return quadraticEquation(b, c, d);
	double p = bisectionMethod(-INF, INF, [&](double x) {return a * x*x*x + b * x*x + c * x + d; });
	// (1, b/a, c/a, d/a) を (1, -p) で割っていった結果
	double bb = b / a + p, cc = c / a + bb * p;
	auto ret = quadraticEquation(a, bb, cc);
	ret.push_back(p);
	sort(ret.begin(), ret.end());
	return ret;
}