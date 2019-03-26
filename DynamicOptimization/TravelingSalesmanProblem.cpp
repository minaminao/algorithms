// 巡回セールスマン問題（traveling salesman problem）
// 有向グラフにおいて各頂点をちょうど1回通る最短閉路
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2236237
void travelingSalesmanProblem() {
	static const int MAX_V = 15;
	static int dp[1 << MAX_V][MAX_V];
	static int g[MAX_V][MAX_V];
	memset(dp, 0x3f, sizeof(dp));
	memset(g, 0x3f, sizeof(g));
	int V, E; cin >> V >> E;
	rep(i, 0, E) {
		int s, t, d; cin >> s >> t >> d;
		g[s][t] = d;
	}
	dp[0][1] = 0;
	for (int mask = 0; mask < (1 << V); mask++) {
		rep(i, 0, V) {
			rep(j, 0, V) {
				if (mask >> j & 1)continue;
				if (dp[mask][i] == INF || g[i][j] == INF)continue;
				chmin(dp[mask | (1 << j)][j], dp[mask][i] + g[i][j]);
			}
		}
	}
	cout << (dp[(1 << V) - 1][0] == INF ? -1 : dp[(1 << V) - 1][0]) << endl;
}