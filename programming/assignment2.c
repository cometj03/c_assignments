/*
8비트 이진수 변환기, 계산기 구현
*/
#include <stdio.h>
void binary1() {

}

void binary2() {

}

void binary3() {

}

int main(void) {
	int n;
	printf("1. 이진수 변환기\t2. 이진수 덧셈기\t3. 이진수 뺄셈기\n");
	printf("번호를 선택하세요 : ");
	scanf("%d", &n);
	switch (n) {
	case 1: binary1(); break;
	case 2: binary2(); break;
	case 3: binary3(); break;
	default: printf("유효한 숫자를 입력하세요.\n"); break;
	}
	return 0;
}