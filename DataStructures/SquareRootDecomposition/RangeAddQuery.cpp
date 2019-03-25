// Range Add Query (RAQ)
// Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2232193
struct SqrtDecomposition {
	int n, sqrt_n, bucket_size;
	vector<int> dat;
	vector<int> bucket;
	SqrtDecomposition(int n) :n(n), sqrt_n(sqrt(n)) {
		assert(n);
		bucket_size = 1 + (n - 1) / sqrt_n;
		dat.assign(bucket_size * sqrt_n, 0);
		bucket.assign(bucket_size, 0);
	}
	int get(int x) {
		return dat[x] + bucket[x / sqrt_n];
	}
	void add(int l, int r, int val) {
		for (int k = 0; k < bucket_size; k++) {
			int bl = k * sqrt_n, br = (k + 1) * sqrt_n;
			if (r <= bl || br <= l)
				continue;
			if (l <= bl && br <= r) {
				bucket[k] += val;
			}
			else {
				for (int i = max(l, bl); i < min(r, br); i++) {
					dat[i] += val;
				}
			}
		}
	}
};