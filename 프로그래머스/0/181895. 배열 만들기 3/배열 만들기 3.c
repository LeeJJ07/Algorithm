#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// intervals_rows는 2차원 배열 intervals의 행 길이, intervals_cols는 2차원 배열 intervals의 열 길이입니다.
int* solution(int arr[], size_t arr_len, int** intervals, size_t intervals_rows, size_t intervals_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int a = intervals[0][0], b = intervals[0][1];
    int c = intervals[1][0], d = intervals[1][1];
    
    int* answer = (int*)malloc((b - a + d - c + 2) * sizeof(int));
    for(int i = a; i<= b;i++){
        answer[i-a] = arr[i];
    }
    for(int i = c; i<=d;i++){
        answer[i-c+b-a+1] = arr[i];
    }
    return answer;
}