// map을 사용한 프로그램

#include <iostream>
#include <string>
#include <map>
usin namespace std;

int main()
{
  map<string, int> m;		// string 형과 int 형 값의 쌍을 관리

  m["ccc"] = 20;		//
  m["aaa"] = 30;		// 등록한다
  m["bbb"] = 10;		//

  if (m.find("bbb") != m.end())	// 등록되어 있으면 표시한다
    cout << m["bbb"] << endl;	// 출력: 10
  return 0;
}
