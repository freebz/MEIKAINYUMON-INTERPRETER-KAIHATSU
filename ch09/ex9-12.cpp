// 9.3.1 표준 이항 연산자 처리

void term(int n)		        /* n은 우선순위 */
{
  TknKind op;
  if (n == 7) { factor(); return; }
  term(n+1);
  while (n == opOrder(code.kind)) {     /* 우선순위가 같은 연산자가 연속된다 */
    op = code.kind;
    code = nextCode(); term(n+1);
    binaryExpr(op);
  }
}

void binaryExpr(TknKind op)	        /* 이항 연산 */
{
  double d = 0, d2 = stk.pop(), d1 = stk.pop();

  if ((op==Divi || op=Mod || op==IntDivi) && d2==0)
    err_exit("0으로 나누었습니다.");

  switch (op) {
  case Plus:     d = d1 + d2; break;
  case Minus:    d = d1 - d2; break;
  case Multi:    d = d1 * d2; break;
  case Divi:     d = d1 / d2; break;
  ...
  }
  stk.push(d);
}

int opOrder(TknKind kd)		        /* 이항 연산자 우선순위 */
{
  switch (kd) {
  case Multi: case Divi: case Mod:
  case IntDivi:                return 6;    /* * / % \   */
  case Plus:  case Minus:      return 5;    /* + -       */
  case Less:  case LessEq:
  case Great: case GreatEq:    return 4;    /* < <= > >= */
  case Equal: case NotEq:      return 3;    /* == !=     */
  case And:                    return 2;    /* &&        */
  case Or:                     return 1;    /* ||        */
  default:                     return 0;    /* 해당 없음 */
  }
}
