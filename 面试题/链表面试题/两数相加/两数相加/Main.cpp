#include<iostream>
using namespace std;
//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/add-two-numbers
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode vHead(0), *p = &vHead;
		int flag = 0;//进位
		while (l1 || l2 || flag)
		{
			int tmp = 0;
			if (l1)
			{
				tmp += l1->val;
			}
			if (l2)
			{
				tmp += l2->val;
			}
			tmp += flag;

			flag = tmp / 10;
			tmp %= 10;

			ListNode* node = new ListNode(tmp);
			node->next = nullptr;
			p->next = node;
			p = p->next;
			
			if (l1)
			{
				l1 = l1->next;
			}
			if (l2)
			{
				l2 = l2->next;
			}
		}
		return vHead.next;
	}
};

