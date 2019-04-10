// Activity Selection Problem
// 参加できる活動の個数を最大化
// 個数が同じなら時間を最大化
// [l, r)
// O(n log n)
// Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3472983
using P = pair<int, int>;
vector<P> activitySelectionProblem(vector<P> schedules) {
	int n = schedules.size();
	sort(schedules.begin(), schedules.end(), [](const P &a, const P &b) {return a.second == b.second ? a.first > b.first : a.second < b.second; });
	vector<P> res;
	if (schedules.size())res.push_back(schedules.front());
	for (auto schedule : schedules)
		if (res.back().second <= schedule.first)
			res.emplace_back(schedule);
	return res;
}