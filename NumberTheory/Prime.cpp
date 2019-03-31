// エラトステネスの篩
// O(n log log n)
vector<char> eratos(int n) {
	vector<char> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i*i <= n; i++) {
		if (!is_prime[i])continue;
		int j = i + i;
		while (j <= n) {
			is_prime[j] = false;
			j += i;
		}
	}
	return is_prime;
}

// n以下の素数
// O(n log log n)
vector<int> getPrimes(int n) {
	vector<char> is_prime = eratos(n);
	vector<int> primes;
	for (int i = 0; i < n + 1; i++)
		if (is_prime[i])
			primes.emplace_back(i);
	return primes;
}