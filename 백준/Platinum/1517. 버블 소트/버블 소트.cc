#include <iostream>
#include <vector>
using namespace std;
static vector<int> A;
static vector<int> temp;
static long result = 0;

void mergeSort(int s, int e) {
	if (e - s < 1)return;
	int m = (s + e) / 2;
	mergeSort(s, m);
	mergeSort(m + 1, e);
	for (int i = s; i <= e; i++) temp[i] = A[i];

	int k = s;
	int idx1 = s;
	int idx2 = m + 1;

	while (idx1 <= m && idx2 <= e) {
		if (temp[idx1] > temp[idx2]) {
			result += (idx2 - k);
			A[k++] = temp[idx2++];
		}
		else A[k++] = temp[idx1++];
	}
	while (idx1 <= m) A[k++] = temp[idx1++];
	while (idx2 <= e) A[k++] = temp[idx2++];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	A.resize(N + 1, 0);
	temp.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) cin >> A[i];

	mergeSort(1, N);
	cout << result << '\n';
}