// 2部グラフの最大マッチング
// O(VE)
// Flow.cpp も参照
// alive は確定させたいときや頂点を削除したいときに使う
struct BipartiteMatching {
	int n;
	vector<vector<int>> g;
	vector<int> match;
	vector<bool> used, alive;
	BipartiteMatching(int n) : n(n), g(n), match(n), used(n), alive(n, true) {}
	void addEdge(int u, int v) {
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	int maximumMatching() {
		int cnt = 0;
		fill(match.begin(), match.end(), -1);
		for (int u = 0; u < n; u++) {
			if (!alive[u])continue;
			if (match[u] == -1) {
				fill(used.begin(), used.end(), false);
				if (augment(u))cnt++;
			}
		}
		return cnt;
	}
	bool augment(int u) {
		used[u] = true;
		for (int v : g[u]) {
			if (!alive[v])continue;
			int w = match[v];
			if (w == -1 || (!used[w] && augment(w))) {
				match[u] = v;
				match[v] = u;
				return true;
			}
		}
		return false;
	}
};
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2478365