#include <iostream>
#include <stack>
using namespace std;

/*class MinStack {
public:
	MinStack() {
	
	}

	void push(int x) {
		_elem.push(x);
		if (_min.empty()||x <=_min.top())
		{
			_min.push(x);
		}
	}

	void pop() {
		if (_elem.top() == _min.top())
		{
			_elem.pop();
			_min.pop();
			return;
		}
		_elem.pop();
		
	}

	int top() {
		return _elem.top();
	}

	int getMin() {
		return _min.top();
	}
private:
	//����ջ�е�Ԫ��
	std::stack<int> _elem;
	//����ջ����Сֵ
	std::stack<int> _min;
};
*/

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/

/*void test1()
{
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() << endl;
	minStack.pop();
	cout<<minStack.top()<<endl;
	cout<<minStack.getMin()<<endl;
}*/
#include <vector>
class Solution1 {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		//��ջ�ͳ�ջ��Ԫ�ظ���������ͬ
		if (pushV.size() != popV.size())
		{
			return false;
		}
		//��s��ģ����ջ���ջ�Ĺ���
		int outIdx = 0;
			int inIdx = 0;
		stack<int> s;
		while (outIdx < popV.size())
		{
			//���s�ǿ� ����ջ��Ԫ�����ջ��Ԫ�ز���ȣ�����ջ
			while (s.empty() || s.top() != popV[outIdx])
			{
				if (inIdx < pushV.size())
				{
					s.push(pushV[inIdx++]);
				}
				else
				{
					return false;
				}

			}
			//ջ��Ԫ�����ջԪ����ȣ���ջ
			s.pop();
			outIdx++;
		}
		return true;
	}
};
class Solution2
{
public:
	int evalRPN(vector<string>& tokens){
		stack<int> s;
		for (size_t i = 0; i < tokens.size(); i++)
		{
			string& str = tokens[i];
			//strΪ����
			//������ջ����
			if (!("+" == str || "-" == str || "*" == str || "/" == str))
			{
				s.push(atoi(str.c_str()));//�ַ���ת����
			}
			else
			{
				//strΪ������
				//��ջ ��������
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();
				
				switch (str[0]) //��������ջ
				{
				case '+':
					s.push(left + right);
					break;
				case '-':
					s.push(left - right);
						break;
				case'*':
					s.push(left*right);
					break;
				case'/':
					s.push(left / right);
						break;
				}
			}
		}
		return s.top();
	}
private:

};

int main()
{
	//test1();
	return 0;
}