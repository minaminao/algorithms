// Binary Indexed Tree
template<class T>
struct BinaryIndexedTree {
	const int n;
	int p; // p = 2^k >= n となるような最小の数
	vector<T> v;
	BinaryIndexedTree(int n) :n(n), v(n + 1, 0) {
		p = 1;
		while (p < n) { p <<= 1; }
	}
	void add(int i, T x) {
		for (; i <= n; i += i & -i)
			v[i] = v[i] + x;
	}
	// [1, i]
	T sum(int i) {
		T ret = 0;
		for (; i > 0; i -= i & -i)
			ret = ret + v[i];
		return ret;
	}
	// [l, r]
	T sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	// BIT 上の二分探索
	// v の要素が非負である必要がある
	// one-based index を返す
	// Verified: https://atcoder.jp/contests/arc033/submissions/4890921
	T lowerBound(T s) {
		if (s <= 0)return 0;
		int x = 0;
		for (int i = p; i > 0; i >>= 1) {
			if (x + i <= n && v[x + i] < s) {
				s -= v[x + i];
				x += i;
			}
		}
		return x + 1;
	}
};

// 半開区間 Binary Indexed Tree
template<class T>
struct BinaryIndexedTree {
	vector<T> v;
	BinaryIndexedTree(int n) : v(n, 0) {}
	void add(int i, T x) {
		for (; i < v.size(); i |= i + 1)
			v[i] += x;
	}
	// [0, i)
	T sum(int i) {
		T r = 0;
		for (--i; i >= 0; i = (i & (i + 1)) - 1)
			r += v[i];
		return r;
	}
	// [l, r)
	T sum(int l, int r) {
		return sum(r) - sum(l);
	}
};

#include "CommutativeGroup.cpp"
// 抽象化 Binary Indexed Tree
// Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3467295
template<class CommutativeGroup>
struct BinaryIndexedTree {
	using T = typename CommutativeGroup::T;
	vector<T> v;
	BinaryIndexedTree(int n) : v(n, CommutativeGroup::I) {}
	void add(int i, T x) {
		for (; i < v.size(); i |= i + 1)
			v[i] = CommutativeGroup::op(v[i], x);
	}
	// [0, i)
	T sum(int i) {
		T r = CommutativeGroup::I;
		for (--i; i >= 0; i = (i & (i + 1)) - 1)
			r = CommutativeGroup::op(r, v[i]);
		return r;
	}
	// [l, r)
	T sum(int l, int r) {
		return CommutativeGroup::op(sum(r), CommutativeGroup::inverse(sum(l)));
	}
};