#include <iostream>
#include <cmath>
using namespace std;

void canto(int arr[], int N);
void _canto(int arr[], int left, int right);
int main() {
	int N;
	while (cin >> N) {
		int num = pow(3, N);
		int* arr = new int[num];
		canto(arr, num);
		for (int i = 0; i < num; i++) {
			if (arr[i] == 1)
				cout << '-';
			else
				cout << ' ';
		}
		cout << endl;
	}
}

void canto(int arr[], int N) {
	_canto(arr, 0, N - 1);
}
void _canto(int arr[], int left, int right) {
	if (left == right) {
		arr[left] = 1;
		return;
	}
	int mid = (right - left)/3;
	_canto(arr, left, left+mid);
	_canto(arr, right-mid, right);
}