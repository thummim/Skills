#include <iostream>
#include <set>
#include <string>
//#include <bits/stdc++.h>

using namespace std;

int main()

{
	set<pair<string, int>> st;
	
	//set은 중복되는 요소 없이 고유한 요소만을 저장하는 자료구조이므로 아래와 같이 중복된 값을 넣으면 중복된 값을 제거하고 희소한(unique)값만 저장한다.
	st.insert({ "test", 1 });
	st.insert({ "test", 1 });
	st.insert({ "test", 1 });
	st.insert({ "test", 1 });

	// 1을 4번 insert했지만 중복된 값이므로 1개의 요소만 남아있어서 1의 크기가 출력되는걸 확인할 수 있다.
	cout << st.size() << "\n";
	set<int> st2;

	st2.insert(1);
	st2.insert(2);
	st2.insert(2);

	// 1과 2가 출력되는걸 확인할 수 있다.
	for (auto it : st2)
	{
		cout << it << '\n';
	}

	return 0;
}
