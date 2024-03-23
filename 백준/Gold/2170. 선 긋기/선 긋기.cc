#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++)cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	int s = v[0].first, e = v[0].second;
	int result = 0;
	for (int i = 1; i < N; i++) {
		if (e < v[i].first) {
			result += (e - s);
			s = v[i].first;
			e = v[i].second;
		}
		else if (v[i].first <= e && v[i].second >= e) {
			e = v[i].second;
		}
	}
	result += e - s;
	cout << result << '\n';
}