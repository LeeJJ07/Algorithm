#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	cin >> M;
	vector<int> source(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> source[i];
	}
	sort(source.begin(), source.end());

	int start = 0;
	int end = N-1;
	int result = 0;

	while (start<end) {
		if (M == source[start] + source[end]) {
			result++;
			start++;
			end--;
		}
		else if (M > source[start] + source[end]) {
			start++;
		}
		else {
			end--;
		}
	}
	cout << result << "\n";
}