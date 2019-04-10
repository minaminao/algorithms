#include "ModInt.cpp"

#include "LagrangeInterpolation.cpp"
// 冪乗和
// ラグランジュ補間を用いる
// Verified: https://yukicoder.me/submissions/336737
mint sumOfPowers(long long n, int k) {
	vector<mint> y;
	mint t = 0;
	for (int x = 0; x <= k + 1; x++) {
		t += pow(mint(x), k);
		y.push_back(t);
	}
	return lagrangeInterpolate(y, mint(n));
}

#include "BernoulliNumbers.cpp"
// 冪乗和
// 1^k + 2^k + ... + n^k
// ファウルハーバーの公式
// O(k^2)
// Verified: https://yukicoder.me/submissions/335474
mint sumOfPowers(long long n, int k) {
	vector<mint> B = bernoulliNumbers(k);
	mint sum = 0;
	mint p = 1;
	mint s = k & 1 ? -1 : 1;
	for (int i = 1; i < k + 2; i++) {
		p *= n;
		sum += s * C(k + 1, i) * p * B[k + 1 - i];
		s *= -1;
	}
	sum /= k + 1;
	return sum;
}
