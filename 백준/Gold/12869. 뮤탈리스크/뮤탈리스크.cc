#include <iostream>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<int, int, int> t;
int scv[3];
int dp[64][64][64];
int a[6][3] = {
	{ 9, 3, 1 },
	{ 9, 1, 3 },
	{ 3, 9, 1 },
	{ 3, 1, 9 },
	{ 1, 3, 9 },
	{ 1, 9, 3 }
};

void BFS() {
	queue<t> q;
	q.push({ scv[0], scv[1], scv[2] });
	dp[scv[0]][scv[1]][scv[2]] = 1;
	while (q.size()) {
		t now = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int n1 = max(0, get<0>(now) - a[i][0]);
			int n2 = max(0, get<1>(now) - a[i][1]);
			int n3 = max(0, get<2>(now) - a[i][2]);
			if (dp[n1][n2][n3]) continue;
			dp[n1][n2][n3] = dp[get<0>(now)][get<1>(now)][get<2>(now)] + 1;
			q.push({ n1,n2,n3 });
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> scv[i];
	BFS();
	
	cout << dp[0][0][0] - 1 << '\n';
}