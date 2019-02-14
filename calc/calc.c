#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	int i, a, b ,c;
	int count = 0;
	for(i=0; i<10; ++i)
	{
		a = rand() %100;
		b = rand() % (100-a+1);
		printf("%d + %d = ", a, b);
		scanf("%d",&c);
		if(c == a+b)
		{
			printf("正确\n");
			++count;
		}else
		{
			printf("错误,正确答案为 %d\n",a+b);
		}
	}
	for(i=0; i<10; ++i)
	{
		a = rand() %100;
		b = rand() % (100-a+1);
		c = a+b;
		printf("%d - %d = ", c, a);
		scanf("%d",&b);
		if(b == c-a)
		{
			printf("正确\n");
			++count;
		}else
		{
			printf("错误,正确答案为 %d\n",c-a);
		}
	}
	printf("你答对了 %d 题，正确率为 %.2f\n", count, count/20.0*100);
	return 0;
}
