#include <iostream>
#include <queue>
#include <string>

using namespace std;
queue<int> q;

// 큐는 스택과는 반대로 먼저 집어넣은 데이터가 먼저 나오는 FIFO(First In First Out)구조임
// 삽입 및 삭제에 O(1), 탐색에 O(n)이 걸림
// 주로 BFS에 사용됨

int main()
{
	q.push(1);
	cout << q.front() << "\n";	// 1
	q.pop();
	cout << q.size() << "\n";	// 0
	
	q.push(10);
	q.push(55);
	q.push(25);

	cout << q.front() << "\n";	// 10
	cout << q.back() << "\n";	// 25
	cout << q.size() << "\n";	// 3
	q.pop();
	cout << q.front() << "\n";	// 55
	q.pop();
	cout << q.size() << "\n";	// 1
	q.pop();
	cout << q.size() << "\n";	// 0

	return 0;
}
