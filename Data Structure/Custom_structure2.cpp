#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
	int y, x;
	bool operator < (const Point & a) const
	{
		if (x == a.x) return y < a.y;
		return x < a.x;
	}

};

vector<Point> v;

int main()
{
	for (int i = 10; i >= 1; i--)
	{
		Point a = { i, i };
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (auto it : v) cout << it.y << " : " << it.x << '\n';
	return 0;
}




/*
1 : 9
2 : 8
3 : 7
4 : 6
5 : 5
6 : 4
7 : 3
8 : 2
9 : 1
10 : 0
*/
