#include "Graph.cpp"
#include "UnionFind.cpp"

// 無向グラフが連結グラフか判定 O(|E|α(|E|))
bool isConnectedGraph(const Graph &udg) {
	int n = udg.size();
	UnionFind uf(n);
	for (auto &es : udg)for (auto &e : es) uf.unite(e.d, e.s);
	return uf.size == 1;
}

// 無向グラフがオイラーグラフか判定（オイラー閉路を持つ）
pair<bool, vector<int>> isEulerianGraph(const Graph &udg) {
	if (!isConnectedGraph(udg))return false;
	int n = udg.size();
	vector<int> degree(n, 0);
	for (auto &es : udg)for (auto &e : es)
		degree[e.d]++, degree[e.s]++;
	bool ok = true;
	for (auto &d : degree) {
		d /= 2;
		if (d % 2)
			ok = false;
	}
	return make_pair(ok, degree);
}

//無向グラフが準オイラーグラフか判定（閉路でないオイラー路を持つ）
bool isSemiEulerianGraph(const Graph &udg) {
	if (!isConnectedGraph(udg))return false;
	int n = udg.size();
	vector<int> degree(n, 0);
	for (auto &es : udg)for (auto &e : es) 
		degree[e.d]++, degree[e.s]++;
	int odd = 0;
	for (auto &d : degree) {
		if ((d / 2) % 2)odd++;
		if (odd > 2)return false;
	}
	return odd == 2;
}