#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;
	int max = 0;
	int sum = 0;

	double *arr = new double[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
		sum += arr[i];
	}
	double result = (double)sum * 100 / max / N;

	cout << result;
	
	return 0;
}