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
	ModInt operator-()const { return ModInt(MOD - (signed)x); }
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

using mint = ModInt<MOD>;



// 動的に法を決める ModInt
// Verified: https://yukicoder.me/submissions/331164
struct DModInt {
	static int kMod;
	unsigned x;
	DModInt() :x(0) {}
	DModInt(signed x_) { x_ %= kMod; if (x_ < 0)x_ += kMod; x = x_; }
	DModInt(signed long long x_) { x_ %= kMod; if (x_ < 0)x_ += kMod; x = x_; }
	int get()const { return (int)x; }
	DModInt &operator+=(DModInt m) { if ((x += m.x) >= kMod)x -= kMod; return *this; }
	DModInt &operator-=(DModInt m) { if ((x += kMod - m.x) >= kMod)x -= kMod; return *this; }
	DModInt &operator*=(DModInt m) { x = (unsigned long long)x*m.x%kMod; return *this; }
	DModInt &operator/=(DModInt m) { return *this *= m.inverse(); }
	DModInt operator+(DModInt m)const { return DModInt(*this) += m; }
	DModInt operator-(DModInt m)const { return DModInt(*this) -= m; }
	DModInt operator*(DModInt m)const { return DModInt(*this) *= m; }
	DModInt operator/(DModInt m)const { return DModInt(*this) /= m; }
	DModInt operator-()const { return DModInt(kMod - x); }
	bool operator==(DModInt m)const { return x == m.x; }
	bool operator!=(DModInt m)const { return x != m.x; }
	DModInt inverse()const {
		signed a = x, b = kMod, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		if (u < 0)u += kMod;
		return DModInt(u);
	}
};
int DModInt::kMod = INF; // stream 用。最大の法より大きな数にしておく
ostream &operator<<(ostream &os, const DModInt &m) { return os << m.x; }
istream &operator>>(istream &is, DModInt &m) { signed long long s; is >> s; m = DModInt(s); return is; };

DModInt pow(DModInt a, unsigned long long k) {
	DModInt r = 1;
	while (k) {
		if (k & 1)r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}

using mint = DModInt;