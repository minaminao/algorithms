// ラグランジュ補間
// x = 0,1,2,...,n-1 に対して y=f(x) がわかっているとき
// 補間を行い f(t) を求める
// Verified: https://atcoder.jp/contests/arc033/submissions/4901364
template<typename X>
X lagrangeInterpolate(const vector<X> &y, X t) {
	int n = y.size();
	X a = 1;
	for (int i = 0; i < n; i++) {
		if (t == i)return y[i];
		a *= t - i;
	}
	X b = 1;
	for (int i = 1; i < n; i++)
		b *= -i;
	X ret = 0;
	for (int i = 0; i < n; i++) {
		ret += y[i] * a / (t - i) / b;
		b = b / -(n - (i + 1)) * (i + 1);
	}
	return ret;
}