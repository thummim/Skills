#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int v[10];

int main()

{
	unordered_map<string, int> umap;
	
	//맵에 변수 넣기
	umap.insert({ "test1", 1 });
	//아래와 같은 방법으로도 넣을 수 있음
	umap.emplace("test5", 5);
	//아래와 같이 변경 또는 추가도 가능함
	umap["test1"] = 4;

	for (auto element : umap)
	{
		//string을 cout할 때에는 string 라이브러리를 include 해야함
		cout << element.first << " :: " << element.second << '\n';
	}

	//map의 find 메소드는 해당하는 값을 찾지 못하면 end() 이터레이터를 반환함.
	auto search = umap.find("test4");

	if (search != umap.end())
	{
		cout << "found : " << search->first << " " << (*search).second << '\n';
	}
	else
	{
		cout << "not found.." << '\n';
	}

	umap["test"]++;
	cout << umap["test1"] << "\n";

	cout << umap.size() << "\n";
	umap.erase("test1");
	cout << umap.size() << "\n";

	return 0;
}
