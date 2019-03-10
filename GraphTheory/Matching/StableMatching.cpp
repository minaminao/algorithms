// 安定マッチング, 安定結婚問題, stable matching, stable marriage problem
// Gale-Shapley O(N^2)
// not verified
vector<int> stableMatching(const vector<vector<int>>& m_list, const vector<vector<int>>& w_list) {
	int nm = m_list.size(), nw = w_list.size();
	vector<queue<int>> receiver(nm);
	rep(i, 0, nm)rep(j, 0, m_list[i].size())receiver[i].emplace(m_list[i][j]);
	queue<int> proposer;
	rep(i, 0, nm)if (m_list[i].size())proposer.emplace(i);
	vector<vector<int>> w_rank(nw, vector<int>(nm, -1));
	rep(i, 0, nw)rep(j, 0, w_list[i].size())w_rank[i][w_list[i][j]] = j;
	vector<int> w_partner(nw, -1), m_partner(nm, -1);
	while (proposer.size()) {
		int m = proposer.front(); proposer.pop();
		while (receiver[m].size()) {
			int w = receiver[m].front(); receiver[m].pop();
			if (w_partner[w] == -1) {
				w_partner[w] = m; m_partner[m] = w;
				break;
			}
			else {
				int p = w_partner[w];
				if (w_rank[w][m] < w_rank[w][p]) {
					w_partner[w] = m; m_partner[m] = w;
					proposer.emplace(p);
					m_partner[p] = -1;
					break;
				}
			}
		}
	}
	return m_partner;
}