#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	double elec;
	double money = 1.5;
	scanf("%lf", &elec);
	if (elec <= 150)
	{
		money = elec*0.4463;
	}
	if (150 < elec <=400)
	{
		money = 150 * 0.4463 + (elec-150)*0.4663;
	}
	if (elec >= 401)
	{
		money = 150 * 0.4463 +(400-150)* 0.4663 + (elec-400)*0.5663;
	}
	//printf("%lf\n", (money*10+0.5)/10);
	printf("%.1lf\n", money);

	return 0;
}