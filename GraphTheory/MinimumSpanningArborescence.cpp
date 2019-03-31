
// 最小全域有向木 (minimum spanning arborescence)
// Chu-Liu/Edmonds' algorithm O(|E||V|)
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2244434
// https://en.wikipedia.org/wiki/Edmonds%27_algorithm
// "A faster implementation of the algorithm due to Robert Tarjan runs in time O(ElogV) for sparse graphs and O(V^2) for dense graphs"
Weight edmonds(const Graph &g, int root) {
	// 辺を逆に張ったグラフで考えると都合がいい
	int n = g.size();
	Weight total = 0;
	Graph rg = reverse(g);
	Graph rmsa;
	while (true) {
		rmsa.assign(n, Edges());
		// 頂点 u から出ている最小コスト辺を採用
		Edges minout(n);
		for (int u = 0; u < n; u++) {
			if (u == root)continue;
			if (!rg[u].size())continue;
			minout[u] = *min_element(rg[u].begin(), rg[u].end());
			rmsa[u].emplace_back(minout[u]);
		}
		// 閉路がなければ最小全域有向木
		vector<int> idx = kosaraju(rmsa);
		if (!detectCycle(idx))
			break;
		vector<int> cycle_count(n);
		Array cycle_cost(n);
		for (int u = 0; u < n; u++) {
			if (u == root)continue;
			if (!rmsa[u].size())continue;
			Edge &e = rmsa[u].front();
			if (idx[e.d] == idx[e.s]) {
				cycle_cost[idx[e.d]] += e.w;
				cycle_count[idx[u]]++;
			}
		}
		// 閉路のコストを加算
		for (int i = 0; i < n; i++)
			if (cycle_count[i] >= 2)
				total += cycle_cost[i];
		// 閉路を縮約 閉路の代表頂点に辺を張り直す
		rmsa.assign(n, Edges());
		for (auto &es : rg)
			for (auto &e : es) {
				if (idx[e.s] == idx[e.d])continue;
				// s から出ている辺のコストを再計算
				if (cycle_count[idx[e.s]] >= 2)
					e.w -= minout[e.s].w;
				rmsa[idx[e.s]].emplace_back(idx[e.s], idx[e.d], e.w);
			}
		rg = rmsa;
	}
	for (auto &es : rmsa)
		for (auto &e : es)
			total += e.w;
	return total;
}