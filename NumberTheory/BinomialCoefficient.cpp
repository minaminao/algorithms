#include "ModInt.cpp"

// 前計算 O(n) 計算 O(1) は Combinatorics.cpp を参照
// 手元計算 O(n) 前計算 O(√n) 計算 O(√n) は Factorial.cpp を参照

// O(k)
// n が大きいときに有用
mint binom(long long n, int k) {
	mint a = 1, b = 1;
	for (int i = 0; i < k; i++) {
		a *= n - i;
		b *= i + 1;
	}
	return a / b;
}

// パスカルの三角形から計算
// O(n^2)
// double なら 10^308 くらいまでOK
// C[n][r]: nCr
// r が小さいなら O(nr) にできる
// Verified: https://yukicoder.me/submissions/335500
using Num = long long;
const Num BINOM_MAX = 1LL << 60;
vector<vector<Num>> C;
vector<vector<Num>> precomputeBinom(int n) {
	vector<Num> a(1, 1), b(2, 1);
	C = { a,b };
	for (int i = 3; i <= n + 1; i++) {
		swap(a, b);
		b.resize(i);
		b[0] = 1; b[i - 1] = 1;
		for (int j = 1; j < i - 1; j++) {
			if (a[j - 1] == BINOM_MAX || a[j] == BINOM_MAX || a[j - 1] + a[j] > BINOM_MAX)
				b[j] = BINOM_MAX;
			else
				b[j] = a[j - 1] + a[j];
		}
		C.emplace_back(b);
	}
	return C;
}

// 確率
using Num = double;
vector<vector<Num>> C;
void precomputeBinomProbability(int n) {
	vector<Num> a(1, 1.0), b(2, 1.0 / 2.0);
	C = { a,b };
	for (int i = 3; i <= n + 1; i++) {
		swap(a, b);
		b.resize(i);
		b.front() = a.front() / 2.0; b.back() = a.back() / 2.0;
		for (int j = 1; j < i - 1; j++)
			b[j] = a[j - 1] / 2.0 + a[j] / 2.0;
		C.emplace_back(b);
	}
}