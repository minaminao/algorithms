// (max, min)
// Verified: https://yukicoder.me/submissions/330289
void floydWarshall() {
	int N, M;

	vector<vector<int>> fw(N, vector<int>(N, 0));
	rep(i, 0, N)fw[i][i] = 0;

	rep(i, 0, M) {
		int s, d, w;
		fw[s][d] = max(fw[s][d], w); // 有向
	}

	rep(k, 0, N)rep(i, 0, N)rep(j, 0, N) {
		if (fw[i][k] != INF && fw[k][j] != INF)
			fw[i][j] = max(fw[i][j], min(fw[i][k], fw[k][j]));
	}
}