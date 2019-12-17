#include<iostream>
#include<stack>
using namespace std;
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		if (!s1.empty())
		{
			int temp = getMin();
			if (temp >= x)
			{
				s2.push(x);
			}
			s1.push(x);
			return;
		}
		else{
			s1.push(x);
			s2.push(x);
		}
	}

	void pop() {
		int temp = s1.top();
		if (temp == s2.top())
		{
			s1.pop();
			s2.pop();
		}
		else{
			s1.pop();
		}
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return s2.top();
	}

	stack<int> s1;
	stack<int> s2;

};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/

int main()
{
	return 0;
}