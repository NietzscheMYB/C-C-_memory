#include <queue>
#include <iostream>
#include <functional>
using namespace std;
class Date
{
private:
	int _y;
	int _m;
	int _d;
public:
	Date(int y, int m, int d)
		:_y(y), _m(m), _d(d)
	{}
	bool operator<(const Date& d) const
	{
		return _y < d._y || (_y == d._y&&_m < d._m)
			|| (_y == d._y&&_m == d._m&&_d < d._d);
	}
	bool operator>(const Date& d) const
	{
		return _y>d._y || (_y == d._y&&_m>d._m) ||
			(_y == d._y&&_m == d._m&&_d>d._d);
	}
	friend ostream& operator<<(ostream& _cout, const Date& d);
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._y << '-' << d._m << '-' << d._d << endl;
	return _cout;
}

void test1()
{
	priority_queue<Date> d;
	d.push(Date(2018, 8, 10));
	d.push(Date(2019, 5, 12));
	d.push(Date(2014, 4, 12));
	while (!d.empty())
	{
		cout << d.top()<< endl;
		d.pop();
	}
	
}
template<class T, class Container = deque<T>>
class Queue{
private:
	Container _con;
public:
	void Push(const T&x)
	{
		_con.push_back(x);
	}
	void Pop()
	{
		_con.pop_front();
	}
	T& Front()
	{
		return _con.front();
	}
	size_t Size()
	{
		return _con.size();
	}
	bool Empty()
	{
		return _con.empty();
	}
	T& Back()
	{
		return _con.back();
	}
};


void test2()
{
	Queue<int, deque<int>> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	while (!q.Empty())
	{
		cout << q.Front() << endl;
		q.Pop();
	}
	cout << endl;
	
}

int main()
{
	test2();
	return 0;
}