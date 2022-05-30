#include <bits/stdc++.h>
using namespace std;
int v[10];

int main()
{
  for(int i = 1; i <= 10; i++)v[i - 1] = i;
  for(int a : v) cout << a << " ";
  cout << "\n";
  
  auto a = find(v, v + 10, 100);
  if(a == v + 10) cout << "not found" << "\n";
  
  fill(v, v +10, 10);
  for(int a : v) cout << a << " ";
  cout << "\n";
  
  return 0;
}
/*
1 2 3 4 5 6 7 8 9 10
not found
10 10 10 10 10 10 10 10 10 10
*/

// fill과 memset

//vector 초기화 하기
vector<int> v[10]; //v벡터를 10개를 생성합니다.
vector<int> v(n, 0); 0이라는 value를 가진 n개의 벡터를 생성
//vector로 2차원 배열 매트릭스 만들기
vector<vector<int> > checked;
vector <vector<int> > v(n + 1 , vector<int> (n + 1, 0));
//fill로도 초기화할 수 있다.

fill(v.begin(), b.end(), 0);
//배열초기화 shortcut : 전체 0으로 초기화한다. 일부 컴파일러에서 통하지 않을 수도
있습니다.
int dp[10] = {0,};
int dp[10][10] = {{0, } };
fill(dist, dist + MAX_N, 0);
//부분초기화 : 0번째를 0, 1번째를 1로 초기화한다.
int a[n] = {0,1};
memset(check, 0, sizeof(check));
//fill을 사용한 2차원 배열 초기화는 이렇습니다.
for(int i = 0;i < 10;i ++) fill(dp[i], dp[i]+10, 0);
fill(&arr[0][0], &arr[0][0] + n*m, k) // 이런식으로 한번에 초기화를 할 수 있습니다.
