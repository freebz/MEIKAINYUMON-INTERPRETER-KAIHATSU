// 7.3 구문 검사 지원

if (syntaxChk_mode) {
  구문 검사 처리
}
else {
  실행 처리
}


fncCall()         -- 함수 호출 처리
fncCall_syntax()  -- 함수 호출 구문 검사



void term(int n)                        /* 항 */
{
  TknKind op;
  if (n == 7) { factor(); return; }
  term(n+1);
  while (n == opOrder(code.kind)) {
    op = code.kind;
    code = nextCode(); term(n+1);
    if (syntaxChk_mode) { stk.pop(); stk.pop; stk.push(1.0); } // 구문 검사
    else binaryExpr(op);                     // 실행
  }
}

void factor()                           /* 인자 */
{
  if (syntaxChk_mode) {		        /* 구문 검사 */
    switch (kd) {
    case Not: case Minus: case Plus:
      code = nextCode(); factor(); stk.pop(); stk.push(1.0);
      break;
    case Lparen:
      expression('(', ')');
      break;
    case IntNum: case DblNum:
      stk.push(1.0); code = nextCode();
      break;
    case Gvar: case Lvar:
      (void)get_memAdrs(code); stk.push(1.0);
      break;
    case Toint: case Input:
      sysFncExec_sytax(kd);	        // 전용 함수로 검사
      break;
    case Fcall:
      fncCall_syntax(code.symNbr);      // 전용 함수로 검사
      break;
    case EofLine:
      err_exit("식이 바르지 않습니다.");
    default:
      err_exit("식 오류 :", kind_to_s(code));
    }
    return;
  }

  switch (code.kind) {		        // 실행
				        // 실행 시의 처리
  }
}



wkVal = get_expression('=', 0);


code = nextCode();
wkVal = get_expression();
