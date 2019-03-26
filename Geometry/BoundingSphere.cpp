#include "Geometry.cpp"

// 最小包含球 山登り法
// 2次 https://en.wikipedia.org/wiki/Smallest-circle_problem
// k次 https://en.wikipedia.org/wiki/Bounding_sphere
// O(N)やO(N^4)解法がある
// k次のPointを実装すればk次に適用可能
void boundingSphere() {
	cout << fixed << setprecision(10);
	for (int N; cin >> N && N;) {
		Polygon p(N);
		// 重み付け
		vector<double> v(N, 1.0);
		rep(i, 0, N)
			cin >> p[i]/* >> v[i]*/;

		Point g = center(p);
		vector<double> cost(N);
		// パラメータは柔軟に変更
		double move = 0.5, y = 0.99;
		while (move > EPS) {
			rep(i, 0, N)
				cost[i] = get_distance(g, p[i]) / v[i];
			int maxidx = max_element(all(cost)) - cost.begin();
			g += (p[maxidx] - g) *move;
			move *= y;
		}

		double ans = 0;
		rep(i, 0, N)
			chmax(ans, get_distance(g, p[i]) / v[i]);
		// 最小の半径
		cout << ans << endl;
	}
}