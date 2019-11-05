#include<iostream>
#include<vector>
using namespace std;
 
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x)
		:val(x), next(NULL)
	{}
};

#if 0
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v1;
		vector<int>	v2;
		ListNode* pCur = head;
		while (pCur)
		{
			v1.push_back(pCur->val);
			pCur = pCur->next;;
		}
		for (int i = v1.size()-1; i>=0; i--)
		{
			v2.push_back(v1.back());
			v1.pop_back();
		}
		return v2;
	}
};
#endif

class Solution {
public:
	vector<int> v1;
	vector<int> printListFromTailToHead(ListNode* head) {
		ListNode* pCur = head;
		if (pCur != nullptr)
		{
			if (pCur->next != nullptr)
			{
				printListFromTailToHead(pCur->next);
			}
			v1.push_back(pCur->val);
		}
		return v1;
	}
};

int main()
{
	return 0;
}