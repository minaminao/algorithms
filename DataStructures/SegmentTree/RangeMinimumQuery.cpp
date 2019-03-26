// コンストラクタより init() のほうが良いメリット
// 配列で持つときにコンストラクタを呼ぶ必要がない
// [l, r)
struct RangeMinimumQuery {
	int n;
	vector<int> d;
	void init(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, INF);
	}
	void update(int i, int x) {
		d[n + i] = x;
		for (int j = (n + i) / 2; j > 0; j >>= 1)
			d[j] = min(d[j * 2], d[j * 2 + 1]);
	}
	int query(int l, int r) {
		int mi = get(l);
		for (; l && l + (l&-l) <= r; l += l & -l)
			mi = min(mi, d[(n + l) / (l&-l)]);
		for (; l < r; r -= r & -r)
			mi = min(mi, d[(n + r) / (r&-r) - 1]);
		return mi;
	}
	int get(int i) { return d[n + i]; }
};

// シンプルなセグメント木
// ノード 2n 個 (n=2^k)
// 構築 O(n) クエリ O(log n) 
// query がトップダウン
// 親から子 2k+1 2k+2
// 子から親 (k-1)/2
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2473843
struct RangeMinimumQuery {
	int n;
	vector<int> d;
	RangeMinimumQuery(int m, int x) {
		for (n = 1; n < m; n *= 2);
		d.assign(2 * n - 1, x);
	}
	void update(int k, int x) {
		k += n - 1;
		d[k] = x;
		while (k > 0) {
			k = (k - 1) / 2;
			d[k] = min(d[2 * k + 1], d[2 * k + 2]);
		}
	}
	int query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return INT_MAX;
		if (a <= l && r <= b)return d[k];
		int xl = query(a, b, 2 * k + 1, l, (l + r) / 2);
		int xr = query(a, b, 2 * k + 2, (l + r) / 2, r);
		return min(xl, xr);
	}
	int query(int a, int b) {
		return query(a, b, 0, 0, n);
	}
};