#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Employee info
class Employee {
public:
// It's the unique ID of each node.
// unique id of this employee
int id;
// the importance value of this employee
int importance;
// the id of direct subordinates
vector<int> subordinates;
};

class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		// vector<bool> inq(employees.size()+1,false);
		vector<bool> inq(2000 + 1, false);

		int ans = 0;

		queue<Employee*> q;
		auto it = employees.begin();
		while (it != employees.end())
		{
			if ((*it)->id == id)
			{
				break;
			}
			it++;
		}
		q.push(*it);
		inq[id] = true;

		while (!q.empty())
		{
			Employee* tem = q.front();
			ans += tem->importance;
			q.pop();
			for (int i = 0; i<tem->subordinates.size(); i++)
			{
				if (inq[tem->subordinates[i]] == false)
				{
					inq[tem->subordinates[i]] = true;
					auto itt = employees.begin();
					while (itt != employees.end())
					{
						if ((*itt)->id == tem->subordinates[i])
						{
							break;
						}
						itt++;
					}
					q.push(*itt);
				}
			}
		}
		//ans-=employees[id-1]->importance;
		return ans;
	}
};

int main()
{
	return 0;
}