// 14.5 클래스

#include <iostream>
#include <string>
using namespace std;

class Person {			// 클래스를 정의한다
public:				// 아래 멤버를 액세스 접근 가능하게 한다
  // 데이터 멤버
  string name;			// 변수를 선언(이름)
  int age;			// 변수를 선언(나이)

  // 생성자
  Person()                 { name= ""; age=0; };
  Person(string s)         { name= s;  age=0; };
  Person(int n)            { name= "", age=n; };
  Person(string s, int n)  { name=s,   age=n; };

  // 멤버 함수
  void setName(string s)   { name=s; };
  void setAge(int n)       { age=n;   };
  void disp() { cout << "n:" << name << " a:" << age << endl; };
};

int main()
{
  Person d1;			// "" 0으로 초기화
  Person d2("Kim");		// "Kim" 0으로 초기화
  Person d3(30);		// "" 30으로 초기화
  Person d4("Lee", 40);		// "Lee" 40으로 초기화

  d1.disp();			// 출력: n: a:0
  d2.disp();			// 출력: n:Kim a:0
  d3.disp();			// 출력: n:  a:30
  d4.disp();			// 출력: n:Lee a:40

  d1.name = "Hong";
  d1.age = -50;
  d1.disp();			// 출력: n:Hong a:-50

  d1.setName("Han");
  d1.setAge(60);
  d1.disp();			// 출력: n:Han a:60

  return 0;
}
