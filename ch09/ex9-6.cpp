// 9.1.6 단순 변수 처리

void statement()
{
  code = save = firstCode(Pc);	        // 코드 가져오기
  ...
  case Gvar: case Lvar:		        // 대입문
    varAdrs = get_memAdrs(code);	// (1) 좌변 주소 구하기
    expression("=", 0);			// (2) 우변 계산
    set_dtTyp(save, DBL_T);		// (3) 대입 시 형 확정
    Dmem.set(varAdrs, stk.pop());	// (4) 대입
  ...
}


void factor()			           // 인자
{
  switch (code.kind) {
  case Gvar: case Lvar:			   // 변수의 우변 값
    chk_dtTyp(code);			   // (1) 형이 정해진 변수인가
    stk.push(Dmem.get(get_memAdrs(code))); // (2) 값을 넣는다
    break;
  ...
}
