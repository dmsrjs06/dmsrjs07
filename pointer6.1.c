#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    int num1;
    scanf("%d", &num1);
    if (num1 % 2 == 0) {
        printf("홀수만 입력 가능합니다.\n");
        return 0;
    }
    //동적할당
    int* arr = (int*)malloc(sizeof(int) * num1 * num1);
    if (arr == NULL) {
        return 0;
    }

    //초기화
    for (int k = 0; k < num1 * num1; k++) {
        *(arr + k) = 0;
    }

    int i = 0;
    int j = num1 / 2;
    for (int num = 1; num <= num1 * num1; num++) {
        *(arr + i * num1 + j) = num;

        int next_i = (i - 1 + num1) % num1;
        int next_j = (j + 1) % num1;

        if (*(arr + next_i * num1 + next_j) != 0) {
            i = (i + 1) % num1;
        }
        else {
            i = next_i;
            j = next_j;
        }
    }

    // 출력
    for (int r = 0; r < num1; r++) {
        for (int c = 0; c < num1; c++) {
            printf("%3d ", *(arr + r * num1 + c));
        }
        printf("\n");
    }

    free(arr);
    return 0;
}
