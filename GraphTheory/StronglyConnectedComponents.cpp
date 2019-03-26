#include "Graph.cpp"

// 辺を逆に張ったグラフ
Graph reverse(const Graph &g) {
	Graph rg(g.size());
	for (auto &es : g)
		for (auto &e : es)
			rg[e.d].emplace_back(e.d, e.s, e.w);
	return rg;
}

// 強連結成分分解 O(|V|+|E|)
// ret[u] = u が属している強連結成分のインデックス
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2244415
vector<int> kosaraju(const Graph &g) {
	int n = g.size();
	Graph rg = reverse(g);
	vector<int> cc(n, -1);
	vector<int> post;
	function<void(int, int)> dfs_cc = [&](int u, int cc_id) {
		if (cc[u] != -1)return;
		cc[u] = cc_id;
		for (auto &e : g[u])
			dfs_cc(e.d, cc_id);
		post.emplace_back(u);
	};
	int count_cc = 0;
	for (int u = 0; u < n; u++)
		if (cc[u] == -1)
			dfs_cc(u, count_cc++);
	vector<int> scc(n, -1);
	function<void(int, int, int)> dfs_scc = [&](int u, int scc_id, int cc_id) {
		if (scc[u] != -1)return;
		if (cc[u] != cc_id)return;
		scc[u] = scc_id;
		for (auto &e : rg[u])
			dfs_scc(e.d, scc_id, cc_id);
	};
	int count_scc = 0;
	reverse(post.begin(), post.end());
	for (auto &u : post)
		if (scc[u] == -1)
			dfs_scc(u, count_scc++, cc[u]);
	return scc;
}

// 閉路の検出 O(|V|+|E|)
bool detectCycle(const vector<int> &idx) {
	return find(all(idx), idx.size() - 1) == idx.end();
}
bool detectCycle(const Graph &g) {
	vector<int> idx = kosaraju(g);
	return find(all(idx), idx.size() - 1) == idx.end();
}

// 強連結成分分解 O(|V|+|E|)
// ret[u] = u が属している強連結成分内の頂点のインデックス
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2244420
// ccとしている箇所は連結成分ではなく到達できる範囲
// 変数名を変えたい
vector<int> kosaraju(const Graph &g) {
	int n = g.size();
	Graph rg = reverse(g);
	vector<int> cc(n, -1);
	vector<int> post;
	function<void(int, int)> dfs_cc = [&](int u, int cc_id) {
		if (cc[u] != -1)return;
		cc[u] = cc_id;
		for (auto &e : g[u])
			dfs_cc(e.d, cc_id);
		post.emplace_back(u);
	};
	for (int u = 0; u < n; u++)
		if (cc[u] == -1)
			dfs_cc(u, u);
	vector<int> scc(n, -1);
	function<void(int, int, int)> dfs_scc = [&](int u, int scc_id, int cc_id) {
		if (scc[u] != -1)return;
		if (cc[u] != cc_id)return;
		scc[u] = scc_id;
		for (auto &e : rg[u])
			dfs_scc(e.d, scc_id, cc_id);
	};
	reverse(post.begin(), post.end());
	for (auto &u : post)
		if (scc[u] == -1)
			dfs_scc(u, u, cc[u]);
	return scc;
}

bool detectCycle(const vector<int> &idx) {
	int n = idx.size();
	vector<bool> f(n);
	for (auto &u : idx) {
		if (f[u])return true;
		f[u] = true;
	}
	return false;
}
