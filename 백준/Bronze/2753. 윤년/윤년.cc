#include <iostream>

using namespace std;

bool isLeapYear(int y);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int y;
    cin >> y;
    cout << isLeapYear(y);
    
    return 0;
}

bool isLeapYear(int y)
{
    if (((y % 4 == 0) && (y % 100)) || (y % 400 == 0))
        return true;
    return false;
}