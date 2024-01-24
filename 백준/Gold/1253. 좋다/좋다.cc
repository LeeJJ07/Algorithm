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
	vector<int>A(N, 0);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A.begin(), A.end());

	int result = 0;

	for (int k = 0; k < N; k++) {
		int start = 0;
		int end = N - 1;
		while (start < end) {
			if (A[k] == A[start] + A[end]) {
				if (start != k && end != k) {
					result++;
					break;
				}
				else if (start == k) {
					start++;
				}
				else if (end == k) {
					end--;
				}
			}
			else if (A[k] > A[start] + A[end]) {
				start++;
			}
			else {
				end--;
			}
		}
	}
	cout << result << "\n";
}