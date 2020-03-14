#include <stdio.h>
#include <string.h>
#include <math.h>
#define People 5
void menu()
{
	printf("\n---------수협은행---------\n");
	printf("1. 계좌 개설\n");
	printf("2. 입금\n");
	printf("3. 출금\n");
	printf("4. 잔액 조회\n");
	printf("5. 모든 계좌 정보 출력\n");
	printf("6. 프로그램 종료\n");
	printf("--------------------------\n");
	printf("메뉴를 선택하세요 >> ");
}
typedef struct
{
	char AccName[20];
	char AccNumber[20];
	int AccBalance;
}Account;

Account Acc[People]; //위의 구조체가 5개 있음. 즉 계좌계설이 5명까지 가능!
int cnt = 0;

void MakeAccount()
{
	if (cnt < People)
	{
		char Makename[20];
		char MakeaccountNumber[20];
		int MakeBalance;

		printf("이름 입력: ");
		scanf("%s", Makename);
		printf("계좌번호 입력: ");
		scanf("%s", MakeaccountNumber);
		for (int i = 0; i < People; i++)
		{
			if (strcmp(Acc[i].AccNumber, MakeaccountNumber) == 0)
			{
				printf("계좌번호 중복! 계좌번호 다시 입력해주세요!\n");
				return;
			}
			else
			{
				strcpy(Acc[cnt].AccName, Makename);
				strcpy(Acc[cnt].AccNumber, MakeaccountNumber);

				cnt++;
				printf("계좌 생성 완료!! 감사합니다.");
				return;
			}
		}


	}
	else
		printf("계좌 생성 초과! 그만 만드세요!\n");

}

void Input()
{
	printf("----------------------입금!!!-----------------------\n");
	char accountNumber[20];
	int balance;
	printf("계좌번호를 입력하세요: ");
	scanf("%s", accountNumber);
	for (int cnt = 0; cnt < People; cnt++)
	{
		if (Acc[cnt].AccNumber == accountNumber)
		{
			printf("입금할 금액을 입력하세요 : ");
			scanf("%d", &balance);
			Acc[cnt].AccBalance += balance;
			printf("-----------------------------\n");
			printf("%d원을 입금하였습니다. \n%s님의 총 잔액은 %d원 입니다.\n", balance, Acc[cnt].AccName, Acc[cnt].AccBalance);
			printf("-----------------------------\n\n");
			return;
		}
	}
	printf("조회된 계좌번호가 없습니다.\n");
}

void Output()
{
	printf("----------------------출금!!!-----------------------\n");
	char accountNumber[20];
	int balance;
	printf("계좌번호를 입력하세요: ");
	scanf("%s", accountNumber);
	for (int cnt = 0; cnt < People; cnt++)
	{
		if (Acc[cnt].AccNumber == accountNumber)
		{
			printf("출금할 금액을 입력하세요 : ");
			scanf("%d", &balance);
			printf("-----------------------------\n");
			if (balance <= Acc[cnt].AccBalance)
			{
				Acc[cnt].AccBalance -= balance;
				printf("-----------------------------\n\n");
				printf("%d원을 인출하였습니다.\n%s님의 총 잔액은 %d원 입니다.\n", balance, Acc[cnt].AccName, Acc[cnt].AccBalance);
				printf("-----------------------------\n\n");
				return;
			}
			else
			{
				int num = 0;
				printf("잔액이 부족합니다 ㅠㅠ\n");
				printf("다시 입력하시려면 1번을 입력하시고, 메뉴로 돌아가시려면 2번을 누르세요\n>> ");
				scanf("%d", &num);
				if (num == 1)
					Output();
				else if (num == 2)
					return;
				else
					printf("잘못 누르셨습니다.\n");
			}
			printf("-----------------------------\n");
			return;
		}
	}
	printf("조회된 계좌번호가 없습니다.\n");
}
void Balance()
{
	printf("----------------------잔액조회!!!-----------------------\n");
	char accountNumber[20];
	printf("계좌번호를 입력하세요: ");
	scanf("%s", accountNumber);
	for (int cnt = 0; cnt < People; cnt++)
	{
		if (Acc[cnt].AccNumber == accountNumber)
		{
			printf("-----------------------------\n");
			printf("%s님의 현재 총 잔액은 %d원 입니다.\n", Acc[cnt].AccName, Acc[cnt].AccBalance);
			printf("-----------------------------\n\n");
			return;
		}

	}
	printf("조회된 계좌번호가 없습니다.\n");
}

void PrintAllAccount()
{
	printf("-----------------\n");
	for (int i = 0; i < People; i++)
	{
		printf("%d번 손님 정보 출력\n", i + 1);
		printf("이름 : %s\n계좌번호 : %s\n잔액 : %d\n", Acc[i].AccName, Acc[i].AccNumber, Acc[i].AccBalance);
		printf("-----------------\n");
	}
}

void Exit()
{
	printf("은행 정보 프로그램을 종료합니다.\n");
	exit();
}

int main()
{
	while (1)
	{
		menu();
		int menu_number;
		scanf("%d", &menu_number);

		switch (menu_number)
		{
		case 1:
			MakeAccount();
			break;
		case 2:
			Input();
			break;
		case 3:
			Output();
			break;
		case 4:
			Balance();
			break;
		case 5:
			PrintAllAccount();
			break;
		case 6:
			Exit();
			break;
		}
	}
}