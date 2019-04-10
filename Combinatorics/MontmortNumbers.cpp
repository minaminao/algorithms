#include "Combinatorics.cpp"

// モンモール数
// O(n)
// Verified: https://atcoder.jp/contests/arc009/submissions/4905032
mint montmortNumber(int n) {
	precompute(n);
	mint m = 0;
	for (int k = 2; k <= n; k++)
		m += factinv[k] * (k & 1 ? -1 : 1);
	m *= fact[n];
	return m;
}

// モンモール数の列
// O(n)
// Verified: https://atcoder.jp/contests/arc009/submissions/4905051
vector<mint> montmortNumbers(int n) {
	precompute(n);
	vector<mint> m(n + 1);
	for (int k = 2; k <= n; k++)
		m[k] = m[k - 1] + factinv[k] * (k & 1 ? -1 : 1);
	for (int k = 2; k <= n; k++)
		m[k] *= fact[k];
	return m;
}