#include "Graph.cpp"
#include "AllPairsShortestPaths.cpp"

// The diameter of a given graph using the Floyd–Warshall algorithm
// O(V^3)
// Verified: https://atcoder.jp/contests/agc039/submissions/7881926
int diameter(const Graph &g) {
	Matrix dist;
	floydWarshall(g, dist);
	int n = dist.size();
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ret = max(ret, dist[i][j] == INF ? -1 : (dist[i][j] + 1));
	return ret;
}
