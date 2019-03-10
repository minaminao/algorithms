#include "Graph.cpp"

// トポロジカルソート O(|E|+|V|)
// 入次数が0の点と辺を取り除きながらretに追加
vector<int> topologicalSort(const Graph &g) {
	int n = g.size(), k = 0;
	vector<int> ord(n), indeg(n);
	for (auto &es : g) for (auto &e : es) indeg[e.d]++;
	queue<int> q;
	for (int i = 0; i < n; i++)
		if (indeg[i] == 0)
			q.push(i);
	while (q.size()) {
		int v = q.front(); q.pop(); ord[k++] = v;
		for (auto &e : g[v])
			if (--indeg[e.d] == 0)
				q.push(e.d);
	}
	return *max_element(indeg.begin(), indeg.end()) == 0 ? ord : vector<int>();
}