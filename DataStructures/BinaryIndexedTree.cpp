// Fenwick tree (binary indexed tree, BIT) [l,r)
template<class T>
struct FenwickTree {
	typedef ll T;
	vector<T> v;
	FenwickTree(int n) : v(n, 0) {}
	void add(int i, T x) {
		for (; i < (int)v.size(); i |= i + 1) v[i] += x;
	}
	// [0, i)
	T sum(int i) {
		T r = 0;
		for (--i; i >= 0; i = (i & (i + 1)) - 1) r += v[i];
		return r;
	}
	// [l, r)
	T sum(int l, int r) {
		return sum(r) - sum(l);
	}
};

// Fenwick tree (binary indexed tree, BIT) [l,r]
template<class T>
struct FenwickTree {
	vector<T> v;
	FenwickTree(int n) :v(n + 1, 0) {}
	// [1,i]の最大値
	T maxi(int i) {
		T ret = 0;
		for (; i > 0; i -= i & -i) ret = max(ret, v[i]);
		return ret;
	}
	// v[i]とその上の要素を更新
	void update(int i, T x) {
		for (; i < v.size(); i += i & -i) v[i] = max(v[i], x);
	}
};