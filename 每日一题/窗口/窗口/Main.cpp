#include<iostream>
#include<list>
using namespace std;
struct window{
	int numid;
	int x1;
	int y1;
	int x2;
	int y2;
};

int main()
{
	list<window> l;
	int N, M;
	cin >> N>>M;
	for (int i = 0; i < N; i++)
	{
		window w;
		w.numid = i + 1;
		cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
		l.push_front(w);
	}
	while (M--)
	{
		int x, y;
		cin >> x >> y;
		auto it = l.begin();
		int count=0;
		while (it != l.end())
		{
			if (x >= it->x1&&x <= it->x2&&y >= it->y1&&y <= it->y2)
			{
				window w;
				w.numid = it->numid;
				w.x1 = it->x1;
				w.x2 = it->x2;
				w.y1 = it->y1;
				w.y2 = it->y2;
				cout << it->numid << endl;
				l.erase(it);
				l.push_front(*it);
				break;
			}
			it++;
			count++;
		}
		if (count== l.size())
		{
			cout <<"IGNORED"<< endl;
		}
	}
	return 0;
}