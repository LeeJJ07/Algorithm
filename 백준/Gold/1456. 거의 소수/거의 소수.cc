#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long A, B;
	cin >> A >> B;

	long num[10000001];
	for (int i = 2; i <= 10000000; i++) {
		num[i] = i;
	}

	for (int i = 2; i <= sqrt(10000000); i++) {
		if (num[i] == 0)
			continue;
		for (int j = i + i; j <= 10000000; j += i) {
			num[j] = 0;
		}
	}

	int count = 0;
	for (int i = 2; i < 10000001; i++) {
		if (num[i] != 0) {
			long temp = num[i];

			while ((double)num[i] <= (double)B / (double)temp) {
				if ((double)num[i] >= (double)A / (double)temp) {
					count++;
				}
				temp *= num[i];
			}
		}
	}
	cout << count << "\n";
}