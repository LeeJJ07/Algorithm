#include <iostream>
#include <list>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string input;
    cin >> input;

    list<char> edit_str;
    for (char c : input)
        edit_str.push_back(c);

    int n;
    cin >> n;

    auto it = edit_str.end();

    for (int i = 0; i < n; i++)
    {
        char c, x;
        cin >> c;
        switch (c)
        {
        case 'L':
            if (it == edit_str.begin()) break;
            it--;
            break;
        case 'D':
            if (it == edit_str.end()) break;
            it++;
            break;
        case 'B':
            if (it == edit_str.begin()) break;
            it = edit_str.erase(--it);
            break;
        case 'P':
            cin >> x;
            edit_str.insert(it, x);
            break;
        }
    }

    for (char c : edit_str)
        cout << c;

    return 0;
}