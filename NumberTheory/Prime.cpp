// エラトステネスの篩
// O(n log log n)
// Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3452809
vector<bool> eratos(int n) {
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i*i <= n; i++) {
		if (!is_prime[i])continue;
		for (int j = i * i; j <= n; j += i)
			is_prime[j] = false;
	}
	return is_prime;
}

// n以下の素数
// O(n log log n)
vector<int> getPrimes(int n) {
	vector<bool> is_prime = eratos(n);
	vector<int> primes;
	for (int i = 0; i <= n; i++)
		if (is_prime[i])
			primes.push_back(i);
	return primes;
}