#include "ModInt.cpp"
#include "Combinatorics.cpp"
// ベルヌーイ数 B^-
// O(n^2)
// Verified: https://yukicoder.me/submissions/335474
vector<mint> bernoulliNumbers(int n) {
	vector<mint> B(n + 1);
	B[0] = 1;
	precompute(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k <= i - 1; k++)
			B[i] += C(i + 1, k) * B[k];
		B[i] *= -inv[i + 1];
	}
	return B;
}