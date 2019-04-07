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
	//保存栈中的元素
	std::stack<int> _elem;
	//保存栈的最小值
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
		//入栈和出栈的元素个数必须相同
		if (pushV.size() != popV.size())
		{
			return false;
		}
		//用s来模拟入栈与出栈的过程
		int outIdx = 0;
			int inIdx = 0;
		stack<int> s;
		while (outIdx < popV.size())
		{
			//如果s是空 或者栈顶元素与出栈的元素不相等，就入栈
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
			//栈顶元素与出栈元素相等，出栈
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
			//str为数字
			//数字入栈！！
			if (!("+" == str || "-" == str || "*" == str || "/" == str))
			{
				s.push(atoi(str.c_str()));//字符串转整形
			}
			else
			{
				//str为操作数
				//出栈 进行运算
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();
				
				switch (str[0]) //运算结果入栈
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