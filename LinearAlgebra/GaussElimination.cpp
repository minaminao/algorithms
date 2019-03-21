#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

// ガウスの消去法（Gauss elimination）
// O(n^3)
//
// 戻り値: (解が存在するか, rank, 解)
//   解が複数ある場合は適当な解を出力する
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
		if (abs(A[rank][cj]) > EPS) {
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
	// 適当な解を構築する
	if (rank < m || cj < m) {
		int ci = rank;
		for (int i = 0; i < min(n, m); i++) {
			if (abs(A[i][i]) <= EPS) {
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
	for (int j = m - 1; j >= 0; j--)
		for (int i = 0; i < j; i++)
			b[i] -= b[j] * A[i][j];
	return make_tuple(true, rank, b);
}

int main() {
	Mat A; Vec b;

	A = { { 1,3,1 },{ 1,1,-1 },{ 3,11,5 } };
	b = { 9,1,35 };
	dump(gaussianElimination(A, b));
	A = { { 1,0,1 },{ 0,0,1 },{ 0,0,0 } };
	b = { { 1,3,0 } };
	dump(gaussianElimination(A, b));
	A = { { 0,0,1 },{ 1,0,1 },{ 0,0,0 } };
	b = { { 3,1,0 } };
	dump(gaussianElimination(A, b));
	A = { { 0,1,0 },{ 0,0,1 },{ 0,0,0 },{ 1,0,0 } };
	b = { { 2,3,0,1 } };
	dump(gaussianElimination(A, b));

	return 0;
}