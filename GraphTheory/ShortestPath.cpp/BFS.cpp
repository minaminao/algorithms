// 木 あるいは 辺の重みが 1 のグラフ での最短距離
// O(E)?
auto bfs = [&](const Graph &g, int s, Array &dist) {
	int n = g.size();
	vector<bool> vis(n);
	vector<int> prev(n, -1);
	dist.assign(n, INF); dist[s] = 0;
	using State = tuple<Weight, int, int>;
	queue<State> q;
	q.emplace(0, s, -1);
	while (q.size()) {
		Weight d; int v, p; tie(d, v, p) = q.front(); q.pop();
		vis[v] = true;
		prev[v] = p;
		for (auto &e : g[v]) {
			if (vis[e.d])continue;
			if (dist[e.d] > dist[v] + e.w) {
				dist[e.d] = dist[v] + e.w;
				q.emplace(dist[e.d], e.d, v);
			}
		}
	}
	return prev;
};
// http://abc070.contest.atcoder.jp/submissions/1510329