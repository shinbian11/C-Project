#include <stdio.h>
void login();
void login_else();
void MainMenu();
void ShowVideoList();
void UpdateVideo();
void DeleteVideo();
void BuyVideo();
void MyRoom();

char* real_id = "video";
char* real_password = "kjh";

typedef struct {
	char name[100];
	char detail[100];
	int price;
} DocumentVideo; // 다큐
typedef struct {
	char name[100];
	char detail[100];
	int price;
} DramaVideo; // 드라마
typedef struct {
	char name[100];
	char detail[100];
	int price;
} MovieVideo; // 영화
typedef struct {
	char name[100];
	char detail[100];
	int price;
} MyList;
DocumentVideo* docu[10];
DramaVideo* drama[10];
MovieVideo* movie[10];
MyList* mylist[10];

int login_cnt = 5; //login 기회는 5번... 5번 안에 로그인 실패하면 종료

int docu_update_cnt = 3;
int drama_update_cnt = 3;
int movie_update_cnt = 3;
int balance = 0;
int coupon = 0;
int main()
{

	login();

}


void MainMenu()
{

	int mainMenu_choice;
	printf("\n\n===========NetFlix===========\n\n");
	printf("1. 비디오 목록 보기(List)\n");
	printf("2. 비디오 등록 하기(Update)\n");
	printf("3. 최근에 등록한 비디오 삭제 하기(Delete)\n");
	printf("4. 비디오 구입 하기(Buy)\n");
	printf("5. 마이룸\n");
	printf("6. 나가기\n\n");
	printf("원하는 메뉴의 번호를 입력하세요 >> ");
	scanf("%d", &mainMenu_choice);
	if (mainMenu_choice == 1)
	{
		ShowVideoList();
	}
	else if (mainMenu_choice == 2)
	{
		UpdateVideo();
	}
	else if (mainMenu_choice == 3)
	{
		DeleteVideo();
	}
	else if (mainMenu_choice == 4)
	{
		BuyVideo();
	}
	else if (mainMenu_choice == 5)
	{
		MyRoom();
	}
	else if (mainMenu_choice == 6)
	{
		printf("\n\n프로그램 종료합니다!\n");
		exit(0);
	}
}


void login() //로그인 -> 일치/불일치 판별 후 메인 메뉴로 보내는 함수
{
	

	char* id_space;
	char id[11];
	char c;
	char password[11];
	printf("\n=====Welcome to NetFlix!!=====\n");
	printf("Please login!\n");
	printf("id (10글자 이내로) > "); // 아이디 입력
	scanf("%s", &id);
	id_space = &id;
	//printf("%s\n", id_space);
	printf("password (10글자 이내로) > "); //비번 입력
	int i = 0;
	while (1)
	{
		c = getch();
		if (c == 13) //enter키 입력할때까지 비번 입력!
		{
			password[i] = '\0';
			break;
		}
		else
		{
			printf("*");
			password[i] = c;
		}
		i++;

	}

	if (strcmp(real_id, id_space) == 0 && strcmp(real_password, password) == 0)// 비번 일치
	{
		int choice;
		printf("\n\n=====어서오세요! Welcome!=====\n");
		printf("메인 메뉴로 가시겠습니까? (1 : Yes, 2: No) > ");
		scanf("%d", &choice);
		if (choice == 1)
		{
			MainMenu();
		}
		else if (choice == 2)
		{
			printf("\n>>>프로그램 종료합니다..\n");
			exit(0);
		}
	}
	else //아이디 혹은 비번 불일치 시
	{
		--login_cnt;
		login_else();
	}
	
}

