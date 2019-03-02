// 14.2 디폴트 인수

void disp(int a = 100, int b = 200 );        // 함수 선언에서 디폴트 값 지정

void disp(int a, int b)		             // 함수 본체
{
  cout << "a=" << a << " b=" << b << endl;
}


disp(11, 22);    // 일반 용법
disp(11);        // disp(11, 200);과 같다
disp();          // disp(100, 200);과 같다


void myfunc(int a, int b = 20, int c = 30);    // 맞다
void myfunc(int a = 10, int b, int c = 30);    // 틀리다
