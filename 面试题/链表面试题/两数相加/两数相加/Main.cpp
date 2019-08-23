#include<iostream>
using namespace std;
//�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
//
//��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�
//
//�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode-cn.com/problems/add-two-numbers
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
 struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode vHead(0), *p = &vHead;
		int flag = 0;//��λ
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

