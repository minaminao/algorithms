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