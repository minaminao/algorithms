// 最大独立集合問題 / 最大重み独立集合問題
// O(1.466^n n)
// https://www.slideshare.net/wata_orz/ss-12131479/30
// Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3703905
const int MAX_N = 41;
int weight[MAX_N];
vector<int> G[MAX_N];
int N;
int dfs(long long flag, int w) {
	if ((1LL << N) - 1 == flag)return w;
	int v = 0;
	rep(i, 0, N) {
		if (!(flag >> i & 1)) {
			v = i;
			break;
		}
	}
	int deg = 0;
	int max_weight = weight[v];
	for (auto x : G[v])
		if (!(flag >> x & 1)) {
			deg++;
			max_weight = max(max_weight, weight[x]);
		}
	int ret = 0;
	// v を使わない
	flag |= 1LL << v;
	if (deg >= 2 || max_weight > weight[v]) {
		ret = dfs(flag, w);
	}
	// v を使う
	for (auto x : G[v])
		flag |= 1LL << x;
	ret = max(ret, dfs(flag, w + weight[v]));
	return ret;
}
