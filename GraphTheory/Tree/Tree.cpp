#include "Graph.cpp"
#include "ShortestPath/BFS.cpp"

// 木の直径
// O(E)
Edge diameter(const Graph &g, int s = 0) {
	Array dist;
	bfs(g, s, dist);
	int n = g.size(), u = -1, v = -1;
	for (int i = 0; i < n; i++) if (dist[i] != INF && (u == -1 || dist[i] > dist[u])) u = i;
	bfs(g, u, dist);
	for (int i = 0; i < n; i++) if (dist[i] != INF && (v == -1 || dist[i] > dist[v])) v = i;
	Weight d = dist[v];
	if (u > v) swap(u, v);
	return Edge(u, v, d);
}

// 木の高さ
// 戻り値: 各頂点からの最遠距離
Array height(const Graph &g) {
	Edge e = diameter(g);
	Array dist1, dist2;
	bfs(g, e.s, dist1);
	bfs(g, e.d, dist2);
	int n = g.size();
	Array height(n);
	for (int i = 0; i < n; i++)
		height[i] = max(dist1[i], dist2[i]);
	return height;
}

// 木の深さ
// 戻り値: 各ノードから根ノードまでのエッジ数
vector<int> depth(const Graph &g, int root) {
	vector<int> ret(g.size(), INF);
	using State = tuple<int, int, int>; //ノード 親 深さ
	stack<State> st; st.emplace(root, -1, 0);
	while (st.size()) {
		int s, p, d; tie(s, p, d) = st.top(); st.pop();
		ret[s] = d;
		for (auto &e : g[s]) {
			if (e.d == p)continue;
			st.emplace(e.d, s, d + 1);
		}
	}
	return ret;
}

// 有向森（有向木）の深さ
using P = pair<int, int>; //深さ 根
vector<P> depth(const Graph &g) {
	int n = g.size();
	vector<P> ret(n);
	for (int i = 0; i < n; i++)
		ret[i] = P(0, i);
	vector<bool> isroot(n, true);
	for (int i = 0; i < n; i++)
		for (auto &e : g[i])
			isroot[e.d] = false;
	using State = tuple<int, int, int>; //ノード 根 深さ
	stack<State> st;
	dump(isroot);
	for (int i = 0; i < n; i++)
		if (isroot[i])
			st.emplace(i, i, 0);
	while (st.size()) {
		int s, r, d; tie(s, r, d) = st.top(); st.pop();
		ret[s] = P(d, r);
		for (auto &e : g[s])
			st.emplace(e.d, d + 1);
	}
	return ret;
}

// 無向木を anti-arborescence に変換
// 連結無向グラフから変換することも可能
// (親, weight) の配列を返す
vector<pair<int, Weight>> antiArborescence(const Graph &g, int root = 0) {
	int n = g.size();
	vector<bool> vis(n);
	queue<int> q; q.emplace(root);
	vector<pair<int, Weight>> ret(n); ret[root] = make_pair(-1, 0);
	while (q.size()) {
		int u = q.front(); q.pop();
		if (vis[u])continue;
		vis[u] = true;
		for (auto &e : g[u]) {
			if (vis[e.d])continue;
			ret[e.d] = make_pair(u, e.w);
			q.emplace(e.d);
		}
	}
	return ret;
}



void f() {
	// 頂点 v の親、左の子、右の子
	int tree[100];
	int v; tree[v];
	int p = (v - 1) / 2; tree[p];
	int l = v * 2 + 1; tree[l];
	int r = v * 2 + 2; tree[r];
}

// preorder と inorder から postorder を構築
vector<int> reconstruct_tree(const vector<int> &pre, const vector<int> &in) {
	vector<int> post;
	int pos = 0;
	function<void(int, int)> rec = [&](int l, int r) {
		if (l >= r)return;
		int root = pre[pos++];
		int m = distance(in.begin(), find(in.begin(), in.end(), root));
		rec(l, m);
		rec(m + 1, r);
		post.emplace_back(root);
	};
	rec(0, pre.size());
	return post;
}

struct node_t {
	int val;
	node_t *ch[2];
};
void inorder(node_t* root, string name = "") {
	function<void(node_t*)> rec = [&](node_t *x) {
		if (!x)return;
		rec(x->ch[0]);
		cerr << x->val << " ";
		rec(x->ch[1]);
	};
	cerr << name << ": ";
	rec(root);
	cerr << endl;
}