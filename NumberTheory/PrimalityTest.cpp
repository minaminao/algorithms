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
bool millerRabinPrimalityTest(long long x, int iteration) {
	if (x < 2)return false;
	if (x != 2 && x % 2 == 0)return false;
	long long s = x - 1;
	while (s % 2 == 0)s /= 2;
	for (int i = 0; i < iteration; i++) {
		long long a = rand() % (x - 1) + 1, tmp = s;
		long long mod = modpow(a, tmp, x);
		while (tmp != x - 1 && mod != 1 && mod != x - 1) {
			mod = modmul(mod, mod, x);
			tmp *= 2;
		}
		if (mod != x - 1 && tmp % 2 == 0)return false;
	}
	return true;
}