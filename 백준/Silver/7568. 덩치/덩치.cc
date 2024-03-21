#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	vector<pair<int, int>> v(n);
	vector<int> level(n);
	for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (v[i].first > v[j].first && v[i].second > v[j].second)
				level[j]++;
		}
	}
	for (int i : level)cout << i + 1 << ' ';
}