#include <stdio.h>
#include <stdlib.h>
#define N 101

int main() {
	int n = 100;


	int arr[N] = { 0 };

	int (*ap)[N] = (int*)malloc(sizeof(int) * N);

	//0부터 n까지 배열생성
	for (int i = 0; i <= n; i++) {
		*(arr + i) = i;
	}

	//0~n까지 출력
	printf("0~n까지: ");
	for (int i = 0; i <= n; i++) {
		printf("%d ", *(arr + i));
	}

	printf("\n");
	//n~0까지 출력
	printf("n~0까지: ");
	for (int i = n; i >= 0; i--) {
		printf("%d ", *(arr + i));
	}

	printf("\n");

	int total = 0;
	//총합 출력
	for (int i = 0; i < n; i++) {
		total += *(arr + i);
		;
	}

	printf("총합: %d\n", total);

	//최대 , 최소
	int min = *(arr + 0);

	int max = *(arr + 0);


	for (int i = 0; i <= n; i++) {
		if (arr[i] < min) {
			min = *(arr + i);

		}
		if (arr[i] > max) {
			max = *(arr + i);

		}
	}

	printf("최소: %d, 최대: %d\n", min, max);

	return 0;
}

