#include "ModularArithmetic.cpp"

// Legendre symbol
// a|p なら 0
// a が平方剰余なら 1
// a が平方非剰余なら -1
int legendre(long long a, long long p) {
	long long l = modpow(a, (p - 1) / 2, p);
	return l == p - 1 ? -1 : l;
}

// Tonelli–Shanks algorithm
// x^2 = a mod p となるような x を求める
// Verified: https://yukicoder.me/submissions/331164
long long modsqrt(long long a, long long p) {
	int l = legendre(a, p);
	if (l != 1)return l;

	long long S = 0, Q = p - 1;
	while (!(Q & 1)) {
		S++;
		Q >>= 1;
	}

	long long z = 1;
	while (legendre(z, p) == 1)z++;

	long long M = S;
	long long c = modpow(z, Q, p);
	long long t = modpow(a, Q, p);
	long long R = modpow(a, (Q + 1) / 2, p);

	while (t != 1) {
		for (int i = 1; i < M; i++) {
			if (modpow(t, 1 << i, p) != 1)continue;
			long long b = modpow(c, 1 << (M - i - 1), p);
			M = i;
			c = b * b % p;
			t = t * b % p * b % p;
			R = R * b % p;
			break;
		}
	}
	return R;
}