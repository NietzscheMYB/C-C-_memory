/*#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int ans=0;
bool check(int a[])
{
if(abs(a[0]-a[1])==1||
abs(a[0]-a[3])==1||
abs(a[0]-a[4])==1||
abs(a[0]-a[5])==1||

abs(a[1]-a[2])==1||
abs(a[1]-a[4])==1||
abs(a[1]-a[5])==1||
abs(a[1]-a[6])==1||

abs(a[2]-a[5])==1||
abs(a[2]-a[6])==1||

abs(a[3]-a[4])==1||
abs(a[3]-a[7])==1||
abs(a[3]-a[8])==1||

abs(a[4]-a[5])==1||
abs(a[4]-a[7])==1||
abs(a[4]-a[8])==1||
abs(a[4]-a[9])==1||

abs(a[5]-a[6])==1||
abs(a[5]-a[8])==1||
abs(a[5]-a[9])==1||

abs(a[6]-a[9])==1||

abs(a[7]-a[8])==1||

abs(a[8]-a[9])==1)
{
return false;
}
return true;
}
void f(int arr[],int k)
{
if(k==10)
{
if(check(arr))
{
ans++;
}
return ;
}
for(int i=k;i<10;i++)
{
{
int t=arr[k];
arr[k]=arr[i];
arr[i]=t;
}
f(arr,k+1);
{
{
int t=arr[k];
arr[k]=arr[i];
arr[i]=t;
}
}
}
}
int main()
{
int arr[]={0,1,2,3,4,5,6,7,8,9};
/*do{
if(check(arr))
{
ans++;
}

}while(next_permutation(arr,arr+10));
cout<<ans<<endl;
f(arr,0);
cout<<ans<<endl;
return 0;
} */



#include <iostream>
#include <sstream>
#include <cstring>
#include<string>
#include <bitset>
#include <algorithm>
using namespace std;
void s2i(string &s, int &i)
{
	stringstream ss;
	ss << s;
	ss >> i;
}
void i2s(string &s, int &i)
{
	stringstream ss;
	ss << i;
	ss >> s;
}
void f(int arr[],int k)
{
	if (k == 9)
	{
		//if ()
		{
			///
		}
	}

	for (int i = k; i <= 9; i++)
	{
		{
			int t = arr[i];
			arr[i] = arr[k];
			arr[k] = t;
		}
		f(arr, k + 1);
		{
			int t = arr[i];
			arr[i] = arr[k];
			arr[k] = t;
		}
	}
}
int main()
{
	string s("123456");
	//int i=0;
	//	s2i(s,i);
	//	 printf("%d\n",i/10);
	//	cout<<i<<endl;
	//	i2s(s,i);
	//	cout<<s<<endl;
	//const	char *p=s.c_str();
	//	printf("%s\n",p);
	/*string ::iterator sit=s.begin();//string::iterator sit=s.begin();
	while(sit!=s.end())
	{
	cout<<*sit<<endl;
	++sit;
	}*/
	//s.insert(0,1,'+');
	// s.push_back('=');
	//s.erase(0,1);
	//s2i(s,i);


	///*int arr[4];
	//int i = 0;*/
	//cout << s << endl;
	////arr[0]=bitset<1>(4);
	////cout<<arr[i]<<endl;
	//cout << bitset<8>(8) << endl;
	//int arr[9];
	//do{

	//} while (next_permutation(arr,arr+9));
	s += '2';
	cout << s << endl;
	return 0;
}















