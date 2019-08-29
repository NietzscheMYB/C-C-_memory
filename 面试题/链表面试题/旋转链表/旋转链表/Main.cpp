#include<iostream>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr)
		{
			return head;
		}
		int count = 0;
		ListNode* cur = head;
		ListNode* pre = head;
		ListNode* h = head;
		while (cur)
		{
			cur = cur->next;
			count++;
		}
		if (k%count == 0)
		{
			return head;
		}
		cur = head;
		k = k%count;
		while (k)
		{
			while (cur->next)
			{
				pre = cur;
				cur = cur->next;
			}
			pre->next = nullptr;
			cur->next = h;
			head = cur;
			cur = head;
			pre = head;
			h = head;
			k--;
		}
		return head;
	}
};