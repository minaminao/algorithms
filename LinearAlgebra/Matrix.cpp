// 行列
template<typename R>
struct Matrix {
	vector<vector<R>> a;
	Matrix() {}
	Matrix(int n, int m) :a(n, vector<R>(m)) {}
	int h()const { return a.size(); }
	int w()const { return a[0].size(); }
	vector<R> &operator[](size_t i) { return a[i]; }
	const vector<R> &operator[](size_t i)const { return a[i]; }
	Matrix &operator*=(const Matrix &b) {
		assert(w() == b.h());
		int n = h(), m = w(), r = b.w();
		Matrix c(n, r);
		for (int i = 0; i < n; i++)for (int j = 0; j < r; j++)for (int k = 0; k < m; k++)
			c[i][j] += a[i][k] * b[k][j];
		return *this = c;
	}
	static Matrix I(int n) {
		Matrix m(n, n);
		for (int i = 0; i < n; i++)m[i][i] = 1;
		return m;
	}
};

// Verified: https://atcoder.jp/contests/dp/submissions/4906423
template<typename R>
Matrix<R> pow(Matrix<R> a, unsigned long long k) {
	Matrix<R> r = Matrix<R>::I(a.h());
	while (k) {
		if (k & 1)r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}