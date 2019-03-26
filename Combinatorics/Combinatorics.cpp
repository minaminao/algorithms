#include "ModInt.cpp"

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
