
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	FILE* fptr;
	fptr = fopen("test.txt", "r");
	char arr[1024] = { 0 };
	int count = 0;
	while (fgets(arr,1022,fptr)!=nullptr)
	{
		arr[1023] = '\0';
		count++;
		string s(arr);
		int pos1 = 0, pos2 = 0;
		int flag1 = 0, flag2 = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if ('a' == s[i] && flag1 == 0)
			{
				flag1 = 1;
				pos1 = i;
				continue;
			}
			if ('b' == s[i] && flag2 == 0)
			{
				flag2 = 1;
				pos2 = i;
				continue;
			}
		}
		cout << count << " " << pos1 + 1 << " " << pos2 + 1 << endl;
	}
	fclose(fptr);
	return 0;

}



