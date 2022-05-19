/*
* 2022.05.12.
* 
* 컴퓨터수학1
* 중간 과제, 레포트
*/
#include <stdio.h>
#define SIZE 18

/* 사전순을 기준으로 문자열을 비교하여
* str1 > str2 일 때 1,
* str1 = str2 일 때 0,
* str1 < str2 일 때 -1을
* 반환하는 함수 
*/
int compareString(char* a, char* b) {

	while (*a != '\0' && *b != '\0' && *a == *b) a++, b++;

	if (*a == *b) return 0;	// *a와 *b가 같다는 의미는 둘 다 널 문자('\0')라는 뜻
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

// 삽입 정렬으로 리스트를 오름차순으로 정렬하는 함수
void insertionSort_ASC(char* arr[], int size) {
	for (int i = 1; i < size; i++) {
		int j = 0;
		char* tmp = arr[i];
		while (compareString(arr[j], tmp) < 0) 
			j++;
		for (int k = i - 1; k > j - 1; k--)
			arr[k + 1] = arr[k];
		arr[j] = tmp;
	}
}

// 삽입 정렬으로 리스트를 내림차순으로 정렬하는 함수
void insertionSort_DESC(char* arr[], int size) {
	for (int i = 1; i < size; i++) {
		int j = 0;
		char* tmp = arr[i];
		while (compareString(arr[j], tmp) > 0)
			j++;
		for (int k = i - 1; k > j - 1; k--)
			arr[k + 1] = arr[k];
		arr[j] = tmp;
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
	insertionSort_ASC(dogBreeds, SIZE);
	print_list(dogBreeds, SIZE);

	printf("[Descending order] ：");
	insertionSort_DESC(dogBreeds, SIZE);
	print_list(dogBreeds, SIZE);

	printf("Press \"Enter\" to quit the program...\n");
	getchar();
	return 0;
}