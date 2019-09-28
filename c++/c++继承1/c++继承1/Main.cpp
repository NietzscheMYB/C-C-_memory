#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	void Print()
	{
		cout << "name: " << _name << endl;
		cout << "age: " << _age << endl;
	}
protected:
	string _name = "peter";
	int _age = 18;
};



int main()
{
	char* ptr;
	cout << sizeof(ptr) << endl;
	return 0;
}