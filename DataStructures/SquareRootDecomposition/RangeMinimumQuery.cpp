// Range Minimum Query (RMQ)
// Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2232123
struct SqrtDecomposition {
	int n, sqrt_n, bucket_size;
	vector<int> dat;
	vector<int> bucket;
	SqrtDecomposition(int n, int val = 0) :n(n), sqrt_n(sqrt(n)) {
		assert(n);
		bucket_size = 1 + (n - 1) / sqrt_n;
		dat.assign(bucket_size * sqrt_n, val);
		bucket.assign(bucket_size, val);
	}
	void update(int x, int y) {
		int k = x / sqrt_n;
		dat[x] = y;
		int mini = y;
		for (int i = k * sqrt_n; i < (k + 1) * sqrt_n; i++) {
			chmin(mini, dat[i]);
		}
		bucket[k] = mini;
	}
	int get_min(int l, int r) {
		int ret = dat[l];
		for (int k = 0; k < bucket_size; k++) {
			int bl = k * sqrt_n, br = (k + 1) * sqrt_n;
			if (r <= bl || br <= l)
				continue;
			if (l <= bl && br <= r) {
				chmin(ret, bucket[k]);
			}
			else {
				for (int i = max(l, bl); i < min(r, br); i++) {
					chmin(ret, dat[i]);
				}
			}
		}
		return ret;
	}
};
