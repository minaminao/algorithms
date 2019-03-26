#include "ModInt.cpp"

// 累積和 (cumulative sum)
// [l, r) : sum[r] - sum[l]
// cumsum.snippet
vector<int> cumsum(const vector<int> &v) {
	int n = v.size();
	vector<int> sum(n + 1);
	for (int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + v[i];
	return sum;
}

// 2次元累積和
// http://arc025.contest.atcoder.jp/submissions/183410
template<typename T>
struct RectangleSum {
	int H, W;
	vector<vector<T>> sum;
	RectangleSum(vector<vector<T>> v)
		:H(v.size()), W(v.front().size()), sum(H + 1, vector<T>(W + 1)) {
		rep(i, 0, H + 1)rep(j, 0, W + 1) {
			sum[i][j] = (i == 0 || j == 0) ? 0 :
				sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + v[i - 1][j - 1];
		}
	}
	// [si, ti), [sj, tj)
	T get(int si, int sj, int ti, int tj) {
		return sum[ti][tj] - sum[si][tj] - sum[ti][sj] + sum[si][sj];
	}
};

// 2次元imos法
struct Imos {
	int X, Y;
	vector<vector<int>> s; //累積和 1-based
	Imos(const vector<vector<int>> &f) :X(f.size()), Y(f[0].size()), s(X + 1, vector<int>(Y + 1)) {
		for (int y = 0; y < Y; y++)
			for (int x = 0; x < X; x++)
				s[x + 1][y + 1] += s[x + 1][y] + s[x][y + 1] - s[x][y] + f[x][y];
	}
	//[x1,x2)かつ[y1,y2)のfieldの和
	int sum(int x1, int y1, int x2, int y2) { return s[x2][y2] - s[x2][y1] - s[x1][y2] + s[x1][y1]; }
};

// 数字和
int digitsum(int x) {
	int sum = 0;
	while (x) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

// ある点から1次元上の点群に対しての距離の総和 O(logn)
/*

- - - -|+ + + +o
- - - -|+ +r
- - -o+|
-o+ + +|

sum[n] - sum[r] - x*(n - r)
- - - -|+ + + +o
- - - -|+ +r

r*x - sum[r]
- - -o+|
-o+ + +|

*/
struct DistanceSum {
	int n;
	vector<int> p;
	vector<int> sum; // [0, i)
	DistanceSum(const vector<int> p_) :n(p_.size()), p(p_), sum(n + 1) {
		sort(p.begin(), p.end());
		for (int i = 0; i < n; i++)
			sum[i + 1] = sum[i] + p[i];
	}
	int get(int x) {
		int r = lower_bound(p.begin(), p.end(), x) - p.begin();
		int d = 0;
		d += r*x - sum[r];
		d += sum[n] - sum[r] - x*(n - r);
		return d;
	}
};

// 1+2+...+n
mint arithsum(int n) {
	return (mint)n*(n + 1) / 2;
}

#include "PopCount.cpp"
#include "Prime.cpp"
// gcd(a, K) = 1, a <= N を満たす a の総和
mint solve(int N, int K) {
	vector<int> factors = primeFactorization(K);
	factors.erase(unique(factors.begin(), factors.end()), factors.end());
	int n = factors.size();
	mint ret = arithsum(N);
	rep(mask, 1, 1 << n) {
		int x = 1;
		rep(i, 0, n)
			if (mask >> i & 1)
				x *= factors[i];
		if (popcount(mask) & 1)
			ret -= arithsum(N / x)*x;
		else
			ret += arithsum(N / x)*x;
	}
	return ret;
}

// gcd(a, K) = g, a <= N を満たす a の総和
mint solve(int N, int K, int g) {
	if (K%g)return 0;
	return solve(N / g, K / g)*g;
}