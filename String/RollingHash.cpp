// Roling Hash
// base: [2, MOD) の乱数
// RH.get(l, r): [l, r) のハッシュを O(1) で求める
// base: 1000000007, 1000000009, 1000000021
template<long long MOD>
struct RollingHash {
	int n;
	long long base;
	vector<long long> pow, hash;
	RollingHash() {}
	RollingHash(const string &s, long long base_ = 10007) { init(s, base_); }
	void init(const string &s, long long base_ = 10007) {
		n = s.size();
		base = base_;
		calc(s.c_str());
	}
	long long get(int x)const { return hash[x]; }
	long long get(int l, int r)const { return (get(r) - get(l)*pow[r - l] % MOD + MOD) % MOD; }
	void calc(const char *s) {
		pow.resize(n + 1);
		pow[0] = 1;
		hash.resize(n + 1);
		hash[0] = 0;
		for (int i = 0; i < n; i++) {
			pow[i + 1] = pow[i] * base % MOD;
			hash[i + 1] = (s[i] + hash[i] * base) % MOD;
		}
	}
};