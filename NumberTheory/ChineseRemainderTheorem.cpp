#include "ExtendedGCD_inverse.cpp"

// 中国剰余定理
// Verified: https://yukicoder.me/submissions/335243
pair<long long, long long> crt(const vector<long long> &a, const vector<long long> &n) {
	assert(a.size() == n.size());
	long long A = 0, N = 1;
	for (int i = 0; i < a.size(); i++) {
		long long u, v;
		long long g = extgcd(N, n[i], u, v);
		if (a[i] % g != A % g)
			return make_pair(-1, -1);
		long long m = n[i] / g;
		long long t = (a[i] - A) / g * u % m;
		if (t < 0)t += m;
		A += N * t;
		N *= m;
	}
	return make_pair(A % N, N);
}