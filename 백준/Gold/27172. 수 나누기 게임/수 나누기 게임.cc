#include <iostream>
using namespace std;
int arr[100004], n;
int card[1000004],res[1000004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) { 
		cin >> arr[i];
		card[arr[i]] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = arr[i] * 2; j < 1000001; j += arr[i]) {
			if (card[j] == 1) {
				res[arr[i]]++;
				res[j]--;
			}
		}
	}
	for (int i = 0; i < n; i++) cout << res[arr[i]] << " ";
}