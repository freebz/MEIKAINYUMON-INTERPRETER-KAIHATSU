#include <iostream>
#include <string>
using namespace std;

class Person {			// 클래스를 정의한다
private:			// 이후의 멤버에 접근할 수 없게 한다
  // 데이터 멤버
  string name;			// 변수를 선언(이름)
  int age;			// 변수를 선언(나이)
  
public:				// 아래 멤버를 액세스 접근 가능하게 한다  
  // 생성자                     // 이후의 멤버에 접근할 수 있게 한다
  Person()                 { name = ""; age = 0; };
  Person(string s)         { name =  s; age = 0; };
  Person(int n)            { name = ""; age = n; };
  Person(string s, int n)  { name = s ; age = n; };

  // 멤버 함수
  void setName(string s)   { name = s; };
  void setAge(int n)       { if (n<0) n=0; age = n; };
  string getName()         { return name; };
  int getAge()             { return age; };
  void disp() { cout << "n:" << name << " a:" << age << endl; };
};

int main()
{
  Person d1("Kim", 10);		// "Kim" 10으로 초기화
  Person d2("Lee", -20);	// -20을 지정

  d1.disp();			// 출력: n:Kim a:10
  d2.disp();			// 출력: n:Lee a:0

  //d1.name = "Hong";
  //d1.age = -50;
  d1.setName("Hong");
  d1.setAge(-50);		// -50을 지정
  d1.disp();			// 출력: n:Hong a:0

  cout << d1.getName() << " " << d1.getAge() << endl;
				// 출력: Hong 0
  return 0;
}
