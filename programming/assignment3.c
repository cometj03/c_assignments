#include <stdio.h>
#include <string.h>
#define SIZE 20

char name[][20] = {
    "Sophia",
    "Olivia",
    "Riley",
    "Emma",
    "Ava",
    "Isabella",
    "Aria",
    "Amelia",
    "Mia",
    "Liam",
    "Noah",
    "Jackson",
    "Aiden",
    "Elijah",
    "Grayson",
    "Lucas",
    "Oliver",
    "Caden",
    "Mateo",
    "David"
};

int id[] = {
    20220001,
    20220010,
    20220002,
    20220015,
    20220009,
    20220014,
    20220020,
    20220005,
    20220016,
    20220008,
    20220012,
    20220004,
    20220018,
    20220017,
    20220003,
    20220013,
    20220007,
    20220019,
    20220011,
    20220006
};

int score[] = {
  98, 96, 88, 77, 82, 93, 84, 79, 90, 80, 89, 99, 78, 83, 92, 71, 72, 68, 96, 76
};

void name_ASC();
void id_ASC();
void score_DESC();
void search_name();
void swap(int, int);
void print_all();

int main(void) {
    int num;
    while (1) {
        printf("1. 이름 오름차순 출력\t2. 학번 오름차순 출력\n3. 점수 내림차순 출력\t4. 이름 검색\n5. 종료\n\n");
        printf("번호를 선택하세요 : ");
        scanf("%d", &num);
        if (num >= 5 || num <= 0) break;
        switch (num) {
        case 1: name_ASC(); break;
        case 2: id_ASC(); break;
        case 3: score_DESC(); break;
        case 4: search_name(); break;
        }
    }
    return 0;
}

void name_ASC() {
    for (int i = 1; i < SIZE; i++)
        for (int j = 0; j < SIZE - i; j++)
            if (strcmp(name[j], name[j + 1]) > 0)
                swap(j, j + 1);
    print_all();
}

void id_ASC() {
    for (int i = 1; i < SIZE; i++)
        for (int j = 0; j < SIZE - i; j++)
            if (id[j] > id[j + 1])
                swap(j, j + 1);
    print_all();
}

void score_DESC() {
    for (int i = 1; i < SIZE; i++)
        for (int j = 0; j < SIZE - i; j++)
            if (score[j] < score[j + 1])
                swap(j, j + 1);
    print_all();
}

void search_name() {
    int i;
    char search[20];
    printf("이름을 입력하세요: ");
    scanf("%s", search);
    for (i = 0; i < SIZE; i++)
        if (strcmp(search, name[i]) == 0)
            break;
    if (i >= SIZE) {
        printf("다시 입력하세요.\n");
        return;
    }
    printf("\n\n%-10s%-10s%s\n", "이름", "학번", "점수");
    printf("%-10s%-10d%-3d\n", name[i], id[i], score[i]);
}

void swap(int a, int b) {
    int t = id[a];
    id[a] = id[b];
    id[b] = t;

    char tname[20];
    strcpy(tname, name[a]);
    strcpy(name[a], name[b]);
    strcpy(name[b], tname);

    int tscore = score[a];
    score[a] = score[b];
    score[b] = tscore;
}

void print_all() {
    printf("\n%-10s%-10s%s\n", "이름", "학번", "점수");
    for (int i = 0; i < SIZE; i++)
        printf("%-10s%-10d%-3d\n", name[i], id[i], score[i]);
    printf("\n\n");
}