void login_else() //아이디 혹은 비번 불일치 시에 실행될 함수
{
	printf("\n\n=======id 또는 pw가 틀립니다.=======\n");
	printf("\n>> 기회는 %d번 남았습니다.\n\n", login_cnt);
	if (login_cnt > 0)
	{
		printf("1. id 찾기\n");
		printf("2. password 찾기\n");
		printf("3. login 창으로 돌아가기\n");
		printf(">> ");
		while (1)
		{
			int choice;
			scanf("%d", &choice);
			if (choice == 1)
			{
				printf("\n>>> id는 %s입니다.\n", real_id);
				login_else();
			}
			else if (choice == 2)
			{
				printf("\n>>> pw는 %s입니다.\n", real_password);
				login_else();
			}
			else if (choice == 3)
			{
				login();
				break;
			}
			else
			{
				printf(">>> 잘못 누르셨습니다\n\n");
				login_else();
			}
		}
	}
	else
	{
		printf("\n\n>> 로그인 가능 횟수를 초과하셨습니다. 프로그램 종료합니다!\n");
		exit(0);
	}
}
void Listinit() //맨처음 리스트 초기화(3개씩)
{
	//일단 다큐멘터리 3개 초기화
	for (int i = 0; i < 3; i++)
	{
		docu[i] = (DocumentVideo*)malloc(sizeof(DocumentVideo));
		memset(docu[i], 0x00, sizeof(DocumentVideo)); //공간 할당한후 초기화
	}
	
	strcpy(docu[0]->name, "Man vs Wild");
	strcpy(docu[0]->detail, "베어그릴스가 야생에서 살아가는 비디오!");
	docu[0]->price = 100;
	strcpy(docu[1]->name, "지구의 모든 것");
	strcpy(docu[1]->detail, "지구의 모든 것을 담고 있는 비디오!");
	docu[1]->price = 200;
	strcpy(docu[2]->name, "About Bill Gates");
	strcpy(docu[2]->detail, "빌게이츠의 모든 것을 담고 있는 비디오!");
	docu[2]->price = 300;

	//일단 드라마 3개 초기화
	for (int i = 0; i < 3; i++)
	{
		drama[i] = (DramaVideo*)malloc(sizeof(DramaVideo));
		memset(drama[i], 0x00, sizeof(DramaVideo)); //공간 할당한후 초기화
	}

	strcpy(drama[0]->name, "평생 내 사랑");
	strcpy(drama[0]->detail, "눈물 없이 볼수 없는 사랑 드라마!");
	drama[0]->price = 150;
	strcpy(drama[1]->name, "내 딸 서윤이");
	strcpy(drama[1]->detail, "잃어버린 딸을 찾기 위한 감동 실화!");
	drama[1]->price = 250;
	strcpy(drama[2]->name, "마지막 잎새");
	strcpy(drama[2]->detail, "웹툰 '마지막 잎새'가 드라마로 돌아왔다!");
	drama[2]->price = 350;

	//일단 영화 3개 초기화
	for (int i = 0; i < 3; i++)
	{
		movie[i] = (MovieVideo*)malloc(sizeof(MovieVideo));
		memset(movie[i], 0x00, sizeof(MovieVideo)); //공간 할당한후 초기화
	}

	strcpy(movie[0]->name, "좋은 녀석들");
	strcpy(movie[0]->detail, "진정한 친구는 무엇인지 담고 있는 영화!");
	movie[0]->price = 500;
	strcpy(movie[1]->name, "범죄자들");
	strcpy(movie[1]->detail, "범죄자들의 씁쓸한 우정을 담고 있는 영화!");
	movie[1]->price = 600;
	strcpy(movie[2]->name, "2018");
	strcpy(movie[2]->detail, "세계 종말을 다루고 있는 재난 영화");
	movie[2]->price = 700;

	
}
void ShowVideoList() //비디오 목록 보여주기
{
	Listinit();
	printf("\n\n ========= 다큐 ========= \n\n");
	for (int i = 0; i < docu_update_cnt;i++)
		printf("%d번\n%s\n%s\n%d원\n\n", i + 1, docu[i]->name, docu[i]->detail, docu[i]->price);
	printf("\n\n ========= 드라마 ========= \n\n");
	for (int i = 0; i < drama_update_cnt; i++)
		printf("%d번\n%s\n%s\n%d원\n\n", i + 1, drama[i]->name, drama[i]->detail, drama[i]->price);
	printf("\n\n ========= 영화 ========= \n\n");
	for (int i = 0; i < movie_update_cnt; i++)
		printf("%d번\n%s\n%s\n%d원\n\n", i + 1, movie[i]->name, movie[i]->detail, movie[i]->price);
	
	printf("엔터 키를 입력하면 메인 메뉴로 돌아갑니다.\n엔터키 이외의 키를 누르면 종료됩니다. >> ");
	int enter;
	enter = getch();
	if (enter == 13)
		MainMenu();
	else {
		printf("\n\n프로그램 종료!!\nBye~!\n\n");
		exit(0);
	}

}

