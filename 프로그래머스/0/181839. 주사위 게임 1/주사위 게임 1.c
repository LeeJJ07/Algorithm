#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b)
{
    int answer = 0;
    answer = (a & 1) && (b & 1) ? a * a + b * b :
        (a & 1) || (b & 1) ? 2 * (a + b) : abs(a - b);
    return answer;
}