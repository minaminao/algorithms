// 素因数分解
// n <= 10^14
// 前処理 O(√n loglog √n)
// クエリ O(√n/ln(√n) + lg(n)) 素数定理と素因数の個数より
// Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3452788
struct PrimeFactorization {
	int max_n;
	vector<bool> is_prime;
	vector<int> primes;
	// 前処理
	PrimeFactorization(int max_n) :max_n(max_n) {
		int s = sqrt(max_n);
		is_prime.assign(s + 1, true);
		is_prime[0] = is_prime[1] = false;
		for (int i = 2; i*i <= s; i++) {
			if (!is_prime[i])continue;
			for (int j = i * i; j <= s; j += i)
				is_prime[j] = false;
		}
		for (int i = 0; i <= s; i++)
			if (is_prime[i])
				primes.emplace_back(i);
	}
	// 昇順で素因数を返す
	// √n以下の素数に対して割り切れるか調べる
	vector<int> factorize(int n) {
		assert(n >= 2);
		vector<int> factors;
		for (auto &p : primes) {
			while (n%p == 0) {
				n /= p;
				factors.emplace_back(p);
			}
		}
		if (n != 1)factors.emplace_back(n);
		return factors;
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