#include<iostream>
using namespace std;


#if 0
int func(int n, int m)
{
	if (n == 1&&m==1)
	{
		return 1;
	}
	if (n == 1)
	{
		return func(n, m - 1);
	}
	if (m == 1)
	{
		return func(n - 1, m);
	}
	int ret1 = func(n - 1, m);
	int ret2 = func(n, m - 1);
	return ret1 + ret2;
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int ret = func(n + 1, m + 1);
		cout << ret << endl;
	}

	return 0;
}
#endif


#if 0
class Solution {
public:
	int  NumberOf1(int n) {
		if (n == 0)
		{
			return 0;
		}
		if (n > 0)
		{
			int count = 0;
			for (int i = 0; i <= 32; i++)
			{
				if ((1 << i)&n)
				{
					count++;
				}
			}
			return count;
		}
		else{
			int count = 0;
			
			int m = n ;
			for (int i = 0; i <= 32; i++)
			{
				if ((1 << i)&m)
				{
					count++;
				}
			}
			return count;
		}
	}
};

int main()
{
	//Solution a;
	int n = -1;
	n = ~n;//°´ÕÕ²¹ÂëÈ¡·´
	cout << n<< endl;
	return 0;
}
#endif



#include<vector>
#if 0
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr)
		{
			return nullptr;
		}
		vector<ListNode*> v;
		ListNode* pCur = pListHead;
		
		while (pCur)
		{
			if (pCur)
			{
				v.push_back(pCur);
			}
			pCur = pCur->next;
		}
		if (k > v.size())
		{
			return nullptr;
		}
		return v[v.size() - k];
	}
};
#endif



struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		vector<ListNode*> v;
		ListNode* pCur = pHead;
		if (pCur == nullptr)
		{
			return nullptr;
		}
		while (pCur)
		{
			v.push_back(pCur);
			pCur = pCur->next;
		}
		ListNode* head = v.back();
		pCur = head;
		while (!v.empty())
		{
			v.pop_back();
			if (!v.empty())
			{
				pCur->next = v.back();
				pCur = pCur->next;
			}
		}
		pCur->next = nullptr;
		return head;
	}
};