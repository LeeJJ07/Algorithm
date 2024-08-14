#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        if (str1.compare(str2) == 0) 
            cout << "Possible\n";
        else 
            cout << "Impossible\n";
    }
    
	return 0;
}