// 0-1 BFS
// コストが 0 か 1 のグラフ上での最短距離
// Dijkstra と同様の考え
// O(|E|+|V|)
// Verified:
//   https://yukicoder.me/submissions/330319
//   http://arc061.contest.atcoder.jp/submissions/1482669
auto zeroOneBfs = [&](const Graph &g, int s, Array &dist) {
	int n = g.size();
	deque<int> dq = { s };
	dist.assign(n, INF);
	dist[s] = 0;
	while (dq.size()) {
		int v = dq.front(); dq.pop_front();
		for (auto &e : g[v]) {
			if (dist[e.d] == INF) {
				dist[e.d] = dist[v] + e.w;
				if (e.w == 0)
					dq.push_front(e.d);
				else
					dq.push_back(e.d);
			}
		}
	}
};