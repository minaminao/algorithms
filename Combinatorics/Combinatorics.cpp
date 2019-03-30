#include "ModInt.cpp"

// n < 10^7
// 前計算 O(n)
// 計算 O(1)
// Verified: https://yukicoder.me/submissions/330366
vector<mint> fact, factinv, inv;
void precompute(int n) {
	int m = fact.size();
	if (n < m)return;
	n = min(n, mint::kMod - 1); //  N >= kMod  =>  N! = 0 (mod kMod)
	fact.resize(n + 1);
	factinv.resize(n + 1);
	inv.resize(n + 1);
	if (m == 0) {
		fact[0] = 1;
		m = 1;
	}
	for (int i = m; i <= n; i++)
		fact[i] = fact[i - 1] * i;
	factinv[n] = fact[n].inverse();
	for (int i = n; i >= m; i--)
		factinv[i - 1] = factinv[i] * i; // ((i-1)!)^(-1) = (i!)^(-1) * i
	for (int i = m; i <= n; i++)
		inv[i] = factinv[i] * fact[i - 1];
}

mint C(int n, int k) {
	// Lucas's theorem
	if (n >= mint::kMod)
		return C(n % mint::kMod, k % mint::kMod) * C(n / mint::kMod, k / mint::kMod);
	precompute(n);
	return k > n ? 0 : fact[n] * factinv[n - k] * factinv[k];
}

mint P(int n, int k) {
	precompute(n);
	return k > n ? 0 : fact[n] * factinv[n - k];
}

mint H(int n, int k) {
	if (n == 0 && k == 0)return 1; // H(0,0) = C(-1,0) = 1
	return C(n + k - 1, k);
}


// L <= x <= R を満たす x の個数
// v はソート済み配列
// O(log n)
int query(const vector<int> &v, int L, int R) {
	return upper_bound(v.begin(), v.end(), R) - lower_bound(v.begin(), v.end(), L);
}

// 数列 v の並べ方
mint numberOfArrangement(vector<int> v) {
	int n = v.size();
	assert(fact.size() >= n);
	mint ret = fact[n];
	unordered_map<int, int> cnt;
	for (auto &e : v)cnt[e]++;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto &e : v)ret /= fact[cnt[e]];
	return ret;
}

// ありえる区間の和
// sumAllInterval(x) * sumAllInterval(y) で ありえる長方形の面積の和
mint sumAllInterval(const vector<int> &x) {
	int n = x.size();
	mint tot = 0;
	rep(i, 0, n - 1) {
		mint t = x[i + 1] - x[i];
		int l = i + 1;
		int r = n - l;
		t *= l;
		t *= r;
		tot += t;
	}
	return tot;
}
