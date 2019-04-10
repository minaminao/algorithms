// 多項式
// C ⊆ X であること
template<typename C, typename X>
struct Polynomial {
	vector<C> coef;
	Polynomial(int d) :coef(d + 1) {}
	int degree()const { return coef.size() - 1; }
	C operator[](int i)const { return i > degree() ? C() : coef[i]; }
	X operator()(const X &x)const {
		int d = degree();
		X y = 0, t = 1;
		for (int i = 0; i <= d; i++) {
			y += t * coef[i];
			t *= x;
		}
		return y;
	}
	void trim() {
		int i = coef.size();
		while (i > 0 && coef[i] == C())i--;
		coef.resize(i);
	}
};