#include <stdio.h>

int main() {
    int a,c;
    scanf("%d %d", &a,&c);
    for (int i = a; i <= c; i++) {
        printf("%d:", i);
        int b = i;
        while (b != 1) {
            if (b % 2 == 1) {  // �������
                b = b * 3 + 1;
            }
            else {  // ż��
                b = b / 2;
            }            
            printf("%d ", b);
        }
        printf("1\n");
    }
    return 0;
}
