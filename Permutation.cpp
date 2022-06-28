#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void printV(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
}

int main()
{
	int a[3] = { 1, 2, 3 };
	vector<int> v;
//오름차순 (1,2,3)
	for (int i = 0; i < 3; i++)
		v.push_back(a[i]);

	do
	{
		printV(v);
	}while (next_permutation(v.begin(), v.end()));
	cout << "----------" << '\n';
	v.clear();

//내림차순 (3,2,1)
	for (int i = 2; i >= 0; i--)
		v.push_back(a[i]);
	do
	{
		printV(v);
	} while (prev_permutation(v.begin(), v.end()));

	return 0;
}

/*
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
-------------
3 2 1
3 1 2
2 3 1
2 1 3
1 3 2
1 2 3
*/
