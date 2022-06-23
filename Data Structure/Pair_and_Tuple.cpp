#include<bits/stdc++.h>
using namespace std;
pair<int, int> pi;
tuple<int, int, int> tl;
int a, b, c;
int main()
{
  pi = {1, 2};
  tl = make_tuple(1, 2, 3);
  tie(a, b) = pi;
  cout << a << " : " << b << "\n";
  tie(a, b, c) = tl;
  cout << a << " : " << b << " : "<< c << "\n";
  return 0;
}

//pair : 두 가지의 값을 담을 때
//tuple : 세 가지 이상의 값을 넣을 때
//tie : 두 가지 이상의 값을 끄집어 낼 때 위와 같이 사용함
