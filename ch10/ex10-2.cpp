// 10.3 대입문

void statement()		      // 문의 처리
{
  code = save = firstCode(Pc);        // 코드 가져오기
  switch (code.kind) {
  case Gvar: case Lvar:		      // 대입문
    varAdrs = get_memAdrs(code);      // 좌변 주소 구하기
    expression("=", 0);		      // 우변 값 구하기
    set_dtTyp(save, DBL_T);	      // 좌변의 형 확정
    Dmem.set(varAdrs, stk.pop());     // 대입 실행
    ++Pc;
    break;
  ...
  }
}