void UpdateVideo() //비디오 등록
{

	printf("\n\n어떤 장르의 비디오를 등록하시겠습니까?\n\n");
	printf("1. 다큐 2. 드라마 3. 영화  >> ");
	int choice_update;
	
	char name[100];
	char detail[100];
	int price;
	scanf("%d", &choice_update);
	if (choice_update == 1)
	{
		if (docu_update_cnt < 10)
		{
			docu[docu_update_cnt] = (DocumentVideo*)malloc(sizeof(DocumentVideo));
			memset(docu[docu_update_cnt], 0x00, sizeof(DocumentVideo)); //공간 할당한후 초기화

			getchar();
			printf("제목 입력 : ");
			fgets(name, 100, stdin);
			name[strlen(name)-1] = '\0';
			strcpy(docu[docu_update_cnt]->name, name);//윗줄에서 마지막에 입력한 개행문자는 삭제하기!
			
			printf("설명 입력 : ");
			fgets(detail, 100, stdin);
			detail[strlen(detail) - 1] = '\0'; //윗줄에서 마지막에 입력한 개행문자는 삭제하기!
			strcpy(docu[docu_update_cnt]->detail, detail);

			printf("가격 입력 : ");	
			scanf("%d", &price);
			docu[docu_update_cnt]->price = price;

			docu_update_cnt++;

			printf("\n\n다큐멘터리 등록 완료!!\n\n");
			MainMenu();
		}
		else
		{
			printf("등록할 수 있는 다큐멘터리의 수가 초과되었습니다.");
			
			MainMenu();
		}
	}
	else if (choice_update == 2)
	{
		if (drama_update_cnt < 10)
		{
			drama[drama_update_cnt] = (DramaVideo*)malloc(sizeof(DramaVideo));
			memset(drama[drama_update_cnt], 0x00, sizeof(DramaVideo)); //공간 할당한후 초기화

			getchar();
			printf("제목 입력 : ");
			fgets(name, 100, stdin);
			name[strlen(name) - 1] = '\0';
			strcpy(drama[drama_update_cnt]->name, name);

			printf("설명 입력 : ");
			fgets(detail, 100, stdin);
			detail[strlen(detail) - 1] = '\0';
			strcpy(drama[drama_update_cnt]->detail, detail);

			printf("가격 입력 : ");
			scanf("%d", &price);
			drama[drama_update_cnt]->price = price;

			drama_update_cnt++;
			printf("\n\n드라마 등록 완료!!\n\n");
			MainMenu();
		}
		else
		{
			printf("등록할 수 있는 드라마의 수가 초과되었습니다.");
			
			MainMenu();
		}
	}
	else if (choice_update == 3)
	{
		if (movie_update_cnt < 10)
		{
			movie[movie_update_cnt] = (MovieVideo*)malloc(sizeof(MovieVideo));
			memset(movie[movie_update_cnt], 0x00, sizeof(MovieVideo)); //공간 할당한후 초기화

			getchar();
			printf("제목 입력 : ");
			fgets(name, 100, stdin);
			name[strlen(name) - 1] = '\0';
			strcpy(movie[movie_update_cnt]->name, name);

			printf("설명 입력 : ");
			fgets(detail, 100, stdin);
			detail[strlen(detail) - 1] = '\0';
			strcpy(movie[movie_update_cnt]->detail, detail);

			printf("가격 입력 : ");
			scanf("%d", &price);
			movie[movie_update_cnt]->price = price;

			movie_update_cnt++;

			printf("\n\n영화 등록 완료!!\n\n");
			MainMenu();
		}
		else
		{
			printf("등록할 수 있는 영화의 수가 초과되었습니다.");
			
			MainMenu();
		}
	}
}

