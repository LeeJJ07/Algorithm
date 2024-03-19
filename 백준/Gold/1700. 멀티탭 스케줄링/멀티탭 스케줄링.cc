#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 104;
bool cmp(pair<int, int> a, pair<int, int>b) {
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v(m, {INF, 0});
	for (int i = 0; i < m; i++) {
		cin >> v[i].second;
	}
	for (int i = 0; i < m - 1; i++) {
		for (int j = i + 1; j < m; j++) {
			if (v[i].second == v[j].second) {
				v[i].first = j;
				break;
			}
		}
	}
	vector<pair<int, int>> tmp;
	int result = 0;
	for (int i = 0; i < m; i++) {
		int j;
		for (j = 0; j < tmp.size(); j++) {
			if (v[i].second == tmp[j].second) { 
				tmp[j].first = v[i].first;
				break; 
			}
		}
		if (j == tmp.size()) tmp.push_back(v[i]);
		if (tmp.size() > n) {
			sort(tmp.begin(), tmp.end() - 1, cmp);
			tmp.erase(tmp.begin());
			result++;
		}
	}
	cout << result << '\n';
}