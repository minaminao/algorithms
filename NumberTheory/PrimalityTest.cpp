// 素数判定
// bit数が固定なら O(√n)
// 多倍長整数を許すなら b = lg n として O(2^(b/2))
bool isPrime(int x) {
	if (x <= 1)return false;
	else if (x == 2)return true;
	if (x % 2 == 0)return false;
	for (int i = 3; i*i <= x; i += 2)
		if (x%i == 0)return false;
	return true;
}

#include "ModularArithmetic.cpp"
// 素数判定（Miller-Rabin primality test）
// 2^24程度から
// millerRabinPrimalityTest(n, 5)
// modmul は遅いので極力使わない __uint128_t や BigInt を使う
// Verified: 
//   https://yukicoder.me/submissions/335299
//   https://yukicoder.me/submissions/335326
//using u128 = __uint128_t;
template<typename T>
bool millerRabinPrimalityTest(T n, int iteration = 5) {
	if (n < 2)return false;
	if (n == 2)return true;
	if (n % 2 == 0)return false;
	T d = n - 1;
	while (d % 2 == 0)d /= 2;
	for (int i = 0; i < iteration; i++) {
		T a = rand() % (n - 1) + 1, t = d;
		T mod = modpow(a, t, n);
		while (t != n - 1 && mod != 1 && mod != n - 1) {
			mod = mod * mod % n; //modmul(mod, mod, n);
			t *= 2;
		}
		if (mod != n - 1 && t % 2 == 0)return false;
	}
	return true;
}

// 素数の累乗か判定
// Miller-Rabin素数判定法を用いる
// Verified: https://yukicoder.me/submissions/335324
template<typename T>
bool isPrimePower(T n, int iteration = 5) {
	T t = n, R = 0;
	while (t) {
		R++;
		t >>= 1;
	}
	for (int r = 1; r <= R; r++) {
		auto f = [&](T x) {
			int k = r;
			T y = 1;
			while (k) {
				if (y * x > n)return true; // オーバーフロー対策
				if (k & 1) y *= x;
				x *= x;
				k >>= 1;
			}
			return y >= n;
		};
		auto binarySearch = [&](T ng, T ok) {
			if (f(ng))return ng;
			while (ng + 1 < ok) {
				T m = (ng + ok) / 2;
				if (f(m))
					ok = m;
				else
					ng = m;
			}
			return ok;
		};
		auto power = [&](T a, int k) {
			T r = 1;
			while (k) {
				if (k & 1) r *= a;
				a *= a;
				k >>= 1;
			}
			return r;
		};
		T p = binarySearch(T(2), n + 1);
		if (power(p, r) != n)continue;
		if (millerRabinPrimalityTest(p, iteration))
			return true;
	}
	return false;
}