#include "Graph.cpp"
#include "UnionFInd.cpp"

// 最小全域木
// Kruskal法
// 非連結グラフでは最小全域森
// 計算量: O(E log E)
// 引数: グラフ
// 戻り値: (総コスト, 辺集合)
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2235604
pair<Weight, Edges> kruskal(const Graph &g) {
	int n = g.size();
	UnionFind uf(n);
	Edges es;
	for (int i = 0; i < n; i++)
		for (auto &e : g[i])
			es.push_back(e);
	sort(es.begin(), es.end());
	Weight total = 0;
	Edges mst;
	for (auto &e : es)
		if (!uf.same(e.s, e.d)) {
			uf.unite(e.s, e.d);
			mst.push_back(e);
			total += e.w;
		}
	return make_pair(total, mst);
}

// 最小全域木
// Kruskal法
// 非連結グラフでは最小全域森
// 計算量: O(V^2 + E log V) (E = V^2 より log E = 2 log V)
// 引数: グラフ（行列表現）
// 戻り値: (総コスト, 辺集合)
pair<Weight, Edges> kruskal(const Matrix &m) {
	int n = m.size();
	Graph g(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (m[i][j] != INF)
				addArc(g, i, j, m[i][j]);
	return kruskal(g);
}

// 最小全域木 (Minimum Spanning Tree)
// Prim O(|E|log|V|)
// root から到達可能な頂点が対象
pair<Weight, Edges> prim(const Graph &g, int root = 0) {
	int n = g.size();
	Edges mst;
	Weight total = 0;
	vector<bool> v(n);
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	pq.emplace(-1, root, 0);
	while (pq.size()) {
		Edge e = pq.top(); pq.pop();
		if (v[e.d])continue;
		v[e.d] = true;
		total += e.w;
		if (e.s != -1)mst.emplace_back(e);
		for (auto &f : g[e.d])
			if (!v[f.d])
				pq.emplace(f);
	}
	return make_pair(total, mst);
}