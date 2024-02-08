#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> tree(N+1);
	int num;
	cin >> num;
	tree[1].push_back(num);
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			int a;
			cin >> a;
			if (j == 0) {
				tree[i].push_back(tree[i - 1][j] + a);
			}
			else if (j == i - 1) {
				tree[i].push_back(tree[i - 1][j - 1] + a);
			}
			else {
				tree[i].push_back(max(tree[i - 1][j - 1], tree[i - 1][j]) + a);
			}
		}
	}
	sort(tree[N].begin(), tree[N].end());
	cout << tree[N][N-1] << "\n";
}