#include<iostream>
//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode vHead(0);
		ListNode* ans = &vHead;
		ListNode* p = l1;
		ListNode* q = l2;
		if (p == nullptr)
		{
			return q;
		}
		if (q == nullptr)
		{
			return p;
		}
		while (q&&p)
		{
			if (q->val <= p->val)
			{
				ans->next = q;
				ans = ans->next;
				q = q->next;
			}
			else{
				ans->next = p;
				ans = ans->next;
				p = p->next;
			}
		}
		if (p==nullptr)
		{
			ans->next = q;
		}
		if (q == nullptr)
		{
			ans->next = p;
		}
		return vHead.next;
	}
};

//class Solution {
//public:
//	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//		ListNode vHead(0);
//		ListNode* ans = &vHead;
//		if (l1 == nullptr)
//		{
//			return l2;
//		}
//		if (l2 == nullptr)
//		{
//			return l1;
//		}
//		if (l1 == nullptr&&l2 == nullptr)
//		{
//			return nullptr;
//		}
//		ListNode* p = l1;
//		ListNode* q = l2;
//		while (p&&q)
//		{
//			if (p->val <= q->val)
//			{
//				ans->next = p;
//				ans = ans->next;
//				p = p->next;
//			}
//			else
//			{
//				ans->next = q;
//				ans = ans->next;
//				q = q->next;
//			}
//
//
//
//		}
//		if (p == nullptr)
//		{
//
//			ans->next = q;
//
//
//		}
//		if (q == nullptr)
//		{
//
//			ans->next = p;
//
//		}
//		return vHead.next;
//	}
//};