#include <iostream>
#include <vector>
using namespace std;

const int INF = 50000;
int n, mxL;
int visited[24];
int a[24][24];
int result = INF;

void dfs(int start, int level) {
	if (level == mxL) {
		int sum1 = 0, sum2 = 0;
		vector<int>s1, s2;
		for (int i = 0; i < n; i++) {
			if (visited[i])s1.push_back(i);
			else s2.push_back(i);
		}
		for (int i : s1) for (int j : s1) sum1 += a[i][j];
		for (int i : s2) for (int j : s2) sum2 += a[i][j];
		result = min(result, abs(sum1 - sum2));
		return;
	}
	for (int i = start + 1; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		dfs(i, level + 1);
		visited[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	mxL = n / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	dfs(-1, 0);
	cout << result << '\n';
}