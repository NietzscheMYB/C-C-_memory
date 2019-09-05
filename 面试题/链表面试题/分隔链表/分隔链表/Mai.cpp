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
	ListNode* partition(ListNode* head, int x) {
		if (head == nullptr)
		{
			return head;
		}
		vector<int> s;
		vector<int> b;
		ListNode* p = head;
		while (p)
		{
			if (x > p->val)
			{
				s.push_back(p->val);
			}
			else
			{
				b.push_back(p->val);
			}
		}
		p = head;
		vector<int> ans;
		while (b.size())
		{
			ans.push_back(b.back());
			b.pop_back();
		}
		while (s.size())
		{
			ans.push_back(s.back());
			s.pop_back();
		}
		while (p)
		{
			p->val = ans.back();
			p = p->next;
			ans.pop_back();
		}
		return head;
	}

};

//class Solution {
//public:
//	ListNode* partition(ListNode* head, int x) {
//		vector<int> x1, x2;
//		ListNode* p = head;
//		while (p)
//		{
//			if (p->val<x)
//			{
//				x1.push_back(p->val);
//				p = p->next;
//			}
//			else
//			{
//				x2.push_back(p->val);
//				p = p->next;
//			}
//		}
//
//		vector<int> ans;
//		while (x2.size())
//		{
//			ans.push_back(x2.back());
//			x2.pop_back();
//		}
//		while (x1.size())
//		{
//			ans.push_back(x1.back());
//			x1.pop_back();
//		}
//
//		p = head;
//		while (p)
//		{
//			p->val = ans.back();
//			p = p->next;
//			ans.pop_back();
//		}
//		return head;
//	}
//};