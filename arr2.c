#include <stdio.h>
#define N 50

void errordefect(int n) {
    if (n % 2 == 0) {
        printf("홀수만 입력.\n");
        return;
    }
    printf("\n");
    //배열 생성
    int arr[N][N] = { 0 };

    int i = 0;        // 첫 번째 행
    int j = n / 2;    // 가운데 열
    for (int num = 1; num <= n * n; num++) {
        arr[i][j] = num;

        int next_i = (i - 1 + n) % n;
        int next_j = (j + 1) % n;

        if (arr[next_i][next_j] != 0) {
            i = (i + 1) % n;
        }
        else {
            i = next_i;
            j = next_j;
        }
    }

    // 출력
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            printf("%d ", arr[r][c]);
        printf("\n");
    }
    printf("\n");

    // 합 체크
    int targetSum = n * (n * n + 1) / 2 / n; // 마방진의 기본 합

    // 행 합
    for (int r = 0; r < n; r++) {
        int sum = 0;
        for (int c = 0; c < n; c++) sum += arr[r][c];
        printf("행 합 %d = %d\n",r+1, sum);
    }
    printf("\n");
    // 열 합
    for (int c = 0; c < n; c++) {
        int sum = 0;
        for (int r = 0; r < n; r++) sum += arr[r][c];
        printf("열 합 %d = %d\n",c+1, sum);
    }
    printf("\n");
    // 대각선 합
    int diag1 = 0, diag2 = 0;
    for (int k = 0; k < n; k++) {
        diag1 += arr[k][k];
        diag2 += arr[k][n - 1 - k];
    }
    printf("대각선 합1 = %d\n", diag1);
    printf("대각선 합2 = %d\n", diag2);
    printf("\n");
}

int main() {
    int n;
    printf("홀수 크기 입력: ");
    scanf_s("%d", &n);

    errordefect(n);

    return 0;
}