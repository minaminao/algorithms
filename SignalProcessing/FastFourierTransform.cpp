// 再帰
// 非再帰と比べて10倍以上遅い
// Verified: https://atcoder.jp/contests/atc001/submissions/4910922
namespace FFT {
	const double PI = acos(-1);
	using C = complex<double>;
	vector<C> fft(vector<C> &a, int n, bool inv = false) {
		if (n == 1)return a;
		int m = n / 2;
		vector<C> a0(m), a1(m);
		for (int i = 0; i < m; i++) {
			a0[i] = a[2 * i];
			a1[i] = a[2 * i + 1];
		}
		a0 = fft(a0, m, inv);
		a1 = fft(a1, m, inv);
		double theta = 2 * PI * (inv ? -1 : 1) / n;
		C omega = C(cos(theta), sin(theta)), p = 1;
		for (int i = 0; i < n; i++) {
			a[i] = a0[i % m] + p * a1[i % m];
			p *= omega;
		}
		if (inv)for (int i = 0; i < n; i++)a[i] /= 2;
		return a;
	}
	vector<int> multiply(const vector<int> &a, const vector<int> &b) {
		int m = a.size() + b.size() - 1;
		int n = 1;
		while (n < m)n <<= 1;
		vector<C> A(a.begin(), a.end()), B(b.begin(), b.end());
		A.resize(n); B.resize(n);
		A = fft(A, n); B = fft(B, n);
		vector<C> C(n);
		for (int i = 0; i < n; i++)C[i] = A[i] * B[i];
		C = fft(C, n, true);
		vector<int> c(n);
		for (int i = 0; i < n; i++)c[i] = C[i].real() + 0.5;
		return c;
	}
};