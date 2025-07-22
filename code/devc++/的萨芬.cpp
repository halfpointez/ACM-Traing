#include <stdio.h>
#include <string.h>
#include <math.h>
int plus(int a, int b) { return a + b; }
int minus(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }
int mod(int a, int b) { return a % b; }
int factorial(int a) {
    if (a <= 1) return 1;
    return a * factorial(a - 1);
}
int main() {
    int a, b;
    char ope;
    while (1) {
        if (scanf("%d", &a) == EOF) break; 
        if (scanf("%c", &ope) == EOF) break; 
        if (ope == '!') {
            printf("%d\n", factorial(a));
        } else {
            if (scanf("%d", &b) == EOF) break;
            switch (ope) {
                case '+': printf("%d\n", plus(a, b)); break;
                case '-': printf("%d\n", minus(a, b)); break;
                case '*': printf("%d\n", multiply(a, b)); break;
                case '/': 
                    if (b == 0) printf("error\n");
                    else printf("%d\n", divide(a, b));
                    break;
                case '%': 
                    if (b == 0) printf("error\n");
                    else printf("%d\n", mod(a, b));
                    break;
                default: break;
            }
        }
    }

    return 0;
}
