#include "StirlingNumbers.cpp"

// 完全2部グラフの彩色多項式
// O(n^2 + n lg m)
// Verified:
//   https://yukicoder.me/submissions/334614
mint chromaticPolynomialOfACompleteBipartiteGraph(int n, int m, mint x) {
	auto S = stirlingNumbers(n);
	mint ret = 0;
	mint a = x;
	for (int k = 1; k <= n; k++) {
		ret += S[n][k] * a * pow(x - k, m);
		a *= x - k;
	}
	return ret;
}