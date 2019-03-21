// ガウスの消去法（Gauss elimination）
// O(n^3)
//
// 戻り値: (解が存在するか, rank, 解)
//
// Verified:
//   http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3437138
//   http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3437187
//   https://yukicoder.me/submissions/326809 (mod)

using Num = double;
using Vec = vector<Num>;
using Mat = vector<Vec>;
tuple<bool, int, Vec> gaussianElimination(Mat A, Vec b) {
	const Num EPS = 1e-5; // 誤差
	const int n = A.size(), m = A[0].size();
	int rank = 0, cj = 0;
	while (rank < n && cj < m) {
		// A[rank][cj] が最大になるように
		for (int i = rank + 1; i < n; i++) {
			if (abs(A[i][cj]) > abs(A[rank][cj])) {
				A[i].swap(A[rank]);
				swap(b[i], b[rank]);
			}
		}
		if (abs(A[rank][cj]) > 0) {
			// 係数を 1 に
			Num d = A[rank][cj];
			for (int j = 0; j < m; j++)
				A[rank][j] /= d;
			b[rank] /= d;
			// 前進消去（forward elimination）
			for (int i = rank + 1; i < n; i++) {
				Num k = A[i][cj];
				for (int j = 0; j < m; j++)
					A[i][j] -= k * A[rank][j];
				b[i] -= k * b[rank];
			}
			rank++;
		}
		cj++;
	}
	// 0 != b[i] だったら不能
	for (int i = rank; i < n; i++)
		if (abs(b[i]) > EPS)
			return make_tuple(false, rank, Vec());
	// 不定
	// rank != m
	// cj < m => n < m
	if (rank < m || cj < m)
		return make_tuple(true, rank, Vec());
	// 後退代入（back substitution）
	for (int j = m - 1; j >= 0; j--)
		for (int i = 0; i < j; i++)
			b[i] -= b[j] * A[i][j];
	return make_tuple(true, rank, b);
}