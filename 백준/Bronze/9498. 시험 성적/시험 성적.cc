#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int score;
    cin >> score;
    score /= 10;

    switch (score)
    {
    case 10:
    case 9:
        cout << 'A';
        break;
    case 8:
        cout << 'B';
        break;
    case 7:
        cout << 'C';
        break;
    case 6:
        cout << 'D';
        break;
    default:
        cout << 'F';
        break;
    }
    
    return 0;
}