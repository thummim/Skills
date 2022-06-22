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
1 : 1
2 : 2
3 : 3
4 : 4
5 : 5
6 : 6
7 : 7
8 : 8
9 : 9
10 : 10
*/
