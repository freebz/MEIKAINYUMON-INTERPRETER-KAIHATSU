// 14.6 예외 처리

#include <iostream>
using namespae std;

int main()
{
  char* p;

  try {
    p = new new char[0x7FFFFFFF]; // 아마 확보할 수 없을 것이다
  }
  catch (bad_alloc e) {
    cout << e.what() << endl;	// 출력 예; bad allocation
  }
}


catch (bad_alloc) {
  cout << "메모리를 확보할 수 없습니다\n";
}


catch (exception) {
  cout << "메모리를 확보할 수 없습니다\n";
}
