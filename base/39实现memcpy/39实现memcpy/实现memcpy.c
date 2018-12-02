/* void *memcpy(void *dest, const void *src, size_t n);
它的功能是从src的开始位置拷贝n个字节的数据到dest。如果dest存在数据，
将会被覆盖。memcpy函数值的返回值是dest的指针。
*/


#include <stdio.h>
#include <windows.h>
#include <assert.h>
void My_memcpy(char *p1, const char *p2, int n)
{
	assert(p1);
	assert(p2);
	//printf("%s\n", p1);
	//printf("%c\n", *p1);
	int i = 0;
	//	char x = '0';
	char *q = p1;
	while (i<n)
	{
		*p1 = *p2;
		p1++;
		p2++;
		i++;
	}
	p1 = q;
	printf("%s\n", p1);
	//return;
}
int main()
{
	char p1[] = "021345645";
	const char *p2 = "ajdf";
	My_memcpy(p1, p2, sizeof(p2));
	//int a = sizeof(p2);
	//printf("%d\n", a);
	printf("%s\n", p1);
	system("pause");
	return 0;
}