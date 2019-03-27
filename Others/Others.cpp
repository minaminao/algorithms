// ソート済み配列 A の要素を全て等しくするための最小操作回数
// -1,+1 を 1つの操作とする
// 真ん中の要素に合わせる
// O(n)
int flat(vector<int> &A) {
	int n = A.size();
	int ret = 0;
	for (int i = 0; i < n; i++)
		ret += abs(A[n / 2] - A[i]);
	return ret;
}