#include <vector>
#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> t(101), cost(4);
	int s, e, result = 0;
	for (int idx = 1; idx < 4;idx++)
		cin >> cost[idx];
	for (int n = 0; n < 3;n++) {
		cin >> s >> e;
		for (int idx = s; idx < e;idx++)
			t[idx]++;
	}

	for (int idx = 1;idx < 101;idx++)
		result += cost[t[idx]] * t[idx];

	cout << result;
}