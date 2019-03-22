#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

// 最小重み三角形分割（Minimum-weight triangulation）
// 凸多角形を三角形分割した時に辺の長さの総和を最小にする
// ユークリッド平面である必要はない
// O(n^3)
int minimumWeightTriangulation(vector<vector<int>> w) {
	const int n = w.size();
	vector<vector<int>> dp(n, vector<int>(n, -1));

	function<int(int, int)> f = [&](int i, int j) {
		if (dp[i][j] != -1)return dp[i][j];
		if (i + 1 == j)
			return dp[i][j] = w[i][j];
		int ret = INF;
		for (int k = i + 1; k < j; k++) {
			chmin(ret, f(i, k) + f(k, j) + w[i][j]);
		}
		return dp[i][j] = ret;
	};
	return f(0, n - 1);
}

// 最小重み三角形分割（Minimum-weight triangulation）
// 三角形の重みを頂点ラベルの積とする
// 積の総和を最小化
// O(n^3)
//
// Verified: http://codeforces.com/contest/1140/submission/51720693
int minimumWeightTriangulation(vector<int> d) {
	const int n = d.size();
	vector<vector<int>> dp(n, vector<int>(n, -1));

	function<int(int, int)> f = [&](int i, int j) {
		if (dp[i][j] != -1)return dp[i][j];
		if (i + 2 == j)
			return dp[i][j] = d[i] * d[i + 1] * d[i + 2];
		// 頂点が 2 つしかないときは 0 と繋がる
		if (i + 1 == j)
			return dp[i][j] = d[i] * d[i + 1] * d[0];
		int ret = INF;
		for (int k = i + 2; k < j; k++) {
			chmin(ret, f(i, k) + f(k, j));
		}
		return dp[i][j] = ret;
	};
	return f(0, n - 1);
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	random_device rd;
	mt19937 mt(rd());

	// 凸多角形ではないが解ける
	vector<vector<int>> w =
	{
	{ 0,3,4,3 },
	{ 3,0,3,5 },
	{ 4,3,0,3 },
	{ 3,5,3,0 }
	};

	dump(w);
	dump(minimumWeightTriangulation(w));


	int n = 4;

	vector<int> d(n);
	rep(i, 0, n) {
		d[i] = mt() % 10 + 1;
	}
	dump(d);
	dump(minimumWeightTriangulation(d));



	return 0;
}