#include <iostream>
#include <vector>
using namespace std;

int n, m, check[9];
void combi(int s, int level, vector<int> res) {
	if (level == m) {
		for (int i : res) cout << i << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i]) continue;
		check[i] = 1;
		res.push_back(i);
		combi(i + 1, level + 1, res);
		res.pop_back();
		check[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
		
	cin >> n >> m;
	vector<int> res;
	combi(1, 0, res);
}