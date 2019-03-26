#include "Graph.cpp"

// 単純無向連結グラフのlowlink
pair<vector<int>, vector<int>> lowlink(const Graph &g, int root = 0) {
	int n = g.size();
	vector<bool> vis(n);
	vector<int> ord(n);
	vector<int> low(n);
	int o = 0;
	function<void(int, int)> dfs = [&](int u, int p) {
		if (vis[u])return;
		vis[u] = true;
		ord[u] = o++;
		low[u] = ord[u];
		for (auto &e : g[u]) {
			if (!vis[e.d]) {
				dfs(e.d, u);
				chmin(low[u], low[e.d]);
			}
			else if (e.d != p) {
				chmin(low[u], ord[e.d]);
			}
		}
	};
	dfs(root, -1);
	return make_pair(ord, low);
}

// 単純無向連結グラフの関節点
vector<int> articulationPoints(const Graph &g, int root = 0) {
	/*
	u が根
	u が関節点 <=> 子が 2 つ以上存在する

	u が根以外
	u が関節点 <=> ord[u] <= low[v] となる子 v が存在する
	*/
	int n = g.size();
	vector<bool> vis(n);
	vector<int> ord(n);
	vector<int> low(n);
	vector<int> art;
	int o = 0;
	int child = 0;
	function<void(int, int)> dfs = [&](int u, int p) {
		if (vis[u])return;
		if (p == root)child++;
		vis[u] = true;
		ord[u] = o++;
		low[u] = ord[u];
		bool is_art = false;
		for (auto &e : g[u]) {
			if (!vis[e.d]) {
				dfs(e.d, u);
				chmin(low[u], low[e.d]);
				if (u != root&&ord[u] <= low[e.d])is_art = true;
			}
			else if (e.d != p) {
				chmin(low[u], ord[e.d]);
			}
		}
		if (is_art)art.emplace_back(u);
	};
	dfs(root, -1);
	if (child >= 2)art.emplace_back(root);
	sort(art.begin(), art.end());
	return art;
}

// 単純無向連結グラフの橋
Edges bridges(const Graph &g, int root = 0) {
	/*
	e(u, v) が橋でない <=> ord[u] >= low[v]
	e(u, v) が橋 <=> ord[u] < low[v]
	*/
	int n = g.size();
	vector<bool> vis(n);
	vector<int> ord(n);
	vector<int> low(n);
	Edges bri;
	int o = 0;
	function<void(int, int)> dfs = [&](int u, int p) {
		if (vis[u])return;
		vis[u] = true;
		ord[u] = o++;
		low[u] = ord[u];
		bool is_art = false;
		for (auto &e : g[u]) {
			if (!vis[e.d]) {
				dfs(e.d, u);
				chmin(low[u], low[e.d]);
				if (ord[u] < low[e.d])bri.emplace_back(u, e.d);
			}
			else if (e.d != p) {
				chmin(low[u], ord[e.d]);
			}
		}
	};
	dfs(root, -1);
	return bri;
}
