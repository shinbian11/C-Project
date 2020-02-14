#include <stdio.h>
#include <time.h>
	//10마리의 서로 다른 동물(카드 2장씩)
	//사용자로부터 입력 2개를 받아 -> 같은 동물이면 카드 뒤집기
	//모든 동물 짝을 찾기->게임 종료
	//총 실패 횟수 알려주기
int arrayAnimal[4][5]; //카드 표시(총 20장)
int checkAnimal[4][5] = { 0, }; //뒤집혔는지의 여부 확인

char* strAnimal[10];
void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int randPos);
int conv_pos_y(int randPos);
void printAnimals();
void printQuestion();
int foundAllAnimals();

int main()
{
	
	srand(time(NULL));

	initAnimalArray();
	initAnimalName();
	shuffleAnimal();


	int failCount = 0; //실패 횟수

	while (1)
	{
		int select1 = 0; //선택 수 1
		int select2 = 0; //선택 수 2

		printAnimals(); //동물 위치 출력
		printQuestion(); //문제 출력(카드 지도)
		printf("뒤집을 카드를 2개 고르세요...");
		scanf("%d %d", &select1, &select2);
		if (select1 == select2) //select1 과 select2가 같으면 좌표가 1개밖에 안 나오므로 잘못된 입력!
			continue;
		
		//좌표를 해당하는 카드를 뒤집어 보고 같은지 안같은지 확인


		//입력한 수(0~19)를 좌표형식(x,y)으로 변환!
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int SecondSelect_x = conv_pos_x(select2);
		int SecondSelect_y = conv_pos_y(select2);

		//if(카드가 뒤집히지 않았는지 && 두 동물이 같은지) => 같은 동물인 경우
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0 &&
			checkAnimal[SecondSelect_x][SecondSelect_y] == 0)
			&&
			(arrayAnimal[firstSelect_x][firstSelect_y]
				== arrayAnimal[SecondSelect_x][SecondSelect_y])
			)
		{
			printf("\n\n빙고!!!!! %s 발견!\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1; //1로 바꿔서 뒤집기!
			checkAnimal[SecondSelect_x][SecondSelect_y] = 1; //1로 바꿔서 뒤집기!
		}
		//else => 다른 동물인 경우
		else
		{
			printf("\n\n땡!! (틀렸거나, 이미 뒤집힌 카드입니다).\n\n");
			printf("당신이 선택한 동물1 : %d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("당신이 선택한 동물2 : %d : %s\n", select2, strAnimal[arrayAnimal[SecondSelect_x][SecondSelect_y]]);
			printf("\n\n");
			failCount++;
		}

		//모든 동물을 찾았는지 여부.. 1: 참 , 0: 거짓
		if (foundAllAnimals() == 1) //모든 동물을 찾았다면
		{
			printf("====================================\n");
			printf("모든 동물을 찾았습니다! 끝!\n");
			printf("%d번 실수하셨습니다\n\n\n", failCount);
			break;
		}
	}

}

void initAnimalArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
		}
	}
}
void initAnimalName()
{
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양이";
	strAnimal[4] = "돼지";
	strAnimal[5] = "코끼리";
	strAnimal[6] = "기린";
	strAnimal[7] = "낙타";
	strAnimal[8] = "타조";
	strAnimal[9] = "호랑이";
}

void shuffleAnimal()
{
	/*
	예를 들어 getEmptyPosition()를 호출했더니 19가 나왔다.그 19는 좌표로 환산하면 (3,4)인데
	그 좌표가 만약 빈공간이라면(-1이 저장되어있다면) 19를 반환하고, 그 반환한 19를
	shuffleAnimal 함수에서 다시 x,y좌표로 변환을 한다. 그리고 그 좌표에(빈공간에) 1번쨰 
	동물인 원숭이를 배정한다. 즉 다시말해 (3,4)에는 "원숭이"가 들어가게되는 것이다. j가 0~1인 이유는,
	다른 좌표에도 원숭이를 하나 더 넣어야 하므로, j를 두번 실행하게 한것이다!
	*/
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPosition(); //빈 공간을 찾은다음
			int x = conv_pos_x(pos); //그 빈공간의 x좌표
			int y = conv_pos_y(pos); //y좌표에

			arrayAnimal[x][y] = i; //동물들을 순서대로 배정한다.
			
		}
	}
}

int getEmptyPosition()
{
	//빈공간 찾기
	while (1)
	{
		int randPos = rand() % 20;
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);
		if (arrayAnimal[x][y] == -1) //처음 초기화했을때 -1이니까 빈공간이라는 뜻!
			return randPos;
	}
}

int conv_pos_x(int randPos)
{
	//19->[3,4]에서 3을 반환해야됨!
	return randPos / 5;
	
}
int conv_pos_y(int randPos)
{
	//19->[3,4]에서 4를 반환해야됨!
	return randPos % 5;
}

void printAnimals()
{
	printf("\n------------컨닝할수있는 답안!!ㅋㅋ------------\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]); //arrayAnimal[i][j]에는 그 동물에 해당되는 숫자가 들어있다.
			//즉 그 동물을 출력하려면 그 숫자를 출력하는것이 아니라 strAnimal[그 숫자]를 해야하는것이다.
		}
		printf("\n");
	}
	printf("\n-------------------------------------------\n");
}

void printQuestion()
{
	printf("\n\n(문제)\n");
	int seq = 0;

	//seq 
	// 0  1  2  3  4
	//하마 6  7  8  9
	// 10 11 12 하마 14
	// 15 16 17 18 19

	//checkAnimal
	//0 0 0 0 0
	//1 0 0 0 0
	//0 0 0 1 0
	//0 0 0 0 0

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			
			
			if (checkAnimal[i][j] != 0)
			{
				//카드를 뒤집어서 정답을 맞혔으면 동물 이름 출력
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			else
			{
				//못 맞혔으면 뒷면-> 위치를 나타내는 숫자 출력
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

int foundAllAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0)
				return 0;
		}
	}
	return 1; // 다 1이면(다 뒤집혔으면) 1을 반환!
}
