// Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3450348

void bubbleSort(vector<int> &A) {
	int n = A.size();
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (A[j - 1] > A[j])
				swap(A[j - 1], A[j]);
}