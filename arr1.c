#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 101
//마방진 - 가로 세로 대각선의 합이 같아야 하는 마법 상수를 먼저 정하고,
//빈칸을 조건에 맞게 좁혀 채워라
int main() {

	int n = 100;

	int arr[N] = {0};

	//0부터 n까지 배열생성
	for (int i = 0; i <= n; i++) {
		arr[i] = i;
	}

	//0~n까지 출력
	printf("0~n까지: ");
	for (int i = 0; i <= n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
	//n~0까지 출력
	printf("n~0까지: ");
	for (int i = n; i >= 0; i--) {
		printf("%d ", arr[i]);
	}

	printf("\n");

	int total = 0;
	//총합 출력
	for (int i = 0; i < n; i++) {
		total += arr[i];
	}

	printf("총합: %d\n", total);

	//최대 , 최소
	int min = arr[0];
	int max = arr[0];

	for (int i = 0; i <= n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	printf("최소: %d, 최대: %d\n", min, max);

	return 0;
}