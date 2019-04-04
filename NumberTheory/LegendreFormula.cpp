// ルジャンドルの公式
// Verified: https://yukicoder.me/submissions/335421

// n! を素因数 p で最大何回割り切れるか
long long largestPowerPrime(long long n, long long p) {
	assert(p >= 2);
	long long ret = 0;
	long long q = p;
	while (q <= n) {
		ret += n / q;
		q *= p;
	}
	return ret;
}

#include "PrimeFactorization.cpp"
// n! を m で最大何回割り切れるか
long long largestPowerComposite(long long n, long long m) {
	assert(m >= 2);
	PrimeFactorization<long long> pf(n);
	auto res = pf.factorizeCount(m);
	long long d = LLONG_MAX;
	for (auto r : res) {
		long long c = largestPowerPrime(n, r.first);
		d = min(d, c / r.second);
	}
	return d;
}