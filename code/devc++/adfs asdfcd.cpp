#include<stdio.h>
long next(long n) {
	static int num = 0;
    if (n % 2 == 0) {
        n /= 2;
    }
    else {
        n = 3 * n + 1;
    }
    num++;
    printf("Times of %ld is %ld.\n", num, n);
    return n;
}
int main() {
    long n;
    scanf("%ld", &n);
    while (n != 1) {
        n = next(n);
    }
    return 0;
}
