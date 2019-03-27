#include "ModInt.cpp"

// ガウスの消去法（Gauss elimination）
// O(n^3)
//
// 戻り値: (解が存在するか, rank, 解)
//   解が複数ある場合は適当な解を出力する
//
// Verified:
//   https://yukicoder.me/submissions/326809 (mod 2)
//   https://yukicoder.me/submissions/329080 (mod 2)

using Num = mint;
using Vec = vector<Num>;
using Mat = vector<Vec>;
tuple<bool, int, Vec> gaussianEliminationMod(Mat A, Vec b) {
	const int n = A.size(), m = A[0].size();
	if (n > b.size())b.resize(n);
	int rank = 0, cj = 0;
	while (rank < n && cj < m) {
		// A[rank][cj] が最大になるように
		for (int i = rank + 1; i < n; i++) {
			if (A[i][cj].get() > A[rank][cj].get()) {
				A[i].swap(A[rank]);
				swap(b[i], b[rank]);
			}
		}
		if (A[rank][cj].get()) {
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
		if (b[i].get())
			return make_tuple(false, rank, Vec());
	// 不定
	// rank != m
	// cj < m => n < m
	// n == m なら適当な解を構築する
	// n != m でも解を構築できるようにする
	if (rank < m || cj < m) {
		if (n != m)
			return make_tuple(true, rank, Vec());
		int ci = rank;
		for (int i = 0; i < n; i++) {
			if (A[i][i].get() == 0) {
				if (i != ci) {
					A[i].swap(A[ci]);
					swap(b[i], b[ci]);
				}
				ci++;
				for (int j = 0; j < m; j++)
					A[i][j] = 0;
				A[i][i] = 1;
				b[i] = 0; // 任意の値で良い
			}
		}
	}
	// 後退代入（back substitution）
	// 1 * * | *     1 * 0 | *
	// 0 1 * | *  -> 0 1 0 | *
	// 0 0 1 | *     0 0 1 | *
	for (int j = m - 1; j >= 0; j--)
		for (int i = 0; i < j; i++)
			b[i] -= b[j] * A[i][j];
	return make_tuple(true, rank, b);
}
