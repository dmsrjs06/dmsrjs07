#include <stdio.h>
#include <stdlib.h>
#define N 45

long long fibonacci(long long n) {
	if (n <= 1) {
		return n;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}


int main() {
	
	for (int i = 0; i < N; i++) {
		printf("f(%d)= %lld\n", (i+1), fibonacci(i+1));
	}

	return 0;
};