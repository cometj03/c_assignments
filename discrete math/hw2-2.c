/*
 * String Insertion Sort Implementation
 */
#include <stdio.h>
#define SIZE 18

/* 문자열을 사전순을 기준으로 비교하여
 * str1 > str2 일 때 1,
 * str1 == str2 일 때 0,
 * str1 < str2 일 때 -1을
 * 반환하는 함수 */
int compareString(char* a, char* b) {
	
	// char* 는 문자열의 주소를 담고있는 포인터로, 기본적으로 첫 번째 요소를 가리키고 있다.
	// 포인터로 배열을 접근할 때 ++를 사용하여 다음 요소의 주소로 이동할 수 있다.
	// 이 문장은 두 문자열의 문자가 다르거나 마지막에 다다를 때까지 다음 문자로 이동하는 문장이다.
	// 문자열의 마지막 문자는 항상 널 문자('\0')로 끝난다.
	while (*a != '\0' && *b != '\0' && *a == *b) a++, b++;

	// TODO: 설명 추가
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