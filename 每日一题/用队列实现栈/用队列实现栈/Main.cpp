#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int x = q.back();
		int size = q.size() - 1;
		if (size == 0)
		{
			q.pop();
			return x;
		}
		for (int i = 0; i<size; i++)
		{
			int tem = q.front();
			q.push(tem);
			q.pop();
		}
		q.pop();
		return x;
	}

	/** Get the top element. */
	int top() {
		return q.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		if (q.size() == 0)
		{
			return true;
		}
		return false;
	}
	queue<int> q;
	queue<int> q2;
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/

int main()
{
	return 0;
}