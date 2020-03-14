#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

void Menu(int cnt);
int* LottoGenerate();
int BonusNumberGenerate(int* random_arr);
int* NumberInput();
void Bonus_result(int* i_input, int bonus);
int LottoResult(int* random_arr, int bonus, int* i_input);
int StartLotto();

static int balance = 0;
static int cnt = 1;

int main()
{

	while (1)
	{
		Menu(cnt);

		printf("돈을 넣으시겠습니까?\n");
		printf("1: yes, 2: no >> ");
		int n;
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("얼마를 넣으시겠습니까? >> ");
			int money;
			scanf("%d", &money);
			balance += money;
			int a = StartLotto();
			if (a == -1)
				return 0;
			break;
		case 2:
			printf("로또를 진행하시겠습니까? 1: yes, 2: no >> ");
			int choice;
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				if (balance >= 1000)
				{
					a = StartLotto();
					if (a == -1)
						return 0;
				}

				else
				{
					printf("돈이 부족합니다. 1회당 1000원입니다.\n");
					printf("1: 돈 충전, 2: 나가기\n>> ");
					int c;
					scanf("%d", &c);
					if (c == 2)
					{
						return 0;
					}
				}
				break;
			case 2:
				return 0;
			}
		}
	}

	return 0;
}


void Menu(int cnt) //메인 메뉴 디자인
{
	printf(".....................................................................................\n");
	printf("................................<<제 %d회 로또>>......................................\n", cnt);
	printf(".....................................................................................\n");
	printf("..**..............************....**************...**************....************....\n");
	printf("..**.............**..........**.........**...............**.........**..........**...\n");
	printf("..**............**............**........**...............**........**............**..\n");
	printf("..**............**............**........**...............**........**............**..\n");
	printf("..**............**............**........**...............**........**............**..\n");
	printf("..**............**............**........**...............**........**............**..\n");
	printf("..**............**............**........**...............**........**............**..\n");
	printf("..**............**............**........**...............**........**............**..\n");
	printf("..**.............**..........**.........**...............**.........**..........**....\n");
	printf("..************....************..........**...............**..........************....\n");
	printf(".....................................................................................\n");
	printf(".....................................................................................\n");

}


int* LottoGenerate() //로또번호 6개 생성
{
	if (balance >= 1000)
	{
		balance -= 1000;
		printf("-------------------------------\n");
		printf("1번에 1000원이 감소됩니다. 남은 잔액은 %d입니다.\n", balance);
		printf("-------------------------------\n");

		srand(rand(time(NULL)));
		int random_arr[6] = { 0, };
		for (int i = 0; i < 6; i++)
		{
			random_arr[i] = rand() % 45 + 1;
		}
		return random_arr;
	}
	else
	{
		printf("돈이 부족합니다. 충전해주세요.\n");
		printf("1: 돈 충전, 2: 나가기\n>> ");
		int c;
		scanf("%d", &c);
		if (c == 1)
		{
			printf("얼마를 넣으시겠습니까? >> ");
			int money;
			scanf("%d", &money);
			balance += money;
			StartLotto();
		}
		else if (c == 2)
			return 0;

	}
}


int BonusNumberGenerate(int* random_arr) //보너스 번호 1개 생성.. 로또번호 6개와 중복 안되도록
{
	srand(rand(time(NULL)));

	int bonus = rand() % 45 + 1;
	for (int i = 0; i < 6; i++)
	{
		if (random_arr[i] == bonus)
		{
			bonus = rand() % 45 + 1;
			i = -1; //중복된 숫자가 있으면 보너스번호 다시 생성하여 중복되는게 있는지 처음부터 다시 검사하기!
		}
	}
	return bonus;
}


int* NumberInput() //내가 뽑은 숫자 6개
{
	int i_input[6] = { 0, };
	printf("1~45 숫자 중 6개를 입력하세요:\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%d번쨰 숫자 >> ", i + 1);
		scanf("%d", &i_input[i]);
		if (i_input[i] > 45)
		{
			printf("45이하의 자연수만 넣으세요.\n");
			i--;
		}
	}
	return i_input;
}


void Bonus_result(int* i_input, int bonus) //2등인지 3등인지 보너스 번호 일치 여부 확인
{
	bool flag = false;
	for (int i = 0; i < 6; i++)
	{
		if (i_input[i] == bonus)
		{
			printf("5개 + 보너스 번호 맞추셨습니다. 2등 당첨! 50000000원이 추가됩니다.\n");
			balance += 50000000;
			flag = false;
			break;
		}
		else
			flag = true;


	}
	if (flag == true)
	{
		printf("5개 맞추셨습니다. 3등 당첨! 1500000원이 추가됩니다.\n");
		balance += 1500000;
	}
}
int LottoResult(int* random_arr, int bonus, int* i_input)
{
	int res_cnt = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (random_arr[i] == i_input[j])
			{
				res_cnt++;
			}
		}
	}
	printf("-------------------------------\n");
	switch (res_cnt)
	{
	case 0:
		printf("0개 맞추셨습니다.\n");
		break;
	case 1:
		printf("1개 맞추셨습니다.\n");
		break;
	case 2:
		printf("2개 맞추셨습니다.\n");
		break;
	case 3:
		printf("3개 맞추셨습니다. 5등 당첨! 5000원이 추가됩니다.\n");
		balance += 5000;
		break;
	case 4:
		printf("4개 맞추셨습니다. 4등 당첨! 50000원이 추가됩니다.\n");
		balance += 50000;
		break;
	case 5:
		Bonus_result(i_input, bonus);
		break;
	case 6:
		printf("6개 맞추셨습니다. 1등 당첨! 대박!!! 1500000000원이 추가됩니다.\n");
		balance += 1500000000;
		break;
	}
	printf("-------------------------------\n");

	printf("또 하시겠습니까? 1회당 1000원이 필요합니다. 1: yes, 2: no >> \n");
	int ch;
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		cnt++;
		Menu(cnt);
		StartLotto();
		break;
	case 2:
		return -1;
	}

}

int StartLotto()
{
	int* random_arr = LottoGenerate();
	int bonus = BonusNumberGenerate(random_arr);
	int* i_input = NumberInput();
	int a = LottoResult(random_arr, bonus, i_input);
	return a;
}