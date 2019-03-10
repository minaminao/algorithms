// 辞書順
// FordFulkerson 版も実装したい
// 隣接リストを予め辞書順にソートしておく
// で左側から順番にリセットして augment すると、augment の実装により必ず辞書順最小のものがマッチする
// それを確定していけば辞書順最小が求まる
// https://ei1333.github.io/algorithm/bipartite-matching.html
// http://web-ext.u-aizu.ac.jp/pc-concours/2015/download/editorial2015_final_WEB.pdf (問10)
// Hopcroft-Karp を継承したい場合には BipartiteMatching の augment を使うこと
struct LexicographicallyBipartiteMatching :BipartiteMatching {
	LexicographicallyBipartiteMatching(int n) :BipartiteMatching(n) {}
	int maximumMatching() {
		for (int u = 0; u < n; u++)
			sort(g[u].begin(), g[u].end());
		int cnt = BipartiteMatching::maximumMatching();
		for (int u = 0; u < n; u++) {
			if (!alive[u] || match[u] == -1)continue;
			match[match[u]] = -1;
			match[u] = -1;
			fill(used.begin(), used.end(), false);
			augment(u);
			alive[match[u]] = 0;
			alive[u] = 0;
		}
		return cnt;
	}
};
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2489900