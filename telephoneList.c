#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
//연결 리스트를 이용한 전화번호부 등록 프로그램
typedef struct Node {
	char name[MAX];
	char tel[MAX];
	struct Node* link;
} Node;

Node* p = NULL;
Node* prev = NULL;
Node* head = NULL;
Node* next = NULL;

char buffer[MAX];

void menu();
void AllClear();
void Add();
void Search();
void Change();


int main()
{
	menu();

}
void menu()
{
	printf("연결 리스트를 이용한 전화 번호부 메뉴\n");
	printf("------------------------------------\n");
	printf("1. 초기화\n");
	printf("2. 전화 번호 추가\n");
	printf("3. 전화 번호 탐색\n");
	printf("4. 전화 번호 변경\n");
	printf("5. 종료\n");
	printf("------------------------------------\n");
	printf("번호를 입력하세요 : ");
	int num;
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		AllClear();
		break;
	case 2:
		Add();
		break;
	case 3:
		Search();
		break;
	case 4:
		Change();
		break;
	case 5:
		exit(0);
		break;

	}
}
void AllClear()  //전화번호 초기화
{
	p = head;
	while (1)
	{
		if (p == NULL)
		{
			printf("초기화 완료!!\n\n");
			head = NULL;
			break;
		}
		next = p->link;
		free(p);
		p = next;
	}

	menu();
}
void Add() //전화번호 하나 추가
{
	getchar();
	p = (Node*)malloc(sizeof(Node));
	p->link = NULL;
	printf("이름 : ");
	gets_s(buffer, MAX);
	strcpy(p->name, buffer);
	printf("전화번호 : ");
	gets_s(buffer, MAX);
	strcpy(p->tel, buffer);
	printf("추가되었습니다!\n\n");
	if (head == NULL)
		head = p;
	else
		prev->link = p;
	prev = p;
	menu();

}
void Search() // 전화번호 전체 탐색
{

	p = head;
	if (head == NULL)
	{
		printf("정보가 없습니다.\n\n");
	}
	while (1)
	{
		if (p == NULL)
			break;

		printf("이름 : %s\n", p->name);
		printf("전화번호 : %s\n\n", p->tel);
		p = p->link;

	}
	menu();

}
void Change() //전화번호부 전화번호 변경
{
	printf("변경할 전화번호부의 이름을 입력하세요 : ");
	getchar();
	gets_s(buffer, MAX);
	p = head;

	while (1)
	{

		if (p == NULL)
		{
			printf("찾는 이름이 없습니다.\n\n");
			break;
		}
		if (strcmp(buffer, p->name) != 0)
		{
			p = p->link;
		}
		else
		{
			printf("전화번호를 변경하세요 : ");
			gets_s(buffer, MAX);
			strcpy(p->tel, buffer);
			printf("변경 완료!\n\n");
			break;
		}

	}

	menu();
}