void DeleteVideo() //최근 비디오 삭제하기
{
	printf("\n\n어떤 장르의 최근 비디오를 삭제하시겠습니까?\n\n");
	printf("1. 다큐 2. 드라마 3. 영화  >> ");
	int choice_delete;
	scanf("%d", &choice_delete);

	if (choice_delete == 1)
	{
		if (docu_update_cnt > 0)
		{
			docu_update_cnt--;
			printf("다큐멘터리 최근 비디오를 삭제합니다.\n");
			printf("최근 비디오 제목 : %s", docu[docu_update_cnt]->name);
			free(docu[docu_update_cnt]);
		}
		else
		{
			printf("지울 수 있는 비디오가 없습니다.\n\n");
		}


		MainMenu();
	}
	else if (choice_delete == 2)
	{
		if (drama_update_cnt > 0)
		{
			drama_update_cnt--;
			printf("드라마 최근 비디오를 삭제합니다.\n");
			printf("최근 비디오 제목 : %s", drama[drama_update_cnt]->name);
			free(drama[drama_update_cnt]);
		}
		else
		{
			printf("지울 수 있는 비디오가 없습니다.\n\n");
		}


		MainMenu();
	}
	else if (choice_delete == 3)
	{
		if (movie_update_cnt > 0)
		{
			movie_update_cnt--;
			printf("영화 최근 비디오를 삭제합니다.\n");
			printf("최근 비디오 제목 : %s", movie[movie_update_cnt]->name);
			free(movie[movie_update_cnt]);
		}
		else
		{
			printf("지울 수 있는 비디오가 없습니다.\n\n");
		}


		MainMenu();
	}
}
static int buycnt = 0;
char* myList[10];
void BuyVideo()//비디오 구매
{


	//현재까지 비디오 리스트 보여주기
	printf("\n\n ========= 다큐 ========= \n\n");
	for (int i = 0; i < docu_update_cnt; i++)
		printf("%d번\n%s\n%s\n%d원\n\n", i + 1, docu[i]->name, docu[i]->detail, docu[i]->price);
	printf("\n\n ========= 드라마 ========= \n\n");
	for (int i = 0; i < drama_update_cnt; i++)
		printf("%d번\n%s\n%s\n%d원\n\n", i + 1, drama[i]->name, drama[i]->detail, drama[i]->price);
	printf("\n\n ========= 영화 ========= \n\n");
	for (int i = 0; i < movie_update_cnt; i++)
		printf("%d번\n%s\n%s\n%d원\n\n", i + 1, movie[i]->name, movie[i]->detail, movie[i]->price);

	printf("어떤 장르의 비디오를 구매하시겠습니까?\n");
	printf("1. 다큐   2. 드라마   3. 영화  >> ");
	int genre;
	scanf("%d", &genre);
	if (genre == 1) //다큐멘터리 구입
	{
		printf("\n\n ========= 다큐 ========= \n\n");
		for (int i = 0; i < docu_update_cnt; i++)
			printf("%d번\n%s\n%s\n%d원\n\n", i + 1, docu[i]->name, docu[i]->detail, docu[i]->price);

		printf("다큐멘터리 중에 어떤 비디오를 구매하시겠습니까? >> ");
		int buy_docu;
		scanf("%d", &buy_docu);
		if (docu[buy_docu - 1]->price > balance)
		{
			printf("돈이 부족합니다...ㅠㅠ\n마이룸으로 가서 돈을 충전하세요!\n\n");
			MyRoom();
		}
		else //잔액이 충분하다면
		{		
			balance -= docu[buy_docu - 1]->price;
			printf("%d번 : %s를 구매하셨습니다.\n", buy_docu, docu[buy_docu - 1]->name);
			printf("\n남은 잔액은 %d원입니다.\n\n", balance);

			//구매했으니 내 리스트에 넣어야겠지??
			mylist[buycnt] = (MyList*)malloc(sizeof(MyList));
			strcpy(mylist[buycnt]->name, docu[buy_docu - 1]->name);
			strcpy(mylist[buycnt]->detail, docu[buy_docu - 1]->detail);
			mylist[buycnt]->price = docu[buy_docu - 1]->price;
			buycnt++; //넣고나서 index 하나 증가!

			printf("또 구매하시려면 1번, 메인 메뉴로 나가시려면 2번을 눌러주세요 : >> ");
			int choi;
			scanf("%d", &choi);
			if (choi == 1)
				BuyVideo();
			else if (choi == 2)
				MainMenu();
			else
			{
				printf("잘못 눌렀습니다. 프로그램 종료합니다! \n");
				exit(0);
			}
		}
	}
	else if (genre == 2)//드라마 구입
	{
		printf("\n\n ========= 드라마 ========= \n\n");
		for (int i = 0; i < drama_update_cnt; i++)
			printf("%d번\n%s\n%s\n%d원\n\n", i + 1, drama[i]->name, drama[i]->detail, drama[i]->price);
		printf("드라마 중에 어떤 비디오를 구매하시겠습니까? >> ");
		int buy_drama;
		scanf("%d", &buy_drama);
		if (drama[buy_drama - 1]->price > balance)
		{
			printf("돈이 부족합니다...ㅠㅠ\n마이룸으로 가서 돈을 충전하세요!\n\n");
			MyRoom();
		}
		else //잔액이 충분하다면
		{
			balance -= drama[buy_drama - 1]->price;
			printf("%d번 : %s를 구매하셨습니다.\n", buy_drama, drama[buy_drama - 1]->name);
			printf("\n남은 잔액은 %d원입니다.\n\n", balance);

			//구매했으니 내 리스트에 넣어야겠지??
			mylist[buycnt] = (MyList*)malloc(sizeof(MyList));
			strcpy(mylist[buycnt]->name, drama[buy_drama - 1]->name);
			strcpy(mylist[buycnt]->detail, drama[buy_drama - 1]->detail);
			mylist[buycnt]->price = drama[buy_drama - 1]->price;
			buycnt++; //넣고나서 index 하나 증가!

			printf("또 구매하시려면 1번, 메인 메뉴로 나가시려면 2번을 눌러주세요 : >> ");
			int choi;
			scanf("%d", &choi);
			if (choi == 1)
				BuyVideo();
			else if (choi == 2)
				MainMenu();
			else
			{
				printf("잘못 눌렀습니다. 프로그램 종료합니다! \n");
				exit(0);
			}
		}
	}
	else if (genre == 3)//영화 구입
	{
		printf("\n\n ========= 영화 ========= \n\n");
		for (int i = 0; i < movie_update_cnt; i++)
			printf("%d번\n%s\n%s\n%d원\n\n", i + 1, movie[i]->name, movie[i]->detail, movie[i]->price);
		printf("영화 중에 어떤 비디오를 구매하시겠습니까? >> ");
		int buy_movie;
		scanf("%d", &buy_movie);
		if (movie[buy_movie - 1]->price > balance)
		{
			printf("돈이 부족합니다...ㅠㅠ\n마이룸으로 가서 돈을 충전하세요!\n\n");
			MyRoom();
		}
		else //잔액이 충분하다면
		{
			balance -= movie[buy_movie - 1]->price;
			printf("%d번 : %s를 구매하셨습니다.\n", buy_movie, movie[buy_movie - 1]->name);
			printf("\n남은 잔액은 %d원입니다.\n\n", balance);

			//구매했으니 내 리스트에 넣어야겠지??
			mylist[buycnt] = (MyList*)malloc(sizeof(MyList));
			strcpy(mylist[buycnt]->name, movie[buy_movie - 1]->name);
			strcpy(mylist[buycnt]->detail, movie[buy_movie - 1]->detail);
			mylist[buycnt]->price = movie[buy_movie - 1]->price;
			buycnt++; //넣고나서 index 하나 증가!

			printf("또 구매하시려면 1번, 메인 메뉴로 나가시려면 2번을 눌러주세요 : >> ");
			int choi;
			scanf("%d", &choi);
			if (choi == 1)
				BuyVideo();
			else if (choi == 2)
				MainMenu();
			else
			{
				printf("잘못 눌렀습니다. 프로그램 종료합니다! \n");
				exit(0);
			}
		}
	}
}
void MyRoom()//마이룸
{
	printf("======마이룸======\n");
	printf("0. 내 계좌 잔액\n");
	printf("1. 내 쿠폰 개수\n");
	printf("2. 돈 충전\n");
	printf("3. 쿠폰 충전\n");
	printf("4. 아이디 변경\n");
	printf("5. 비밀번호 변경\n");
	printf("6. 내가 구입한 비디오 리스트 보기\n");
	printf("7. 메인 메뉴로 나가기\n");
	printf("=================\n");
	printf(">> ");
	int choice_MyRoom;
	scanf("%d", &choice_MyRoom);
	if (choice_MyRoom == 0)
	{
		printf("당신의 계좌의 잔액은 총 %d원입니다.\n\n", balance);
		MyRoom();
	}
	else if (choice_MyRoom == 1)
	{
		printf("당신의 쿠폰은 총 %d개입니다.\n\n", coupon);
		MyRoom();
	}
	else if (choice_MyRoom == 2)
	{
		int money;
		printf("충전할 금액을 적으세요! >> ");
		scanf("%d", &money);
		balance += money;
		printf("%d원이 충전되었습니다. 이제 총 잔액은 %d원입니다.\n\n", money, balance);
		MyRoom();
	}
	else if (choice_MyRoom == 3)
	{
		int addCoupon;
		printf("충전할 쿠폰 갯수를 적으세요! >> ");
		scanf("%d", &addCoupon);
		coupon += addCoupon;
		printf("쿠폰 %d개가 충전되었습니다. 이제 총 쿠폰은 %d개입니다.\n\n", addCoupon, coupon);
		MyRoom();
	}
	else if (choice_MyRoom == 4)
	{
		char change_id[20];
		printf("변경할 아이디를 입력하세요: >> ");
		scanf("%s", change_id);
		real_id = &change_id;
		printf("아이디 변경되었습니다! 바뀐 아이디는 %s 입니다.\n\n", real_id);
		MyRoom();
	}
	else if (choice_MyRoom == 5)
	{
		char change_pw[20];
		printf("변경할 비밀번호를 입력하세요: >> ");
		scanf("%s", change_pw);
		real_password = &change_pw;
		printf("아이디 변경되었습니다! 바뀐 아이디는 %s 입니다.\n\n", real_password);
		MyRoom();
	}
	else if (choice_MyRoom == 6)
	{
		printf("====내가 구입한 비디오 목록====\n\n");
		for (int i = 0; i < buycnt; i++)
		{
			printf("%d번 : %s, %s\n", i + 1, mylist[i]->name, mylist[i]->detail);
			printf("가격 : %d원\n\n", mylist[i]->price);
		}
		printf("메인메뉴로 가시려면 1번을 누르세요 >> ");
		int n;
		scanf("%d", &n);
		if (n == 1)
			MainMenu();
	}
	else if (choice_MyRoom == 7)
	{
		MainMenu();
	}
}
