// 最適か不明
// [l, r)
struct RangeAddQuery {
	int n;
	vector<int> d;
	RangeAddQuery(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, 0);
	}
	void add(int l, int r, int x) {
		for (; l && l + (l&-l) <= r; l += l & -l)
			d[(n + l) / (l&-l)] += x;
		for (; l < r; r -= r & -r)
			d[(n + r) / (r&-r) - 1] += x;
	}
	int get(int i) {
		int ret = d[n + i];
		for (int j = (n + i) / 2; j > 0; j >>= 1)
			ret += d[j];
		return ret;
	}
};