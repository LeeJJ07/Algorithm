#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll arr[100004], n, resA, resB;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int left = 0;
	int right = n - 1;
	ll resLq = abs(arr[left] + arr[right]);
	resA = arr[left];
	resB = arr[right];
	
	while (left < right) {
		ll tmpLq = arr[left] + arr[right];
		if (abs(tmpLq) < resLq) {
			resLq = abs(tmpLq);
			resA = arr[left];
			resB = arr[right];
		}

		if (tmpLq < 0) left++;
		else right--;
	}
	cout << resA << " " << resB << "\n";
}