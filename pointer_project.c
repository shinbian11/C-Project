#include <stdio.h>
#include <time.h>
//물고기 6마리
//사막에 살고있는데, 물이 다 증발하기 전에 부지런히
//어항에 물을 줘서 물고기를 살려주세요.
//열심히 키운 물고기는 먹는다 ㅎㅎ
int level;
int arrayFish[6];
int* cursor;

void initData();
void printfFishes();
void decreaseWater(long elapsedTime);
//int checkFishAlive();
 
int main()
{
	long startTime = 0;
	long totalElapsedTime = 0;
	long prevElapsedTime = 0;

	int num;//몇번 어항에 물을 줄것인지, 사용자 입력
	initData();


	cursor = arrayFish;

	startTime = clock(); //현재 시간을 1000분의 1초 단위로 반환
	while (1)
	{
		printfFishes();
		printf("\n\n몇 번 어항에 물을 주시겠어요? ");
		scanf("%d", &num);

		if (num < 1 || num >6)
		{
			printf("\n입력값이 잘못되었습니다.\n");
			continue;
		}
		//총 경과 시간
		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총 경과 시간 : %ld 초\n", totalElapsedTime);

		//직전 물 준 시간(마지막으로 물 준 시간) 이후로 흐른 시간
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간 : %ld 초\n", prevElapsedTime);

		//어항의 물을 감소
		decreaseWater(prevElapsedTime);

		//사용자가 입력한 어항에 물을 준다.
		//1. 어항의 물이 0이면? : 물을 줄 필요가 없다.
		if (cursor[num - 1] <= 0)
			printf("%3d번 물고기는 죽었습니다. 물 줄 필요 없습니다.\n", num);
		//2. 어항의 물이 0이 아닌경우? : 물을 준다! 100을 넘지 않는지 체크
		else if (cursor[num - 1] <= 99)
		{
			//물을 준다
			printf("%3d번 물고기에 물을 줍니다.\n",num);
			cursor[num - 1] += 1;
		}

		//레벨업을 할건지 확인(20초마다 레벨업하기)
		if (totalElapsedTime / 20 > level - 1) //그 level에서 20초 이상 버티면
		{
			level++;
			printf("축! 레벨업! 기존 %d레벨에서 %d레벨로 업그레이드! \n", level - 1, level);
			//최종 레벨 :5
			if (level == 5)
			{
				printf("축하! 최고 레벨 달성! 게임 종료!\n");
				exit(0);
			}
		}

		//모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0)
		{
			//모든 물고기 죽음
			printf("모든 물고기 죽음 ㅠㅠ\n");
			exit(0);
		}
		else
		{
			printf("물고기 아직 살아있음!\n");
		}
		prevElapsedTime = totalElapsedTime;

		
	}


	return 0;
}

void initData()
{
	level = 1; //레벨 1~5
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; //어항의 물 높이 0~100
	}
}
void printfFishes()
{
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", arrayFish[i]);
	}
}
void decreaseWater(long elapsedTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 3 * (int)elapsedTime);//3 : 난이도 조절을 위한 값
		if (arrayFish[i] < 0)
			arrayFish[i] = 0;
		
	}
}
int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
			return 1; //한마리라도 살아있을때 1반환
	}
	return 0; //다 죽었을때
}