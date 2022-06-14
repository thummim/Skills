#include <iostream>
#include <stack>
#include <string>
//#include <bits/stdc++.h>

using namespace std;
stack<string> stk;

// 스택은 가장 마지막으로 들어간 데이터가 가장 첫 번째로 나오는 LIFO(Last In First Out)의 구조를 지님
// 재귀함수, 알고리즘, 웹 브라우저 방문기록 등에 쓰이며 삽입 및 삭제에 O(1), 탐색에 O(n)이 걸림
// 알고리즘 문제에서 문자열 폭발, 아름다운 괄호만들기, 짝을 찾기 등에 쓰이며 "교차하지 않고" 등에 사용될 수 있음

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stk.push("가");
	stk.push("나");
	stk.push("다");
	stk.push("라");
	stk.push("마");
	stk.push("바");

	while (stk.size())
	{
		cout << stk.top() << "\n";
		stk.pop();
	}
	return 0;
}
