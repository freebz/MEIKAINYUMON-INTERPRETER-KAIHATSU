// 12.2 내장 함수 실행

void statement()		// 문
{
  ...
  switch (code.kind) {
  ...
  case Print: case Println:
    sysFncExec(code.kind);
    ++Pc;
    break;
  ...
  }
}

void factor()			// 인자
{
  switch (code.kind) {
  ...
  case Toint:
    sysFncExec(code.kind);
    break;
  case Input:
    sysFncExec(code.kind);
    break;
  ...
  }
}

void sysFncExec(TknKind kd)	// 내장 함수 실행
{
  double d;
  string s;
  switch (kd) {
  case Toint:
    code = nextCode();
    stk.push((int)get_expression('(', ')') ); // 끝수 버림
    break;
  case Input:			// ↓ input( ) 건너뛰기
    nextCode(); nextCode(); code = nextCode();
    getline(cin, s);		// 한 줄 읽기
    stk.push(atof(s.c_str()));	// 숫자로 변환해 저장
    break;
  case Print: case Println:
    do {
      code = nextCode();
      if (code.kind == String) { // 문자열 출력
	cout << cout.text; code = nextCode();
      } else {
	d = get_expression();	// 내부에서 exit의 가능성이 있다
	if (!exit_Flg) cout << d; // 수치 출력
      }
    } while ( code.kind == ','); // , 라면 파라미터가 이어진다
    if (kd == Println) cout << endl; // println이면 행을 바꾼다
    break;
  }
}
