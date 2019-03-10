
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
long long modmul(long long a, long long b, long long mod) {
	long long x = 0, y = a % mod;
	while (b > 0) {
		if (b & 1)x = x + y % mod;
		y = y * 2 % mod;
		b >>= 1;
	}
	return x % mod;
}

// オーバーフローする可能性があれば掛け算にmodmul()を使う
long long modpow(long long a, long long exponent, long long mod) {
	long long res = 1;
	while (exponent > 0) {
		if (exponent & 1)res = res * a % mod;
		a = a * a % mod;
		exponent >>= 1;
	}
	return res;
}