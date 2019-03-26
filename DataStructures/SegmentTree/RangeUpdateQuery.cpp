// 最適か不明
// [l, r)
struct RangeUpdateQuery {
	int n;
	vector<int> d;
	vector<int> timestamp;
	int time;
	RangeUpdateQuery(int m) {
		for (n = 1; n < m; n *= 2);
		d.assign(n * 2, INF);
		time = 0;
		timestamp.assign(n * 2, 0);
	}
	void update(int l, int r, int x) {
		time++;
		for (; l && l + (l&-l) <= r; l += l & -l) {
			d[(n + l) / (l&-l)] = x;
			timestamp[(n + l) / (l&-l)] = time;
		}
		for (; l < r; r -= r & -r) {
			d[(n + r) / (r&-r) - 1] = x;
			timestamp[(n + r) / (r&-r) - 1] = time;
		}
	}
	int get(int i) {
		int ret = d[n + i];
		int max_time = timestamp[n + i];
		for (int j = (n + i) / 2; j > 0; j >>= 1) {
			if (max_time > timestamp[j])continue;
			max_time = timestamp[j];
			ret = d[j];
		}
		return ret;
	}
};