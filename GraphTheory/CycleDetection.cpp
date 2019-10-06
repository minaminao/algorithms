#include "Graph.cpp"

// 単純無向グラフでの閉路検出
// Verified: https://atcoder.jp/contests/agc032/submissions/4678569
bool detectCycle(const Graph &g, int s = 0) {
	int n = g.size();
	vector<bool> vis(n);
	function<int(int, int)> dfs = [&](int u, int p) {
		bool ret = false;
		vis[u] = true;
		for (auto e : g[u]) {
			if (p == e.d)continue;
			if (vis[e.d])
				return true;
			ret |= dfs(e.d, u);
			if (ret)break;
		}
		return ret;
	};
	return dfs(s, -1);
}

// 有効グラフでの閉路検出
// Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3440956#1
bool detectCycle(const Graph &g) {
	int n = g.size();
	vector<bool> path(n);
	vector<bool> vis(n);
	function<bool(int)> dfs = [&](int u) {
		bool ret = false;
		path[u] = true;
		for (auto e : g[u]) {
			if (vis[e.d])continue;
			if (path[e.d]) {
				ret = true;
				break;
			}
			ret |= dfs(e.d);
			if (ret)break;
		}
		vis[u] = true;
		path[u] = false;
		return ret;
	};
	for (int i = 0; i < n; i++)
		if (!vis[i])
			if (dfs(i))
				return true;
	return false;
}