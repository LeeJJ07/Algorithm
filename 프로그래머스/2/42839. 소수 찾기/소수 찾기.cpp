#include <string>
#include <vector>

using namespace std;

int answer = 0;
int chkNum[10000004];
bool isPrime(int num)
{
    if (num == 1 || num == 0) return false;
    for (int i = 2; i * i <= num; i++)
        if (!(num % i))
            return false;
    return true;
}
void dfs(vector<int> numbers, int * check, int number, int depth)
{
    if (isPrime(number) && !chkNum[number]) answer++;
    chkNum[number] = 1;

    if (depth == numbers.size())
        return;

    for (int i = 0; i < numbers.size(); i++)
    {
        if (check[i]) continue;
        check[i] = 1;
        dfs(numbers, check, number * 10 + numbers[i], depth + 1);
        check[i] = 0;
    }
}

int solution(string numbers)
{
    vector<int> arr;
    int* check = (int*)calloc(numbers.size(), sizeof(int));
    for (int i = 0; i < numbers.size(); i++)
        arr.push_back(numbers[i] - '0');

    for (int i = 0; i < arr.size(); i++)
    {
        check[i] = 1;
        dfs(arr, check, arr[i], 1);
        check[i] = 0;
    }
    return answer;
}