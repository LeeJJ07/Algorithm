#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 0; i < 3; i++)
    {
        int num;
        int arr[2] = { 0, 0 };
        for (int j = 0; j < 4; j++)
        {
            cin >> num;
            arr[num]++;
        }
        if (arr[0] == 1 && arr[1] == 3) cout << "A\n";
        else if (arr[0] == 2 && arr[1] == 2) cout << "B\n";
        else if (arr[0] == 3 && arr[1] == 1) cout << "C\n";
        else if (arr[0] == 4) cout << "D\n";
        else if (arr[1] == 4) cout << "E\n";
    }

    return 0;
}