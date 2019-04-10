#include "Combinatorics.cpp"

// モンモール数
// O(n)
// Verified: https://atcoder.jp/contests/arc009/submissions/4905241
mint montmortNumber(int n) {
	if (n <= 1)return 0;
	if (n == 2)return 1;
	mint a = 0, b = 1, c;
	for (int i = 3; i <= n; i++) {
		c = (a + b) * (i - 1);
		a = b;
		b = c;
	}
	return c;
}

// モンモール数の列
// O(n)
// Verified: https://atcoder.jp/contests/arc009/submissions/4905257
vector<mint> montmortNumbers(int n) {
	vector<mint> m(n + 1); m[2] = 1;
	for (int i = 3; i <= n; i++)
		m[i] = (m[i - 1] + m[i - 2]) * (i - 1);
	return m;
}