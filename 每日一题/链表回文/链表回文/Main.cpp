#include<iostream>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		//ListNode* newhead=new ListNode(0);
		ListNode* p1 = A;
		ListNode* p2 = nullptr;
		while (p1)
		{
			if (p2 == nullptr)
			{
				p2 = p1;
				p1 = p1->next;
				p2->next = nullptr;
				continue;
			}
			ListNode* p3 = p1;
			p1 = p1->next;
			p3->next = p2;
			p2 = p3;

		}
		//p2->next=nullptr;
		//p2=newhead->next;
		p1 = A;
		int flag = 0;
		while (p2&&p1)
		{
			if (p1->val == p2->val)
			{
				p1 = p1->next;
				p2 = p2->next;
				flag = 1;
				continue;
			}
			flag = 0;
			break;
		}
		if (flag == 0)
		{
			return false;
		}
		else{
			return true;
		}
	}
};
int main()
{
	return 0;
}