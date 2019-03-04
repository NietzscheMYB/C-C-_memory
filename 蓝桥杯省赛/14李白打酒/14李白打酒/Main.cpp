#include <iostream>
using namespace std;

int ans=0;
  
void Find(int jiu, int hua, int dian)   //递归深度优先搜索！！可以做全排列！！
{
	if (dian == 0 && hua == 0&&jiu==1)
	{
		ans++;
		return;
	}
if(dian>0)	Find(jiu * 2, hua, dian - 1);
if(hua>0)	Find(jiu-1, hua - 1, dian);
}

int main()
{
	int jiu = 2,hua=9,dian=5;
	Find(jiu, hua, dian);
	cout << ans << endl;
	return 0;
}
