#include<iostream>
#include<vector>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 //对两个链表的情况进行处理,合并
 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
 {
	 if (nullptr == l1)
	 {
		 return l2;
	 }
	 if (nullptr == l2)
	 {
		 return l1;
	 }
	 ListNode vhead(0);
	 ListNode* ans = &vhead;
	 while (l1&&l2)
	 {
		 if (l1->val <= l2->val)
		 {
			 ans->next = l1;
			 l1 = l1->next;
			 ans = ans->next;
		 }
		 else
		 {
			 ans->next = l2;
			 l2 = l2->next;
			 ans = ans->next;
		 }
	 }
	 if (nullptr == l1)
	 {
		 ans->next = l2;
	 }
	 if (nullptr == l2)
	 {
		 ans->next = l1;
	 }
	 return vhead.next;
 }

 class Solution {
 public:
	 ListNode* mergeKLists(vector<ListNode*>& lists) {
		 if (lists.size() == 0)
		 {
			 return nullptr;
		 }
		 if (lists.size() == 1)
		 {
			 return lists[0];
		 }
		 if (lists.size() == 2)
		 {
			 return mergeTwoLists(lists[0],lists[1]);
		 }

		 int mid = lists.size() / 2;
		 vector<ListNode*> sub1;
		 vector<ListNode*> sub2;
		 for (int i = 0; i < mid; i++)
		 {
			 sub1.push_back(lists[i]);
		 }
		 for (int j = mid; j < lists.size(); j++)
		 {
			 sub2.push_back(lists[j]);
		 }
		 return mergeTwoLists(mergeKLists(sub1), mergeKLists(sub2));
	 }
 };

 //ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
 //{
	// ListNode l(0);
	// if (l1 == nullptr)
	// {
	//	 return l2;
	// }
	// if (l2 == nullptr)
	// {
	//	 return l1;
	// }
	// ListNode* ans = &l;
	// while (l1&&l2)
	// {
	//	 if (l1->val <= l2->val)
	//	 {
	//		 ans->next = l1;
	//		 l1 = l1->next;
	//		 ans = ans->next;
	//	 }
	//	 else
	//	 {
	//		 ans->next = l2;
	//		 l2 = l2->next;
	//		 ans = ans->next;
	//	 }
	// }
	// if (l1 == nullptr)
	// {
	//	 ans->next = l2;
	// }
	// if (l2 == nullptr)
	// {
	//	 ans->next = l1;
	// }
	// return l.next;
 //}
 //class Solution {
 //public:
	// ListNode* mergeKLists(vector<ListNode*>& lists) {
	//	 if (lists.empty())
	//	 {
	//		 return nullptr;
	//	 }
	//	 if (lists.size() == 1)
	//	 {
	//		 return lists[0];
	//	 }
	//	 if (lists.size() == 2)
	//	 {
	//		 return mergeTwoLists(lists[0], lists[1]);
	//	 }
	//	 int mid = lists.size() / 2;
	//	 vector<ListNode*> sub_list1;
	//	 vector<ListNode*> sub_list2;
	//	 for (int i = 0; i<mid; i++)
	//	 {
	//		 sub_list1.push_back(lists[i]);
	//	 }
	//	 for (int j = mid; j<lists.size(); j++)
	//	 {
	//		 sub_list2.push_back(lists[j]);
	//	 }

	//	 return mergeTwoLists(mergeKLists(sub_list1), mergeKLists(sub_list2));
	// }
 //};