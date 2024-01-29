#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool pl(int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;

	int A[10000001];
	for (int i = 2; i <= 10000000; i++) {
		A[i] = i;
	}

	for (int i = 2; i <= sqrt(10000000); i++) {
		if (A[i] == 0)
			continue;
		for (int j = i + i; j <= 10000000; j += i) {
			A[j] = 0;
		}
	}
	int i = N;
	while (true) {
		if (A[i] != 0 && pl(A[i])) {
			cout << A[i] << "\n";
			break;
		}
		i++;
	}
}
bool pl(int num) {
	string arr = to_string(num);
	char const* temp = arr.c_str();
	int s = 0;
	int e = arr.size() - 1;

	while (s < e) {
		if (temp[s] != temp[e]) {
			return false;
		}
		s++; e--;
	}
	return true;
}