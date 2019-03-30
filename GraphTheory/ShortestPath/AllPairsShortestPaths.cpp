#include "Dijkstra.cpp"

// 全点対最短路問題
// Dijkstra法
// O(|V|(|E|+|V|)log|V|)
// Floyd–Warshall法より速い
auto allPairsShortestPathsByDijkstra = [&](const Graph &g, Matrix &dists) {
	int n = g.size();
	dists.resize(n);
	for (int i = 0; i < n; i++)
		dijkstra(g, i, dists[i]);
};

// 全点対最短経路 
// Floyd–Warshall O(|V|^3)
// 戻り値: 負閉路なし:true あり:false
bool floydWarshall(const Graph &g, Matrix &dist) {
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

// 全点対最短経路
// Floyd–Warshall O(|V|^3)
// インライン版
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2243165
void floydWarshall() {
	int N, M;

	vector<vector<int>> fw(N, vector<int>(N, INF));
	rep(i, 0, N)fw[i][i] = 0;

	rep(i, 0, M) {
		int s, d, w;
		fw[s][d] = min(fw[s][d], w); // 有向
	}

	rep(k, 0, N)rep(i, 0, N)rep(j, 0, N) {
		if (fw[i][k] != INF && fw[k][j] != INF)
			fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
	}


	int i, j;

	// iを通る負閉路があるか
	fw[i][i] < 0;

	// iからjへ向かう道であり負閉路を通るものがあるか
	rep(k, 0, N)
		if (fw[i][k] != INF && fw[k][j] != INF && fw[k][k] < 0);
}