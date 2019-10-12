#include "Graph.cpp"

// 2部グラフかどうか判定
// Verified: https://atcoder.jp/contests/agc039/submissions/7881926
bool isBipartiteGraph(const Graph &g) {
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
	Array dist;
	bfs(g, 0, dist);
	Edges edges;
	for (auto es : g)
		edges.insert(edges.end(), es.begin(), es.end());
	for (auto e : edges)
		if (dist[e.s] % 2 == dist[e.d] % 2)
			return false;
	return true;
}