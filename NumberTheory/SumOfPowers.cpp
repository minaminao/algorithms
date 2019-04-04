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