#include<iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		//�������������
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		ListNode* p1 = head;
		ListNode* p2 = head->next;
		p1->next = p2->next;
		p2->next = p1;
		head = p2;

		p1 = head -> next;
		p2 = p1->next;
		while (p2&&p2->next)
		{
			//����
			ListNode* temp = p2->next->next;
			p1->next = p2->next;
			p2->next = temp;
			p1->next->next = p2;
			
			//��ǰ����
			p1 = p2;
			p2 = p1->next;

		}
		return head;
	}
};

//class Solution {
//public:
//	ListNode* swapPairs(ListNode* head) {
//		if (head == nullptr || head->next == nullptr)
//		{
//			return head;
//		}
//		ListNode* p1 = head;
//		ListNode* p2 = head->next;
//		p1->next = p2->next;
//		p2->next = p1;
//		head = p2;//�ı�head
//
//		p1 = head->next;
//		p2 = p1->next;
//		while (p2&&p2->next)
//		{
//			ListNode* temp = p2->next->next;
//			p1->next = p2->next;
//			p2->next = temp;
//			p1->next->next = p2;
//
//			p1 = p2;
//			p2 = p1->next;
//		}
//		return head;
//	}
//};