
const double EPS = 1e-8;
// mod (double)
double modulo(double x, double mod) {
	x -= floor(x / mod)*mod;
	if (x<EPS || x + EPS>mod)x = 0;
	return x;
}

// 最小非負剰余(c/c++は絶対値最小剰余)
int modulo(int x, int mod) {
	return (x%mod < 0) ? x % mod + abs(mod) : x % mod;
}

// (a*b) % mod
template<typename T>
T modmul(T a, T b, T mod) {
	T x = 0, y = a % mod;
	while (b > 0) {
		if (b & 1)x = x + y % mod;
		y = y * 2 % mod;
		b >>= 1;
	}
	return x % mod;
}

// 累乗
// O(log e)
// mod^2 が T の最大値より大きければオーバーフローするので掛け算に modmul を使う
template<typename T>
T modpow(T a, T e, T mod) {
	T res = 1;
	while (e > 0) {
		if (e & 1)res = res * a % mod; // modmul(res, a, mod);
		a = a * a % mod; // modmul(a, a, mod);
		e >>= 1;
	}
	return res;
}

// 逆元
// O(log mod)
long long modinv(long long a, long long mod) {
	return modpow(a, mod - 2, mod);
}