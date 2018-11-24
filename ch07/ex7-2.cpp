// 7.2 구문 검사 방법

void syntaxChk()
{
  syntaxChk_mode = true;
  for (Pc=1; Pc<(int)intercode.size(); Pc++) {  // 모든 소스 행
    code = firstCode(Pc);
    switch (code.kind) {      	                // 토큰 분기
    case Func: case Option: case Var:
      break;
    case Else: case End: case Exit:
      ...
      break;
    case For:
      ...
      break;
    case Fcall:
      ...
      break;
    case Print: case Println:
      ...
      break;
    case Gvar: case Lvar:
      ...
      break;
    case Return:
      ...
      break;
    case EofLine:
      break;
    default:
      // 오류 표시
    }
  }
  syntaxChk_mode = false;
}



case If: case ElIf: case While:
    code = nextCode();
    (void)get_expression(0, EofLine);                      /* 식 값 */
    break;

case For:
    code = nextCode();
    (void)get_memAdrs(code);                               /* 제어 변수 주소  */
    (void)get_expression('=', 0);                          /* 초깃값          */
    (void)get_expression(To, 0);                           /* 최종값          */
    if (code.kind == Step) (void)get_expression(Step, 0);  /* 증가 값         */
    chk_EofLine();
    break;

case Gvar: case Lvar:                                      /* 대입문          */
    (void)get_memAdrs(code);                               /* 좌변 주소       */
    (void)get_expression('=', EofLine);                    /* 좌변 식 값      */
    break;
