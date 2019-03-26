#include "ModInt.cpp"

// n < 10^7
// 前計算 O(n)
// 計算 O(1)
vector<mint> fact, factinv;
void precomputeFact(int n) {
	n = min(n, mint::kMod - 1); //  N >= kMod  =>  N! = 0 (mod kMod)
	fact.resize(n + 1); factinv.resize(n + 1);
	fact[0] = 1;
	for (int i = 1; i < n + 1; i++)
		fact[i] = fact[i - 1] * i;
	factinv[n] = fact[n].inverse();
	for (int i = n; i >= 1; i--)
		factinv[i - 1] = factinv[i] * i; // ((i-1)!)^(-1) = (i!)^(-1) * i
}
mint binom(int n, int r) {
	if (n >= mint::kMod)
		return binom(n % mint::kMod, r % mint::kMod) * binom(n / mint::kMod, r / mint::kMod);
	return r > n ? 0 : fact[n] * factinv[n - r] * factinv[r];
}

// O(r)
mint binom_r(int n, int r) {
	mint ret = 1;
	for (int i = 0; i < r; i++) {
		ret *= n - i;
		ret /= i + 1;
	}
	return ret;
}

// パスカルの三角形から計算
// O(n^2)
// double なら 10^308 くらいまでOK
// C[n][r]: nCr
// r が小さいなら O(nr) にできる
using Num = long long;
vector<vector<Num>> C;
vector<vector<Num>> precomputeBinom(int n) {
	vector<Num> a(1, 1), b(2, 1);
	C = { a,b };
	for (int i = 3; i <= n + 1; i++) {
		swap(a, b);
		b.resize(i);
		b[0] = 1; b[i - 1] = 1;
		for (int j = 1; j < i - 1; j++)
			b[j] = a[j - 1] + a[j];
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