// 6.4.2 함수명 선행 처리

int myname;			// int 형인 myname을 먼저 선언
myname = 100;			// 그 변수에 대입 처리한다


void myfunc(int a);		// (1) myfunc() 본체의 사양만 먼저 선언한다(함수 선언)

myfunc(10);			// (2) myfunc()을 호출한다

void myfunc(int a)		// (3) myfunc() 본체 기술
{
  ...
}
