#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		reverse(s1.begin(), s1.end());
//		reverse(s2.begin(), s2.end());
//		string s3;
//		int len1 = s1.size(), len2 = s2.size();
//		if (len1 > len2)
//		{
//			int i = 0;
//			int cy = 0;
//			for (i = 0; i < len2; i++)
//			{
//				int x = s1[i] - '0';
//				int y = s2[i] - '0';
//				int d = x + y + cy;
//				cy = d / 10;
//				s3 += (d % 10) + '0';
//			}
//			while (cy != 0)
//			{
//				int z = s1[i++] - '0';
//				int d = z + cy;
//				cy = d / 10;
//				s3 += (d % 10) + '0';
//			}
//			if (i >= len1)
//			{
//				break;
//			}
//			for (; i < len1; i++)
//			{
//				s3 += s1[i];
//			}
//		}
//		else if (len1 < len2)
//		{
//			int i = 0;
//			int cy = 0;
//			for (i = 0; i < len1; i++)
//			{
//				int x = s1[i] - '0';
//				int y = s2[i] - '0';
//				int d = x + y + cy;
//				cy = d / 10;
//				s3 += (d % 10) + '0';
//			}
//			while (cy != 0)
//			{
//				int z = s2[i++] - '0';
//				int d = z + cy;
//				cy = d / 10;
//				s3 += (d % 10) + '0';
//				if (i >= len2)
//				{
//					break;
//				}
//			}
//			for (; i < len2; i++)
//			{
//				s3 += s2[i];
//			}
//		}
//		else if (len1 == len2)
//		{
//			int i = 0;
//			int cy = 0;
//			for (i = 0; i < len1; i++)
//			{
//				int x = s1[i] - '0';
//				int y = s2[i] - '0';
//				int d = x + y + cy;
//				cy = d / 10;
//				s3 += (d % 10) + '0';
//			}
//			if (cy == 1)
//			{
//				s3 += '1';
//			}
//		}
//		reverse(s3.begin(), s3.end());
//		cout << s3 << endl;
//	}
//	return 0;
//}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		string s3;
		int len1 = s1.size(), len2 = s2.size();
		if (len1 > len2)
		{
			int i = 0;
			int cy = 0;
			int x, y;
			int d;
			for (i = 0; i < len1; i++)
			{
				if (i < len2)
				{
					 y = s2[i] - '0';
				}
				else{
					 y = 0;
				}
				 x = s1[i] - '0';
				
				 d = x + y + cy;
				cy = d / 10;
				s3 += (d % 10) + '0';
			}
			if (cy == 1)
			{
				s3 += '1';
			}
		}
		else if (len1 < len2)
		{
			int i = 0;
			int cy = 0;
			int x, y;
			int d;
			for (i = 0; i < len2; i++)
			{
				if (i < len1)
				{
					y = s1[i] - '0';
				}
				else{
					y = 0;
				}
				x = s2[i] - '0';

				d = x + y + cy;
				cy = d / 10;
				s3 += (d % 10) + '0';
			}
			if (cy == 1)
			{
				s3 += '1';
			}
		}
		else if (len1 == len2)
		{
			int i = 0;
			int cy = 0;
			for (i = 0; i < len1; i++)
			{
				int x = s1[i] - '0';
				int y = s2[i] - '0';
				int d = x + y + cy;
				cy = d / 10;
				s3 += (d % 10) + '0';
			}
			if (cy == 1)
			{
				s3 += '1';
			}
		}
		reverse(s3.begin(), s3.end());
		cout << s3 << endl;
	}
	return 0;
}