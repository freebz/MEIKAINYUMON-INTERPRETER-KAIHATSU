// 리스트 5-4 재귀 호출로 만든 식 분석 프로그램

void expression()                       /* 식 처리 시작 */
{
  term(1);
}

void term(int n)                        /* 항. n은 우선순위 */
{
  TknKind op;
  if (n == 7) { factor(); return; }
  term(n+1);
  while (n == opOrder(token.kind)) {
    op = token.kind; token = nextTkn(); term(n+1); operate(op);
  }
}

void factor()                           /* 인자 */
{
  ( 같다 )
}

int opOrder(TknKind kd)                 /* 이항 연산자의 우선수위 */
{
  switch (kd) {
  case Multi: case Divi: case Mod: return 6;    /* * / % */
  case Plus:  case Minus:          return 5;    /* + -   */
  case Less:  case LessEq:
  case Great: case GreatEq:        return 4;    /* < <= > >= */
  case Equal: case NotEq:          return 3;    /* == != */
  case And:                        return 2;    /* && */
  case Or:                         return 1;    /* || */
  default:                         return 0;    /* 해당 없음 */
  }
}
