//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	vector<int>::iterator it = v.begin();
//	while (it!=v.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	v.pop_back();
//	v.pop_back();
//	it = v.begin();
//	while (it!=v.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	cout << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	//ʹ��find����3����λ�õ�iterator
//	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
//	//��posλ��֮ǰ����30
//	v.insert(pos,30);
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//	cout << endl;
//	pos = find(v.begin(), v.end(), 3);
//	v.erase(pos);
//	it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//	cout << endl;
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	vector<int> v(a, a + sizeof(a) / sizeof(int));
//	
//	//ͨ��[]��д��0��λ��
//	v[0] = 10;
//	cout << v[0] << endl;
//
//	//ͨ��[i]�ķ�ʽ����vector
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	vector<int> swapv;
//	swapv.swap(v);
//	cout << "v data:";
//	for (size_t i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	cout << "swapv data:";
//
//	for (size_t i = 0; i < swapv.size(); i++)
//	{
//		cout << swapv[i] << " ";
//	}
//	cout << endl;
//
//	//c++11֧�ֵ��µı���
//	for (auto x : swapv)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//	for (auto x : swapv)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//	//swapv.resize(100);
//	swapv.reserve(100);
//	cout << "capacity:" << swapv.capacity() << endl;
//	cout << "size:" << swapv.size() << endl;
//	return 0;
//}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));
	//ʹ��find�ҵ�3���ڵ�λ��
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	
	//1.
	//ɾ��posλ�õ����ݣ�����pos������ʧЧ��
	//v.erase(pos);
	//cout << *pos << endl;//��ʱ��Ƿ�����


	//2.
	//��posλ�ò������ݣ�����pos������ʧЧ
	//insert�ᵼ�µ�����ʧЧ������Ϊinsert���ܻᵼ�����ݣ�
	//���ݺ�pos��ָ��ԭ���Ŀռ䣬��ԭ���Ŀռ��Ѿ����ͷŵ�
	//pos = find(v.begin(), v.end(), 3);
	//v.insert(pos, 30);
	//cout << *pos << endl;//�˴��Ƿ�����


	return 0;
}