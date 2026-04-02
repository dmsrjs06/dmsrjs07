#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

int main() {

	int n;

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("%d 번째 %lld\n",i+1, fibonacci(i+5) );
	}

	for (int i = 0; i < n; i++) {
		long long a = fibonacci(i + 5);
		long long b = fibonacci(i + 6);
		printf("%d번째 최대공약수: %lld \n",i+1, gcd(a, b));
	}


	return 0;
}