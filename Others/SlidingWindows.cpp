//しゃくとり法
void sliding_window(const vector<int> &a) {
	int n = a.size(), l = 0, r = 0;
	while (l < n) {
		if (r == n) {
			//break;
			a[l];
			l++;
		}
		//区間を狭める
		else if (1/*区間が広げられない条件*/) {
			/* 処理 */
			if (l == r) {
				l++, r++;
			}
			else {
				a[l];
				l++;
			}
		}
		//区間を広げる
		else {
			a[r];
			r++;
		}
	}
}

//a_l + a_l+1 + ... + a_r-1 >= S となる部分列の長さ r-l の最小値
int smallest_window(const vector<int> &a, int S) {
	int n = a.size(), l = 0, r = 0;
	int sum = 0;
	int ret = INF;
	while (l < n) {
		if (r == n) {
			sum -= a[l];
			l++;
		}
		else if (sum + a[r] >= S) {
			chmin(ret, r + 1 - l);
			if (l == r) {
				l++, r++;
			}
			else {
				sum -= a[l];
				l++;
			}
		}
		else {
			sum += a[r];
			r++;
		}
	}
	return ret == INF ? 0 : ret;
}

//a_l + a_l+1 + ... + a_r-1 <= x を満たす [l, r) の個数 
int number_of_windows(const vector<int> &a, int x) {
	int n = a.size(), l = 0, r = 0;
	int num = 0;
	int sum = 0;
	while (l < n) {
		if (r == n || sum + a[r] > x) {
			if (l == r) {
				l++, r++;
			}
			else {
				num += r - l;
				sum -= a[l];
				l++;
			}
		}
		else {
			sum += a[r];
			r++;
		}
	}
	return num;
}

//要素が互いに異なる部分列の長さ r-l の最大値
int sliding_window2(const vector<int> &a) {
	int n = a.size(), l = 0, r = 0;
	int ret = 0;
	unordered_set<int> st;
	while (l < n) {
		if (r == n) {
			break;
		}
		//区間を狭める
		else if (st.count(a[r])) {
			st.erase(a[l]);
			if (l == r) {
				l++, r++;
			}
			else {
				a[l];
				l++;
			}
		}
		//区間を広げる
		else {
			st.emplace(a[r]);
			r++;
		}
		chmax(ret, r - l);
	}
	return ret;
}