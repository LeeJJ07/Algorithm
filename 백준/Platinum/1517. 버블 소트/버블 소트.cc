#include <iostream>
#include <vector>
using namespace std;

static vector<int> A;
static vector<int> tmp;
void mergeSort(int s, int e);
static long result = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	A = vector<int>(N + 1, 0);
	tmp = vector<int>(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	mergeSort(1, N);
	
	cout << result;
}
void mergeSort(int s, int e) {
	if (e - s < 1)
		return;

	int m = (s + e) / 2;
	mergeSort(s, m);
	mergeSort(m + 1, e);

	for (int i = s; i <= e; i++) {
		tmp[i] = A[i];
	}

	int k = s;
	int index1 = s;
	int index2 = m + 1;

	while (index1 <= m && index2 <= e) {
		if (tmp[index1] > tmp[index2]) {
			A[k] = tmp[index2];
			result += (index2 - k);
			index2++;
			k++;
		}
		else {
			A[k++] = tmp[index1++];
		}
	}

	while (index1 <= m) {
		A[k++] = tmp[index1++];
	}
	while (index2 <= e) {
		A[k++] = tmp[index2++];
	}
}