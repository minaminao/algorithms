// 全探索（深さ優先探索）
int n;
Graph g(n);
vector<bool> vis(n);
function<void(int)> dfs = [&](int u) {
	if (vis[u])return;
	vis[u] = true;
	/* 処理 */
	for (auto &e : g[u]) {
		if (vis[e.d])continue;
		/* 処理 */
		dfs(e.d);
	}
};

// 非再帰
void dfs(const Graph &g, int root) {
	int n = g.size();
	vector<bool> vis(n);
	stack<int> st; st.emplace(root);
	while (st.size()) {
		int u = st.top(); st.pop();
		if (vis[u])continue;
		vis[u] = true;
		/* 処理 */
		for (auto &e : g[u]) {
			if (vis[e.d])continue;
			/* 処理 */
			st.emplace(e.d);
		}
	}
}