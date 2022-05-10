/*
* 2022.05.11.
* 
* 프로그래밍1및실습 10주차
* 8비트 이진수 변환기, 계산기 구현 과제
* without arrays
*/
#include <stdio.h>

void whiteSpaceRemove();
int inputBinary_and_returnDecimal();
void convertIntoBinary_and_print(int n);

void binary_conversion();
void binary_add();
void binary_subtract();

int main(void) {
	int n;
	printf("1. 이진수 변환기\t2. 이진수 덧셈기\t3. 이진수 뺄셈기\n\n");
	printf("번호를 선택하세요 : ");
	scanf_s("%d", &n);

	switch (n) {
	case 1: binary_conversion(); break;
	case 2: binary_add(); break;
	case 3: binary_subtract(); break;
	default: printf("유효한 숫자를 입력하세요.\n"); break;
	}

	return 0;
}

void binary_conversion() {
	printf("8비트 이진수를 입력하세요 : ");
	int val = inputBinary_and_returnDecimal();
	printf("십진수로 %d입니다.\n", val);
}

void binary_add() {
	printf("첫 번째 8비트 이진수를 입력하세요 : ");
	int n1 = inputBinary_and_returnDecimal();
	printf("두 번째 8비트 이진수를 입력하세요 : ");
	int n2 = inputBinary_and_returnDecimal();
	
	int sum = n1 + n2;
	printf("두 이진수의 합은 ");
	convertIntoBinary_and_print(sum);
	printf("이고, 십진수로 %d 입니다.", sum);
}

void binary_subtract() {
	printf("첫 번째 8비트 이진수를 입력하세요 : ");
	int n1 = inputBinary_and_returnDecimal();
	printf("두 번째 8비트 이진수를 입력하세요 : ");
	int n2 = inputBinary_and_returnDecimal();

	int sub = n1 - n2;
	printf("두 이진수의 합은 ");
	convertIntoBinary_and_print(sub);
	printf("이고, 십진수로 %d 입니다.", sub);
}

void whiteSpaceRemove() {
	char c;
	while ((c = getchar()) == ' ');
}

int inputBinary_and_returnDecimal() {
	whiteSpaceRemove();
	int value = 0, t;
	int sign = getchar() - '0';

	for (int i = 6; i >= 0; i--) {
		t = getchar() - '0';
		value += (t ^ sign) * (1 << i);
	}

	if (sign) 
		return -(value + 1);

	return value;
}

void convertIntoBinary_and_print(int n) {
	int sign;
	(sign = n < 0) && (n = -(n + 1));

	for (int i = 6; i >= 0; i--)
		printf("%d", ((n / (1 << i)) % 2) ^ sign);
}