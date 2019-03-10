// 全点対間最短経路 
auto allPairsShortestPathsByDijkstra = [&](const Graph &g, Matrix &dists) {
	int n = g.size();
	dists.resize(n);
	for (int i = 0; i < n; i++)
		dijkstra(g, i, dists[i]);
};

//全点対間最短経路 
//Warshall-Floyd O(|V|^3)
//戻り値: 負閉路なし:true あり:false
bool warshallFloyd(const Graph &g, Matrix &dist) {
	int n = g.size();
	dist.assign(n, Array(n, INF));
	for (int i = 0; i < n; i++) dist[i][i] = 0;
	for (int i = 0; i < n; i++)
		for (auto &e : g[i])
			dist[e.s][e.d] = min(dist[e.s][e.d], e.w);
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (dist[i][k] == INF || dist[k][j] == INF)continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
	bool negative_cycle = false;
	for (int i = 0; i < n; i++)
		if (dist[i][i] != 0)
			negative_cycle = true;
	return !negative_cycle;
}

//全点対間最短経路
//Warshall-Floyd O(|V|^3)
//インライン版
void warshallFloyd() {
	static const int V = 100;
	static int wf[V][V];
	int N, M;

	rep(i, 0, N)rep(j, 0, N)wf[i][j] = INF;
	rep(i, 0, N)wf[i][i] = 0;

	rep(i, 0, M) {
		int s, d, w; cin >> s >> d >> w; s--, d--;
		wf[s][d] = min(wf[s][d], w); // 有向
	}

	rep(k, 0, N)rep(i, 0, N)rep(j, 0, N) {
		if (wf[i][k] != INF && wf[k][j] != INF)
			wf[i][j] = min(wf[i][j], wf[i][k] + wf[k][j]);
	}


	int i, j;

	//iを通る負閉路があるか
	wf[i][i] < 0;

	//iからjへ向かう道であり負閉路を通るものがあるか
	rep(k, 0, N)
		if (wf[i][k] != INF && wf[k][j] != INF && wf[k][k] < 0);
}
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2243165
