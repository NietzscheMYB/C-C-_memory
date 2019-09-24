#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int h, w;
	cin >> w >> h;
	vector<vector<int>>  v;

	v.resize(w);//v���н������ݣ�����

	for (auto& e : v)
	{
		e.resize(h, 1);//ÿһ�����ݣ����ݵ�ֵΪ1
	}

	int ret = 0;
	for (int x = 0; x < w; x++)
	{
		for (int y = 0; y < h; y++)
		{
			if (v[x][y] == 1)
			{
				ret++;
				//��ǲ��ܷŵ����λ��
				if ((x + 2) < w)
				{
					v[x + 2][y] = 0;
				}
				if ((y + 2) < h)
				{
					v[x][y + 2] = 0;
				}
			}
		}
	}
	cout << ret << endl;
	return 0;
}