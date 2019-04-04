// 素因数分解
// n <= 10^14
// 前処理 O(√n loglog √n)
// クエリ O(√n/ln(√n) + lg(n)) 素数定理と素因数の個数より
// Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3452788
template<typename T>
struct PrimeFactorization {
	T max_n;
	vector<bool> is_prime;
	vector<T> primes;
	// 前処理
	PrimeFactorization(T max_n) :max_n(max_n) {
		T s = sqrt(max_n);
		is_prime.assign(s + 1, true);
		is_prime[0] = is_prime[1] = false;
		for (T i = 2; i*i <= s; i++) {
			if (!is_prime[i])continue;
			for (T j = i * i; j <= s; j += i)
				is_prime[j] = false;
		}
		for (T i = 0; i <= s; i++)
			if (is_prime[i])
				primes.emplace_back(i);
	}
	// 素因数を指数個分並べて昇順で返す
	// √n以下の素数に対して割り切れるか調べる
	vector<T> factorize(T n) {
		assert(n >= 2);
		vector<T> factors;
		for (auto &p : primes) {
			while (n%p == 0) {
				n /= p;
				factors.push_back(p);
			}
		}
		if (n != 1)
			factors.push_back(n);
		return factors;
	}
	// 素因数とその指数のペアを昇順で返す
	vector<pair<T, int>> factorizeCount(T n) {
		assert(n >= 2);
		vector<pair<T, int>> ret;
		for (auto &p : primes) {
			int cnt = 0;
			while (n%p == 0) {
				n /= p;
				cnt++;
			}
			if (cnt > 0)
				ret.emplace_back(p, cnt);
		}
		if (n != 1)
			ret.emplace_back(n, 1);
		return ret;
	}
};


// 素因数分解
// n以下の素因数分解の列挙が O(n lg n) でできる
// n <= 10^7
// 前処理 O(n + √n loglog √n)
// クエリ O(lg n)
struct PrimeFactorization {
	int max_n;
	vector<bool> is_prime;
	vector<int> min_factor;
	// 前処理
	// O(n + √n loglog √n)
	PrimeFactorization(int max_n)
		:max_n(max_n), is_prime(max_n + 1, true), min_factor(max_n + 1) {
		is_prime[0] = is_prime[1] = false;
		iota(min_factor.begin(), min_factor.end(), 0);
		for (int i = 2; i <= max_n; i++) {
			if (!is_prime[i])continue;
			for (int j = i * i; j <= max_n; j += i) {
				is_prime[j] = false;
				if (min_factor[j] > i)
					min_factor[j] = i;
			}
		}
	}
	// 昇順で素因数を返す
	// O(lg n) 
	// 2^(lg n) = n より、素因数の個数 <= lg n であるため
	vector<int> factorize(int n) {
		assert(n >= 2);
		vector<int> factors;
		while (n != min_factor[n]) {
			factors.push_back(min_factor[n]);
			n /= min_factor[n];
		}
		if (n != 1)factors.push_back(n);
		return factors;
	}
};