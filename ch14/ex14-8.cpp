class Person {
  ...
  int  getAge() { return age; };
  void disp();			// 여기에는 함수의 선언만 쓴다
};

void Person::disp()		// 멤버 함수 정의
{
  cout << "n:" << name << " a:" << age << endl;
}
