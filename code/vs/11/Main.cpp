#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<cmath>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int main(){
	int arr[5];
	for (int i = 0;i < 5;i++) {
		scanf("%d",&arr[i]);
	}
	int min = arr[0];
	int max = arr[0];
	for (int i = 0;i < 5;i++) {
		max=MAX(arr[i], max);
		min = MIN(arr[i], min);
	}
	printf("%d %d", min, max);
	return 0;

}	