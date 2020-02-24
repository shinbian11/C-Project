#include <stdio.h>
#define ROWS 4
#define COLS 3
int m[ROWS][COLS] = { {1,2,3},{4,5,6},{7,8,9},{10,11,12} };

int get_row_avg(int m[ROWS][COLS], int r)
{
	int* p, * endp;
	int sum = 0;
	p = &m[r][0];
	endp = &m[r][COLS - 1];
	while (p <= endp)
	{
		sum += *p;
		p++;
	}
	sum /= COLS;
	return sum;
}
int main()
{
	for (int i = 0; i < ROWS; i++)
	{
		printf("%d행의 원소들의 평균은 %d입니다.\n", i, get_row_avg(m,i));
	}
}

