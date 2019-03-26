template<int MOD>
struct ModInt {
	static const int kMod = MOD;
	unsigned x;
	ModInt() :x(0) {}
	ModInt(signed x_) { x_ %= MOD; if (x_ < 0)x_ += MOD; x = x_; }
	ModInt(signed long long x_) { x_ %= MOD; if (x_ < 0)x_ += MOD; x = x_; }
	int get()const { return (int)x; }
	ModInt &operator+=(ModInt m) { if ((x += m.x) >= MOD)x -= MOD; return *this; }
	ModInt &operator-=(ModInt m) { if ((x += MOD - m.x) >= MOD)x -= MOD; return *this; }
	ModInt &operator*=(ModInt m) { x = (unsigned long long)x*m.x%MOD; return *this; }
	ModInt &operator/=(ModInt m) { return *this *= m.inverse(); }
	ModInt operator+(ModInt m)const { return ModInt(*this) += m; }
	ModInt operator-(ModInt m)const { return ModInt(*this) -= m; }
	ModInt operator*(ModInt m)const { return ModInt(*this) *= m; }
	ModInt operator/(ModInt m)const { return ModInt(*this) /= m; }
	ModInt operator-()const { return ModInt(kMod - x); }
	bool operator==(ModInt m)const { return x == m.x; }
	bool operator!=(ModInt m)const { return x != m.x; }
	ModInt inverse()const {
		signed a = x, b = MOD, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		if (u < 0)u += MOD;
		return ModInt(u);
	}
};
template<int MOD>
ostream &operator<<(ostream &os, const ModInt<MOD> &m) { return os << m.x; }
template<int MOD>
istream &operator>>(istream &is, ModInt<MOD> &m) { signed long long s; is >> s; m = ModInt<MOD>(s); return is; };

using mint = ModInt<MOD>;

template<int MOD>
ModInt<MOD> pow(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while (k) {
		if (k & 1)r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}
