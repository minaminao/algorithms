#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

// 拡張ユークリッドの互除法
// 一次不定方程式 ax + by = gcd(a, b) を満たす x, y を求める
// ax + by = k * gcd(a, b) は、まず ax + by = gcd(a, b) を解き、解を k 倍する
// 戻り値: gcd(a, b)
long long extgcd(long long a, long long b, long long &x, long long &y) {
	long long g = a; x = 1; y = 0;
	if (b != 0) {
		g = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	return g;
}

//逆元
//xy%m=1, y<m となるyを求める
long long modinv(long long x, long long m) {
	long long s, t;
	extgcd(x, m, s, t);
	return (s + m) % m;
}

int main() {
	long long a = 240, b = 46, c = 4;
	long long x, y;
	long long g = extgcd(a, b, x, y);
	cout << "gcd(a, b) = " << g << endl;
	long long k = c / g;
	cout << "x = " << k * x << ", y = " << k * y << endl;
	return 0;
}