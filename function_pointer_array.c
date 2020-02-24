#include <stdio.h>
int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);
void menu()
{
	printf("=================\n");
	printf("1. 덧셈\n");
	printf("2. 뺄셈\n");
	printf("3. 곱셈\n");
	printf("4. 나눗셈\n");
	printf("=================\n");
}
int main()
{
	/*포인터가 변수만 가르키는건 아니다. 떄로는 함수를 가리킬때도 있다. 함수도 자신의 주소가 있다.
	그러므로 함수 포인터를 만들면 포인터를 통해서 그 함수를 호출할수있다.*/
	//이때 그 함수 포인터들의 배열을 함수 포인터 배열이라고 한다. 함수를 가리키는 포인터들이 여러개인것!
	int (*pf[4])(int, int) = { add,sub,mul,div }; //함수 포인터 배열
	while (1)
	{
		menu();
		int n;
		scanf("%d", &n);
		if (n < 1 || n > 4)
		{
			printf("잘못된 입력입니다.\n");
			break;
		}
		int n1, n2;
		printf("두 수를 입력! ");
		scanf("%d %d", &n1, &n2);
		int answer = pf[n - 1](n1, n2);
		printf("답은 %d입니다.\n", answer);
	}

}
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x % y;
}