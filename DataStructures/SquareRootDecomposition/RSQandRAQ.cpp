// RSQ and RAQ
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2232416#1
const int SQRT_N = 317;
const int MAX_N = SQRT_N * SQRT_N;
int dat[MAX_N] = {};
int bucket_add[SQRT_N] = {};
int bucket_sum[SQRT_N] = {};

void add(int l, int r, int val) {
	for (int k = 0; k < SQRT_N; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			bucket_add[k] += val;
			bucket_sum[k] += val * SQRT_N;
		}
		else {
			for (int i = max(l, bl); i < min(r, br); i++) {
				dat[i] += val;
				bucket_sum[k] += val;
			}
		}
	}
}

int get_sum(int l, int r) {
	int ret = 0;
	for (int k = 0; k < SQRT_N; k++) {
		int bl = k * SQRT_N, br = (k + 1) * SQRT_N;
		if (r <= bl || br <= l)
			continue;
		if (l <= bl && br <= r) {
			ret += bucket_sum[k];
		}
		else {
			for (int i = max(l, bl); i < min(r, br); i++) {
				ret += dat[i] + bucket_add[k];
			}
		}
	}
	return ret;
}