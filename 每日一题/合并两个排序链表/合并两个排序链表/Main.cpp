#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
#if 0
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
		{
			return pHead2;
		}
		if (pHead2 == nullptr)
		{
			return pHead1;
		}
		ListNode* pCur1 = pHead1;
		ListNode* pCur2 = pHead2;
		ListNode* pp = nullptr;
		ListNode* ret = pp;
		while (pCur1 || pCur2)
		{
			if (pCur1&&pCur2&&pCur1->val < pCur2->val)
			{
				if (pp == nullptr)
				{
					pp = pCur1;
					continue;
				}
				pp->next = pCur1;
				pp = pp->next;
				pCur1 = pCur1->next;
				continue;
			}
			if (pCur1&&pCur2&&pCur1->val >= pCur2->val)
			{
				if (pp == nullptr)
				{
					pp = pCur2;
					continue;
				}
				pp->next = pCur2;
				pp = pp->next;
				pCur2 = pCur2->next;
			}
			if (pCur1 == nullptr)
			{
				pp->next = pCur2;
				break;
			}
			if (pCur2 == nullptr)
			{
				pp->next = pCur1;
				break;
			}
		}
		return ret;

	}
};
#endif

#include<algorithm>
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
		{
			return pHead2;
		}
		if (pHead2 == nullptr)
		{
			return pHead1;
		}
		ListNode* pCur = pHead1;
		while (pCur->next)
		{
			pCur = pCur->next;
		}
		pCur->next = pHead2;
		pCur = pHead1;
		vector<int> v;
		while (pCur)
		{
			v.push_back(pCur->val);
			pCur = pCur->next;
		}
		sort(v.begin(), v.end());
		pCur = pHead1;
		int count = 0;
		while (pCur)
		{
			pCur->val = v[count];
			pCur = pCur->next;
			count++;
		}
		return pHead1;
	}
};

int main()
{
	ListNode* phead1=new ListNode(1);
	phead1->next = new ListNode(3);
	phead1->next->next = new ListNode(5);

	ListNode* phead2 = new ListNode(2);
	phead2->next = new ListNode(4);
	phead2->next->next = new ListNode(6);
	
	Solution s;

	ListNode* ret = s.Merge(phead1, phead2);
	return 0;
}