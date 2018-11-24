/*.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 
给20元，可以多少汽水。 */


#include <stdio.h>
int main()
{
	int bottle ;
	int empty_bottle;
	int flag;
	int money = 20;
	int sum = 0;
	sum = 20;
	empty_bottle = 20 / 1;
	while (empty_bottle)
	{
		sum += empty_bottle / 2;
		empty_bottle = empty_bottle / 2;
		
	}
	sum++;
	printf("%d\n", sum);
}