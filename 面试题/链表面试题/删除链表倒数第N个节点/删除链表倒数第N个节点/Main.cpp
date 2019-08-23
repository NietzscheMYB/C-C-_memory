//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr)
			return nullptr;
		int size = 0;
		ListNode*q = head;
		ListNode*p = head;
		ListNode*x = head;
		while (p)
		{
			size++;
			p = p->next;
		}
		int diff = size - n;
		if (diff == 0)
		{
			return head->next;
		}
		while (diff)
		{
			x = q;
			diff--;
			q = q->next;
		}
		x->next = q->next;
		return head;
	}
};