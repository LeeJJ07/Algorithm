#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> check(26);

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
		check[str[i] - 'a']++;
	
	for (int i : check)
		cout << i << ' ';

	return 0;
}