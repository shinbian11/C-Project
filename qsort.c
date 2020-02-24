//qsort함수
#include <stdio.h>
#include <stdlib.h>
int values[] = { 98,23,99,37,16 };
#define MAX 1000000
int values[MAX];
int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b; //첫번째 원소가 더 크면 양수반환,더 작으면 음수반환, 같으면 0   (오름차순)
}
int main()
{
	printf("정렬 전 : ");
	for (int i = 0; i < 5; i++)
		printf("%d ", values[i]);

	printf("\n\n");


	qsort(values, n, sizeof(int), compare);
	//정렬할 배열,원소개수,각원소의크기,비교함수


	printf("정렬 후 : ");

	for (int i = 0; i < 5; i++)
		printf("%d ", values[i]);

}