// 2次方程式を解の公式を用いて解く
// 計算量: O(sqrt()の計算量)
// 重解は1つにせず返す 1つにしたいなら変えること
// Verified:
//   https://www.urionlinejudge.com.br/judge/en/runs/code/13486899
//   http://codeforces.com/contest/233/submission/52143945
vector<double> quadratic_equation(double a, double b, double c) {
	// 1次方程式
	if (a < EPS)
		return b < EPS ? vector<double>() : vector<double>{ -c / b };
	// 判別式
	double D = b * b - 4 * a*c;
	// 解無し
	if (D < -EPS)
		return vector<double>();
	// 重解
	if (D < EPS)
		return vector<double>{-b / (2 * a), -b / (2 * a)};
	double d = sqrt(D);
	double x1 = (-b + d) / (2 * a);
	double x2 = (-b - d) / (2 * a);
	if (x1 > x2)swap(x1, x2);
	return vector<double>{x1, x2};
}