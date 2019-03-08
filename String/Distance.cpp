#include "template.cpp"

// ハミング距離
// 等しい文字数を持つ２つの文字列の中で対応する位置にある異なった文字の個数
int hamming_distance(const string &a, const string &b) {
	assert(a.size() == b.size());
	int cnt = 0;
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i])
			cnt++;
	return cnt;
}

// レーベンシュタイン距離 (編集距離)
// a に操作 {挿入, 削除, 置換} を行い b と等しくするための操作の最小回数
// a, b に操作 {挿入, 置換} を行い両者を等しくするための操作の最小回数とも言える
// 時間 O(mn) 空間 O(mn)
int levenshteinDistance(const string &a, const string &b) {
	int m = a.size(), n = b.size();
	vector<vector<int>> ld(m + 1, vector<int>(n + 1, INF));

	rep(i, 0, m + 1)ld[i][0] = i;
	rep(j, 0, n + 1)ld[0][j] = j;
	rep(i, 1, m + 1)rep(j, 1, n + 1) {
		ld[i][j] = min({
			// 挿入(aに)
			ld[i - 1][j] + 1,
			// 削除(bから) or 挿入(bに)
			ld[i][j - 1] + 1,
			// 置換 
			ld[i - 1][j - 1] + (a[i - 1] != b[j - 1])
			});
	}
	return ld[m][n];
}

//レーベンシュタイン距離 (編集距離)
//時間 O(mn) 空間 O(m)
int levenshteinDistance(const string &a, const string &b) {
	int m = a.size(), n = b.size();
	int column_start = 1;
	vector<int> column(m + 1);
	iota(column.begin() + column_start, column.begin() + m + 1, column_start);
	for (int x = column_start; x <= n; x++) {
		column[0] = x;
		int last_diagonal = x - column_start;
		for (int y = column_start; y <= m; y++) {
			int old_diagonal = column[y];
			column[y] = min({
				column[y] + 1,
				column[y - 1] + 1,
				last_diagonal + (a[y - 1] != b[x - 1])
				});
			last_diagonal = old_diagonal;
		}
	}
	return column[m];
}
//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2235636

// レーベンシュタイン距離の繰り返し文字列にする版
// 繰り返しなので遷移が循環する
// 2周みればよい。もし3周目に更新できるならば負閉路と同じ原理で無限に編集距離が小さくなるため。
int yahooDistance(const string &a, const string &b) {
	int m = a.size(), n = b.size();
	vector<vector<int>> ld(m + 1, vector<int>(n, INF));

	rep(i, 0, m + 1)ld[i][0] = i;
	rep(j, 0, n)ld[0][j] = j;
	rep(i, 1, m + 1) {
		rep(j, 1, n + 1) {
			ld[i][j%n] = min({
				ld[i - 1][j%n] + 1,
				ld[i][j - 1] + 1,
				ld[i - 1][j - 1] + (a[i - 1] != b[j - 1])
				});
		}
		rep(j, 1, n + 1) {
			ld[i][j%n] = min({
				ld[i - 1][j%n] + 1,
				ld[i][j - 1] + 1,
				ld[i - 1][j - 1] + (a[i - 1] != b[j - 1])
				});
		}
	}
	return ld[m][0];
}
// http://yahoo-procon2017-final-open.contest.atcoder.jp/submissions/1477181

// Damerau-Levenshtein distance
// Levenshtein distance に transposition (隣同士をswap) を追加
// ca -> ac がコスト1
// アルゴリズムがいまいち理解できてない
// https://en.wikipedia.org/wiki/Damerau–Levenshtein_distance
// wiki の実装は添字が間違っている。元の論文が正しい。
// https://doi.org/10.1145%2F363958.363994
// http://id.fnshr.info/2011/11/29/damerau/
// 説明だけ わかりやすい
int damerauLevenshteinDistance(const string &a, const string &b) {
	int m = a.size(), n = b.size();
	vector<vector<int>> d(m + 1, vector<int>(n + 1, INF));
	static int da[128];
	memset(da, 0, sizeof(da));
	rep(i, 0, m + 1)d[i][0] = i;
	rep(j, 0, n + 1)d[0][j] = j;
	rep(i, 1, m + 1) {
		int db = 0;
		rep(j, 1, n + 1) {
			int k = da[b[j - 1]];
			int l = db;
			int cost = 1;
			if (a[i - 1] == b[j - 1]) {
				cost = 0;
				db = j;
			}
			d[i][j] = min({
				d[i - 1][j] + 1,
				d[i][j - 1] + 1,
				d[i - 1][j - 1] + cost
				});
			if (k - 1 >= 0 && l - 1 >= 0) {
				chmin(d[i][j], d[k - 1][l - 1] + (i - k - 1) + 1 + (j - l - 1));
			}
		}
		da[a[i - 1]] = i;
	}
	return d[m][n];
}
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2475042