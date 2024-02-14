#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> A(101 , 0);
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++) {
		int start, end;
		cin >> start >> end;
		for (int j = start; j < end; j++) {
			A[j]++;
		}
	}
	int result = 0;
	for (int i = 1; i <= 100; i++) {
		if (A[i] == 3) {
			result += c*3;
		}
		else if (A[i] == 2) {
			result += b*2;
		}
		else if (A[i] == 1) {
			result += a;
		}
	}
	cout << result << '\n';
}