/*
 * 2022.04.20.
 * 
 * 프로그래밍1및 실습 8주차
 * 정수 2의 보수 구현 과제
 * without arrays, functions
 */
#include <stdio.h>
int main(void)
{
	int n, sign, i = 6;
	printf("-128부터 127까지의 십진수 정수 하나를 입력하세요 : ");
	scanf("%d", &n);
	printf("%d의 이진수는 %d", n, sign = n < 0);
	sign && (n = -(n + 1));

	while (i >= 0) {
		printf("%d", (n != n % (1 << i)) ^ sign);
		printf(i == 4 ? " " : "");
		n %= 1 << i--;
	}

	printf(" 입니다.\n");

	return 0;
}