//奖券数目
//
//有些人很迷信数字，比如带“4”的数字，认为和“死”谐音，就觉得不吉利。
//虽然这些说法纯属无稽之谈，但有时还要迎合大众的需求。某抽奖活动的奖券号码是5位数（10000 - 99999），要求其中不要出现带“4”的号码，
//主办单位请你计算一下，如果任何两张奖券不重号，最多可发出奖券多少张。
//
//请提交该数字（一个整数），不要写任何多余的内容或说明性文字。
#include <iostream>
using namespace std;
int main()
{
	int i, j, k, l,p;
	int count = 0;
	for (i = 1; i <= 9; i++)
	{
		if (i == 4)
		{
			continue;
		}
		for (j = 0; j <= 9; j++)
		{
			if (j == 4)
			{
				continue;
			}
			for (k = 0; k <= 9; k++)
			{
				if (k == 4)
				{
					continue;
				}
				for (l = 0; l <= 9; l++)
				{	
					if (l == 4)
						{
							continue;
						}
					for (p = 0; p <= 9; p++)
					{
						if (p == 4)
						{
							continue;
						}

						printf("%d%d%d%d%d\n", i, j, k, l,p);
						count++;
					}
					
				}
			}
		}
	}
	printf("%d\n", count);
	return 0;
}