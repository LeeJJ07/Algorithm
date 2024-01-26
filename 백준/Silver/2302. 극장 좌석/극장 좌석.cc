#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector <int>vip(M, 0);
	for (int i = 0; i < M; i++) {
		cin >> vip[i];
	}
	sort(vip.begin(), vip.end());
	vector <int>check(41, 1);
	for (int i = 2; i < 41; i++) {
		check[i] = check[i - 1] + check[i - 2];
	}

	int count = 0;
	int vipIdx = 0;
	int result = 1;
	for (int i = 0; i < N; i++) {
		if (vipIdx < M) {
			if (vip[vipIdx] == i+1) {
				result *= check[count];
				vipIdx++;
				count = -1;
			}
		}
		count++;
	}
	if (count != 0) {
		result *= check[count];
	}
	cout << result;
}