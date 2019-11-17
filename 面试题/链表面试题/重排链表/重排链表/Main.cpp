#include<iostream>
#include<vector>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	void reorderList(ListNode* head) {
		vector<ListNode*> v;
		if (head == nullptr)
		{
			return;
		}
		ListNode* pCur = head;
		while (pCur)
		{
			v.push_back(pCur);
			pCur = pCur->next;
		}
		vector<ListNode*> vn;
		int count1 = 0;
		int count2 = v.size() - 1;
		while (count1!=count2&&count1<count2)
		{
			vn.push_back(v[count1++]);
			vn.push_back(v[count2--]);
		}
		if (count1 == count2)
		{
			vn.push_back(v[count1]);
		}
		for (int i = 0; i < vn.size()-1; i++)
		{
			vn[i]->next = vn[i + 1];
		}
		vn[vn.size() - 1]->next = nullptr;
	}
};

int main()
{
	ListNode* head=new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	Solution s;
	s.reorderList(head);
	return 0;
}