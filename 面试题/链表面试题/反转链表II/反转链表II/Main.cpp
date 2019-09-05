#include<iostream>
#include<vector>
using namespace std;

//* Definition for singly-linked list.
 struct ListNode {
    int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		vector<int> v;
		int x = m, y = n;
		y = y - x;
		x--;
		ListNode* p = head;
		ListNode* q = head;
		while (x)
		{
			p = p->next;
			x--;
		}
		q = p;
		while (y)
		{
			q = q->next;
			y--;
		}
		ListNode* q1 = p;
		while (q1 != q)
		{
			v.push_back(q1->val);
			q1 = q1->next;
		}
		v.push_back(q1->val);
		while (p != q)
		{
			p->val = v.back();
			v.pop_back();
			p = p->next;
		}
		p->val = v.back();
		return head;
	}
};


//class Solution {
//public:
//	ListNode* reverseBetween(ListNode* head, int m, int n) {
//		ListNode* p = head;
//		vector<int> ans;
//		int x = m;
//		int y = n;
//		y = y - x;
//		int y2 = y;
//		x--;
//		while (x)
//		{
//			p = p->next;
//			x--;
//		}
//		ListNode* q = p;
//		ListNode* q2 = p;
//		while (y)
//		{
//			ans.push_back(q2->val);
//			y--;
//			q2 = q2->next;
//		}/*
//		ans.push_back(q2->val);
//		while (y2)
//		{
//			q->val = ans.back();
//			ans.pop_back();
//			q = q->next;
//			y2--;
//		}
//		q->val = ans.back();
//		return head;
//	}
//};*/