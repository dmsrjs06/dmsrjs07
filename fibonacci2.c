#include <stdio.h>
#include <stdlib.h>
#define N 45

long long fibonacci(int n) {
	if (n <= 1) {
		return n;
	}
	long long previous = 0;
	long long current = 1;

	for (int i = 0; i <= n; i++) {
		long long temp = previous + current;
		previous = current;
		current = temp;
	}
	return current;

}

int main() {
	
	for (int i = 0; i < N; i++) {
		printf("f(%d) = %lld\n", i + 1, fibonacci(i+1));
	}

	return 0;
}