// 全探索（幅優先探索）

auto bfs = [&](int root) {
	vector<bool> vis(n);
	queue<int> q; q.emplace(root);
	while (q.size()) {
		int u = q.front(); q.pop();
		if (vis[u])continue;
		vis[u] = true;
		/* 処理 */
		for (auto &e : g[u]) {
			if (vis[e.d])continue;
			/* 処理 */
			q.emplace(e.d);
		}
	}
};

void bfs(const Graph &g, int root) {
	int n = g.size();
	vector<bool> vis(n);
	queue<int> q; q.emplace(root);
	while (q.size()) {
		int u = q.front(); q.pop();
		if (vis[u])continue;
		vis[u] = true;
		/* 処理 */
		for (auto &e : g[u]) {
			if (vis[e.d])continue;
			/* 処理 */
			q.emplace(e.d);
		}
	}
}