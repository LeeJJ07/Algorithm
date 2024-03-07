#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 98765432;
int n;
int minRes = INF;
int minidx = -1;
int nur[4];
int others[20][5];
map<int, vector<vector<int>>> ret_v;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < 4; i++) cin >> nur[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> others[i][j];
		}
	}
	int j;
	for (int i = 0; i < (1 << n); i++) {
		int sum[5] = { 0, 0, 0, 0, 0 };
		vector<int> v;
		for (j = 0; j < n; j++) {
			if (i & (1 << j)) {
				v.push_back(j + 1);
				for (int k = 0; k < 5; k++) {
					sum[k] += others[j][k];
				}
			}
		}
		for (j = 0; j < 4; j++) {
			if (nur[j] > sum[j]) break;
		}
		if (j == 4 && sum[j] <= minRes) {
			minRes = sum[j];
			ret_v[minRes].push_back(v);
		}
	}
	if (minRes == INF) cout << -1;
	else {
		sort(ret_v[minRes].begin(), ret_v[minRes].end());
		cout << minRes << '\n';
		for (int a : ret_v[minRes][0]) {
			cout << a << ' ';
		}
	}
}