#include<iostream>
using namespace std;

#if 0
//��ͨ��̨�ף�����1�Σ�������2��
class Solution {
public:
	int jumpFloor(int number) {
		if (number == 0)
		{
			return 1;
		}
		if (number == 1)
		{
			return 1;
		}
		return jumpFloor(number - 1) + jumpFloor(number - 2);
	}
};
#endif




int main()
{
	return 0;
}