// Gram–Schmidt の正規直交化法
// n次元のk個の独立なベクトルを正規直交化する
// O(nk^2)
using F = double;
using V = vector<F>;
vector<V> gramSchmidt(const vector<V> &v) {
	const int K = v.size(), N = v.front().size();

	auto product = [&](const V &a, const V &b) {
		F p = 0;
		for (int i = 0; i < N; i++)
			p += a[i] * b[i];
		return p;
	};
	auto projCoef = [&](const V &a, const V &b) {
		return product(a, b) / product(a, a);
	};
	auto unitize = [&](V &a) {
		F p = sqrt(product(a, a));
		for (int j = 0; j < N; j++)
			a[j] /= p;
	};

	vector<V> u(K);
	u[0] = v[0];
	unitize(u[0]);

	for (int i = 1; i < K; i++) {
		u[i] = v[i];
		for (int j = 0; j < i; j++) {
			F p = projCoef(u[j], u[i]);
			for (int k = 0; k < N; k++) {
				u[i][k] = u[i][k] - p * u[j][k];
			}
		}
		unitize(u[i]);
	}

	return u;
}