double get_expression(int kind1, int kind2)   // 결과를 반환하는 expression
{
  expression(kind1, kind2); return stk.pop();
}

void expression(int kind1, int kind2)         /* 확인부 식 처리 */
{
  if (kind1 != 0) code = chk_nextcode(code, kind1);
  expression();
  if (kind2 != 0) code = chk_nextcode(code, kind2);
}

void expression()		              /* 일반식 처리 */
{
  term(1);
}
