#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
map<int, int> m;
map<int, int> mp_first;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return mp_first[a.second] < mp_first[b.second];
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		m[num]++;
		if (mp_first[num] == 0) mp_first[num] = i + 1;
	}
	vector<pair<int,int>> res;
	for (auto it : m) {
		res.push_back({ it.second, it.first });
	}
	sort(res.begin(), res.end(), cmp);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].first; j++) {
			cout << res[i].second << ' ';
		}
	}
}