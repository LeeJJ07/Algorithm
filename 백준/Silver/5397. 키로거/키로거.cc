#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;
    
    string str;
   
    while (t--)
    {
        cin >> str;
        list<char> arrList;
        auto it = arrList.begin();

        for (char c : str)
        {
            if (c == '<')
            {
                if (it == arrList.begin()) continue;
                it--;
            }
            else if (c == '>')
            {
                if (it == arrList.end()) continue;
                it++;
            }
            else if (c == '-')
            {
                if (it == arrList.begin()) continue;
                it = arrList.erase(--it);
            }
            else
            {
                arrList.insert(it, c);
            }
        }
        for (char c : arrList)
            cout << c;
        cout << '\n';
    }
    return 0;
}