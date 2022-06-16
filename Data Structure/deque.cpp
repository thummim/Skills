#include <iostream>
#include <deque>
#include <string>

using namespace std;
deque<int> dq;

// 덱은 앞에서만 꺼낼 수 있는 큐와 다르게 앞뒤로 참조가 가능함
// 양방향 큐라고도 함

int main()
{
	dq.push_front(1);
	dq.push_back(2);
	dq.push_back(3);
	cout << dq.front() << "\n";
	cout << dq.back() << "\n";
	cout << dq.size() << "\n";
	dq.pop_back();
	dq.pop_front();
	cout << dq.size() << "\n";
	return 0;
}
