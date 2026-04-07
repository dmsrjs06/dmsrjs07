/*#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define N 30


	int main() {


		int num1;
		scanf_s("%d", &num1);
		if (num1 % 2 == 0) {
			return;
		}

		int arr[N][N] = { 0 };

		int (*ap)[N] = (int*)malloc(sizeof(int) * N);	


		int i = 0;        // 첫 번째 행
		int j = num1 / 2;    // 가운데 열
		for (int num = 1; num <= num1 * num1; num++) {
			*(*(arr + i) + j) = num;

			int next_i = (i - 1 + num1) % num1;
			int next_j = (j + 1) % num1;

			if (arr[next_i][next_j] != 0) {
				i = (i + 1) % num1;
			}
			else {
				i = next_i;
				j = next_j;
			}
		}

		for (int r = 0; r < num1; r++) {
			for (int c = 0; c < num1; c++) {
				printf("%d ", *(*(arr + r) + c));
			}
			printf("\n");
		}

		return 0;
	}