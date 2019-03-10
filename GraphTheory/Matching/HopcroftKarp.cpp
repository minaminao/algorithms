// Hopcroft-Karp
// O(E√V)
// dense O(V^2.5)
// sparse O(E)
// Dinic は Hopcroft-Karp の一般化と言える
// augment は残余グラフを流せるかみるから使われていない頂点から探索すればよい
// u - v - w
// DAGの最小パス被覆などに使う
// 常に使用してもいいかも（要検証）
struct HopcroftKarp {
	int n;
	vector<vector<int>> g;
	vector<int> match, dist;
	vector<bool> used, alive;
	HopcroftKarp(int n) : n(n), g(n), match(n), dist(n), used(n), alive(n, true) {}
	void addEdge(int u, int v) {
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	int maximumMatching() {
		int cnt = 0;
		fill(match.begin(), match.end(), -1);
		while (true) {
			buildAlternatingLevelGraph();
			fill(used.begin(), used.end(), false);
			int flow = 0;
			for (int u = 0; u < n; u++) {
				if (!alive[u])continue;
				if (match[u] == -1 && augment(u))
					flow++;
			}
			if (flow == 0)break;
			cnt += flow;
		}
		return cnt;
	}
	void buildAlternatingLevelGraph() {
		fill(dist.begin(), dist.end(), -1);
		queue<int> q;
		for (int u = 0; u < n; u++)
			if (match[u] == -1) {
				q.emplace(u);
				dist[u] = 0;
			}
		while (q.size()) {
			int u = q.front(); q.pop();
			for (int v : g[u]) {
				int w = match[v];
				if (w != -1 && dist[w] == -1) {
					dist[w] = dist[u] + 1;
					q.emplace(w);
				}
			}
		}
	};
	bool augment(int u) {
		used[u] = true;
		for (int v : g[u]) {
			if (!alive[v])continue;
			int w = match[v];
			if (w == -1 || (!used[w] && dist[w] == dist[u] + 1 && augment(w))) {
				match[u] = v;
				match[v] = u;
				used[v] = true;
				return true;
			}
		}
		return false;
	}
};
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2491573
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2491574
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2491582