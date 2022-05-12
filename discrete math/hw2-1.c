/*
* 2022.05.12.
* 
* 컴퓨터수학1
* 중간 과제, 레포트
* String Bubble Sort Implementation
*/
#include <stdio.h>
#define SIZE 18

/* 문자열을 사전순을 기준으로 비교하여
 * str1 > str2 일 때 1,
 * str1 == str2 일 때 0,
 * str1 < str2 일 때 -1을
 * 반환하는 함수 */
int compareString(char* a, char* b) {

	while (*a != '\0' && *b != '\0' && *a == *b) a++, b++;

	if (*a == *b) return 0;
	if (*b == '\0' || *a > *b) return 1;
	if (*a == '\0' || *a < *b) return -1;
	return 0;
}

// 리스트 전체를 출력하는 함수
void print_list(char* arr[], int size) {
	for (int i = 0; i < size; i++)
		printf("%s | ", arr[i]);
	printf("\n");
}

// 버블 소팅으로 리스트를 오름차순으로 정렬하는 함수
void bubbleSort_ASC(char* arr[], int size) {

	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {

			// arr[j+1]가 arr[j]보다 사전 순으로 앞서 있을 때
			if (compareString(arr[j], arr[j + 1]) > 0) { 
				// arr[j]와 arr[j+1] 스왑
				char* tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

// 버블 소팅으로 리스트를 내림차순으로 정렬하는 함수
void bubbleSort_DESC(char* arr[], int size) {

	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size - i; j++) {

			// arr[j]가 arr[j+1]보다 사전 순으로 앞서 있을 때
			if (compareString(arr[j], arr[j + 1]) < 0) { 
				// arr[j]와 arr[j+1] 스왑
				char* tmp;
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

char* dogBreeds[] = {
	"Yorkshire Terrier", "French Bulldog", "Golden Retriever", "Dachshund",
	"Samoyed", "Cairn Terrier", "Shiba Inu", "Pomeranian",
	"Pomsky", "Australian Shepherd", "Bichon Frise", "Dalmatian", "American Eskimo",
	"Chiweenie", "Brussels Griffon", "Papillon", "Chihuahua", "Toy Poodle"
};

int main(void) 
{
	printf("[Input String] : ");
	print_list(dogBreeds, SIZE);
	
	printf("[Ascending order] ：");
	bubbleSort_ASC(dogBreeds, SIZE);
	print_list(dogBreeds, SIZE);

	printf("[Descending order] ：");
	bubbleSort_DESC(dogBreeds, SIZE);
	print_list(dogBreeds, SIZE);

	printf("Press \"Enter\" to quit the program...\n");
	getchar();
	return 0;
}