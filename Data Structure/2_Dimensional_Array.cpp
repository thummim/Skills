#include <bits/stdc++.h>

using namespace std;
const int mxy = 3;
const int mxx = 4;

int a[mxy][mxx];

int main()
{
  for(int i = 0; i < mxy; i++)
  {
      for(int j = 0; j < mxx; j++)
      {
        a[i][j] = (i + j);
      }
  }
  
  // 좋은 예시
  for(int i = 0; i < mxy; i++)
  {
      for(int j = 0; j < mxx; j++)
      {
        cout << a[i][j] << ' ';
      }
    cout << '\n';
  }
  // 나쁜 예시
  for(int i = 0; i < mxx; i++)
  {
      for(int j = 0; j < mxy; j++)
      {
        cout << a[j][i] << ' ';
      }
    cout << '\n';
  }
  
  return 0;
}
/*
0 1 2 3
1 2 3 4
2 3 4 5
0 1 2
1 2 3
2 3 4
3 4 5
*/

// 다차원 배열을 접근할 때에는 첫번째 차원에서 두 번째 자원 순으로 탐색하는것이 성능이 좋다
// 이는 C++에서 캐시를 첫 번째 차원을 기준으로 접근하기 때문임
