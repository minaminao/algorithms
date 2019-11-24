// https://atcoder.jp/contests/ddcc2020-qual/submissions/8601433
struct InteractiveProblem {
	const int N;
	const int MAX_Q = 210;
	int q;
	vector<int> is_red;
	bool to_server;
	InteractiveProblem(int n, bool to_server) :N(n), q(0), is_red(2 * N), to_server(to_server) {
		random_device rd;
		mt19937 mt(rd());
		set<int> st;
		while (st.size() < N)
			st.emplace(mt() % (2 * N));
		for (auto i : st) {
			is_red[i] = true;
		}
	}
	bool question(vector<int> A) {
		assert(A.size() == N);
		if (to_server) {
			cout << "?";
			rep(i, 0, A.size())
				cout << " " << A[i] + 1;
			cout << endl;
			string res; cin >> res;
			assert(res != "-1");
			return res[0] == 'R';
		}
		else {
			assert(q < MAX_Q);
			q++;

			int cnt = 0;
			for (auto i : A) {
				if (is_red[i])
					cnt++;
			}
			dump(cnt);
			return cnt >= N / 2 + 1;
		}
	}
	void judge(vector<int> ans) {
		if (to_server)return;
		int correct = 0;
		rep(i, 0, 2 * N) {
			if (ans[i] == -1)continue;
			dump(ans[i] == 1, is_red[i]);
			if (ans[i] == is_red[i])correct++;
		}
		dump(correct);
	}
};