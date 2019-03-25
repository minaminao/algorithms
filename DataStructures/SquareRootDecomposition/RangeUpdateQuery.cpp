// Range Update Query (RUQ)
// Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2232387
const int SQRT_N = 317;
const int MAX_N = SQRT_N * SQRT_N;
int dat[MAX_N] = {};
int lazy_bucket[SQRT_N] = {};
bool lazy_flag[SQRT_N] = {};

void init(int n) {
	rep(i, 0, n) {
		dat[i] = INT_MAX;
	}
}

int get(int x) {
	int k = x / SQRT_N;
	return lazy_flag[k] ? lazy_bucket[k] : dat[x];
}

void update(int l, int r, int val) {
	for (int k = 0; k < SQRT_N; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			lazy_bucket[k] = val;
			lazy_flag[k] = true;
		}
		else {
			if (lazy_flag[k]) {
				for (int i = bl; i < br; i++) {
					dat[i] = lazy_bucket[k];
				}
				lazy_flag[k] = false;
			}
			for (int i = max(l, bl); i < min(r, br); i++) {
				dat[i] = val;
			}
		}
	}
}