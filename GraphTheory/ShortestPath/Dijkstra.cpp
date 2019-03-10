// 単一始点最短経路(負閉路なし)
// Dijkstra O((|E|+|V|)log|V|)
// dist: 始点から各頂点までの最短距離
// 戻り値: 最短経路木の親頂点(根は-1)
// 拡張ダイクストラでは状態に対する座標圧縮が有効
vector<int> dijkstra(const Graph &g, int s, Array &dist) {
	int n = g.size();
	assert(s < n);
	enum { WHITE, GRAY, BLACK };
	vector<int> color(n, WHITE); color[s] = GRAY;
	vector<int> prev(n, -1);
	dist.assign(n, INF); dist[s] = 0;
	using State = tuple<Weight, int, int>; //始点からの最短距離 子 親
	priority_queue<State, vector<State>, greater<State>> pq; pq.emplace(0, s, -1);
	while (pq.size()) {
		Weight d; int v, u; tie(d, v, u) = pq.top(); pq.pop();
		if (dist[v] < d)continue;
		color[v] = BLACK; prev[v] = u;
		for (auto &e : g[v]) {
			if (color[e.d] == BLACK)continue;
			if (dist[e.d] > dist[v] + e.w) {
				dist[e.d] = dist[v] + e.w;
				pq.emplace(dist[e.d], e.d, v);
				color[e.d] = GRAY;
			}
		}
	}
	return prev;
}

auto dijkstra = [&](const Graph &g, int s, Array &dist) {
	int n = g.size();
	vector<bool> vis(n);
	vector<int> prev(n, -1);
	dist.assign(n, INF); dist[s] = 0;
	using State = tuple<Weight, int, int>;
	priority_queue<State, vector<State>, greater<State>> pq;
	pq.emplace(0, s, -1);
	while (pq.size()) {
		Weight d; int v, p; tie(d, v, p) = pq.top(); pq.pop();
		if (dist[v] < d)continue;
		vis[v] = true;
		prev[v] = p;
		for (auto &e : g[v]) {
			if (vis[e.d])continue;
			if (dist[e.d] > dist[v] + e.w) {
				dist[e.d] = dist[v] + e.w;
				pq.emplace(dist[e.d], e.d, v);
			}
		}
	}
	return prev;
};