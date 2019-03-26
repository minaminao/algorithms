#include "Graph.cpp"
#include "UnionFind.cpp"

// Tarjan's off-line lowest common ancestors (dfs再帰)
// 構築O(N) クエリ(1)
struct Query {
	int u, v;
	Query(int u, int v) :u(u), v(v) {}
};
struct LowestCommonAncestor {
	vector<vector<pair<int, Query>>> query_set;
	Graph g;
	vector<int> color;
	vector<int> ancestor;
	vector<int> res;
	UnionFind uf;
	LowestCommonAncestor(const Graph &g, vector<Query> &query) :g(g), color(g.size()), ancestor(g.size()), uf(g.size()), res(query.size()), query_set(g.size()) {
		int n = query.size();
		for (int i = 0; i < n; i++) {
			query_set[query[i].u].emplace_back(i, query[i]);
			query_set[query[i].v].emplace_back(i, query[i]);
		}
	}
	void visit(int s, int prev) {
		ancestor[uf.root(s)] = s;
		for (auto &e : g[s]) {
			if (e.d == prev)continue;
			visit(e.d, s);
			uf.unite(e.s, e.d);
			ancestor[uf.root(s)] = s;
		}
		color[s] = 1;
		for (auto &p : query_set[s]) {
			Query q = p.second;
			int w = (q.v == s ? q.u : q.u == s ? q.v : -1);
			if (w == -1 || !color[w])continue;
			res[p.first] = ancestor[uf.root(w)];
		}
	}
	vector<int> solve(int root) {
		int n = g.size();
		UnionFind uf(n);
		vector<int> color(n), ancestor(n);
		visit(root, -1);
		return res;
	}
};


// lowest common ancestor (ダブリング + dfs再帰)
// 構築O(NlogN) クエリO(logN)
struct LowestCommonAncestor {
	const int n, log2_n;
	vector<vector<int>> parent;
	vector<int> depth;
	const Graph &g;
	LowestCommonAncestor(const Graph &g, int root)
		:g(g), n(g.size()), log2_n(log2(n) + 1), parent(log2_n, vector<int>(n)), depth(n) {
		dfs(root, -1, 0);
		for (int k = 0; k + 1 < log2_n; k++) {
			for (int v = 0; v < n; v++) {
				if (parent[k][v] < 0)
					parent[k + 1][v] = -1;
				else
					parent[k + 1][v] = parent[k][parent[k][v]];
			}
		}
	}
	void dfs(int s, int p, int d) {
		parent[0][s] = p;
		depth[s] = d;
		for (auto &e : g[s]) {
			if (e.d == p)continue;
			dfs(e.d, s, d + 1);
		}
	}
	int get(int u, int v) {
		if (depth[u] > depth[v]) swap(u, v);
		for (int k = 0; k < log2_n; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v];
			}
		}
		if (u == v) return u;
		for (int k = log2_n - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
};

// lowest common ancestor (ダブリング + dfs非再帰)
// 構築O(NlogN) クエリO(logN)
struct LowestCommonAncestor {
	const Graph &g;
	const int root, n, log2_n;
	vector<vector<int>> parent;
	vector<int> depth;
	LowestCommonAncestor(const Graph &g, int root)
		:g(g), root(root), n(g.size()), log2_n(log2(n) + 1), parent(log2_n, vector<int>(n)), depth(n) {
		dfs();
		for (int k = 0; k + 1 < log2_n; k++) {
			for (int v = 0; v < n; v++) {
				if (parent[k][v] < 0)
					parent[k + 1][v] = -1;
				else
					parent[k + 1][v] = parent[k][parent[k][v]];
			}
		}
	}
	void dfs() {
		using State = tuple<int, int, int>;
		stack<State> st; st.emplace(root, -1, 0);
		while (st.size()) {
			int s, p, d; tie(s, p, d) = st.top(); st.pop();
			parent[0][s] = p;
			depth[s] = d;
			for (auto &e : g[s]) {
				if (e.d == p)continue;
				st.emplace(e.d, s, d + 1);
			}
		}
	}
	int get(int u, int v) {
		if (depth[u] > depth[v]) swap(u, v);
		for (int k = 0; k < log2_n; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v];
			}
		}
		if (u == v) return u;
		for (int k = log2_n - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
};