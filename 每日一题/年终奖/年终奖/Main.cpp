#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//class Bonus {
//
//
//public:
//	//int max[1000];
//	int max=0;
//	int i = 0;
//	int sum = 0;
//	int count = 0;
//	
//public:
//	void test(vector<vector<int> > board, int n, int m,int sum)
//	{
//		sum += board[n - 1][m - 1];
//
//		if (n == 1 && m == 1)
//		{
//			if (max<sum)
//			{
//				max = sum;
//			}
//			
//			//max[i++] = sum;
//			//count++;
//			return ;
//		}
//		if (n>1 && m == 1)
//		{
//			test(board, n-1, m,sum);
//		}
//		if (n == 1 && m > 1)
//		{
//			test(board, n, m-1,sum);
//		}
//		if (n > 1 && m > 1)
//		{
//			test(board, n-1, m,sum);
//			test(board, n, m-1,sum);
//		}
//	}
//	int getMost(vector<vector<int> > board) {
//
//		test(board, 2, 2,sum);
//		//sort(max, max + 1000);
//		//return max[999];
//		return max;
//	}
//};
//
//int main()
//{
//	vector<vector<int>>v(2,(vector<int>(2,0)));
//	v[0][1] = 10;
//	v[1][0] = 100;
//
//	Bonus s;
//	cout << s.getMost(v) << endl;
//	cout << s.count << endl;
//
//	return 0;
//}


class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		vector<vector<int>> v(6, vector<int>(6, 0));
		v[0][0] = board[0][0];
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (i == 0 && j == 0)
				{
					continue;
				}
				else if (i == 0 && j != 0)
				{
					v[i][j] = v[i][j - 1] + board[i][j];
				}
				else if (i != 0 && j == 0)
				{
					v[i][j] = v[i - 1][j] + board[i][j];
				}
				else{
					v[i][j] = max(v[i - 1][j], v[i][j - 1]) + board[i][j];
				}
			}
		}
		return v[5][5];
	}
};