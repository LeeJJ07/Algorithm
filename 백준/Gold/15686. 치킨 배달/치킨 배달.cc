#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> yx;
int N, M;
vector<yx> chicken;
vector<yx> house;
vector<int> visited;
vector<int> chosen;
int result = 1e9;
void check() {
	int res = 0;
	for (yx i : house) {
		int mn = 3000;
		for (int j : chosen) {
			mn = min(mn, abs(chicken[j].first - i.first) +
				abs(chicken[j].second - i.second));
		}
		res += mn;
	}
	result = min(result, res);
}
void choose(int start) {
	if (chosen.size() == M) {
		check();
		return;
	}
	for (int i = start + 1; i < chicken.size(); i++) {
		if (visited[i] != 0) continue;
		visited[i] = 1;
		chosen.push_back(i);
		choose(i);
		chosen.pop_back();
		visited[i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			if (num == 2) chicken.push_back({ i,j });
			else if (num == 1) house.push_back({ i,j });
		}
	}
	visited.resize(chicken.size());
	choose(-1);
	cout << result << '\n';
}