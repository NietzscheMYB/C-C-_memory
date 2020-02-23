#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	////6 10 15
public:
	int nthUglyNumber(int index) {

		// 0-6�ĳ����ֱ�Ϊ0-6
		if (index < 7) return index;
		//p2��p3��p5�ֱ�Ϊ�������е�ָ�룬newNumΪ�Ӷ���ͷѡ��������С��
		int p2 = 0, p3 = 0, p5 = 0, newNum = 1;
		vector<int> arr;
		arr.push_back(newNum);
		while (arr.size() < index) {
			//ѡ����������ͷ��С����
			newNum = min(arr[p2] * 2, min(arr[p3] * 3, arr[p5] * 5));
			//������if�п��ܽ���һ�����߶��������������������ͷ��С�����ж�������
			if (arr[p2] * 2 == newNum) p2++;
			if (arr[p3] * 3 == newNum) p3++;
			if (arr[p5] * 5 == newNum) p5++;
			arr.push_back(newNum);
		}
		return newNum;
	}
};

int main()
{
	return 0;
}