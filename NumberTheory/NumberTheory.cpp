// 累乗（power）
// 高速累乗 繰り返し自乗法 バイナリ法
// power((BigInt)a, k) のように使うこと
// pow だと pow(int,int) が衝突する
template<typename Int>
Int power(Int a, unsigned long long k) {
	Int r = 1;
	while (k) {
		if (k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}

// 階乗, factorial
int factorial(int n) {
	int fact = 1;
	for (int i = 1; i <= n; i++)
		fact *= i;
	return fact;
}

// フィボナッチ数列
auto fibonacci = [&](int n) {
	vector<int> v(n);
	v[0] = v[1] = 1;
	for (int i = 0; i < n - 2; i++)
		v[i + 2] += v[i + 1] + v[i];
	return v;
};

// powerarray.snnipet
vector<int> powerArray(int p, int n) {
	vector<int> power(n + 1); power[0] = 1;
	for (int i = 0; i < n; i++)
		power[i + 1] = power[i] * p;
	return power;
}

// 細かな定理・予想

// コラッツの予想
// https://en.wikipedia.org/wiki/Collatz_conjecture
// n/2  if n = 0 (mod 2)
// 3n+1 if n = 1 (mod 2)
// n <= 10^6 だと最大 collatzConjecture(837799) = 524 だから全探索しても結構速く終わる
int collatzConjecture(int n) {
	if (n == 1)
		return 0;
	if (n % 2)
		return collatzConjecture(3 * n + 1) + 1;
	else
		return collatzConjecture(n / 2) + 1;
}

