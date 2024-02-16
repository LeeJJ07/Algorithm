#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int sum = 0;
	int s = 1;
	int e = 1;
	int result = 0;
	while (e <= N) {

		if (sum < N) {
			sum += e++;
		}
		else if (sum > N) {
			sum -= s++;
		}
		else {
			result++;
			sum -= s++;
			sum += e++;
		}
	}
	cout << result+1 << '\n';
}