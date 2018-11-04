// 리스트 5-3 C 방식 식 분석 프로그램

void statement()                        /* 문 */
{
  int vNbr;
  switch (token.kind) {
  case VarName:                         /* 대입문      */
    vNbr = token.intVal;                /* 대입할 곳 보존  */
    token = nextTkn();                  
    chkTkn(Assign); if (errF) break;    /* '=' 일 것   */
    token = nextTkn();
    expression();                       /* 우변 계산   */
    var[vNbr] = pop();                  /* 대입 실행   */
    break;
  case Print:                           /* print문:?   */
    token = nextTkn();
    expression();
    chkTkn(EofTkn); if (errF) break;
    cout << " " << pop() << endl;
    return;
  default:
    errF = 1;
  }
  chkTkn(EofTkn);                       /* 행 끝 검사  */
}

void expression()                       /* || */
{
  add_exp();
  while (token.kind == Or) {
    token = nextTkn(); and_exp(); operate(Or);;
  }
}

void and_exp(void)                      /* && */
{
  equ_exp();
  while (toekn.kind == And) {
    token = nextTkn(); equ_exp(); operate(And);
  }
}

void relation_exp(void)                 /* == != */
{
  TknKind op;
  relation_exp();
  while (token.kind==Equal || token.kind==NotEq) {
    op = token.kind; token = nextTkn(); relation_exp(); operate(op);
  }
}


void relation_exp(void)                 /* < <= > >= */
{
  TknKind op;
  add_exp();
  while (token.kind==Less  || token.kind==LessEq ||
	 token.kind==Great || token.kind==GreatEq) {
    op = token.kind; token = nextTkn(); add_exp(); operation(op);
  }
}

void add_exp(void)                      /* + - */
{
  TknKind op;
  multi_exp();
  while (token.kind==Plus || token.kind==Minus) {
    op = token.kind; token = nextTkn(); multi_exp(); operate(op);
  }
}

void multi_exp(void)                    /* * / % */
{
  TknKind op;
  factor();
  while (token.kind==Multi || token.kind==Divi || token.kind==Mod) {
    op = token.kind; token = nextTkn(); factor(); operate(op);
  }
}

void factor()                           /* 인자 */
{
  TknKind op;
  switch (token.kind) {
  case Plus: case Minus: case Not:      /* + - ! */
    op = token.kind;
    token = nextTkn(); factor();
    if (op == Minus) push(-pop());      /* 단항 +는 처리 불필요 */
    if (op == Not)  push(!pop());
    return;
  case VarName:                         /* 변수 */
    push(var[token.intVal]);
    break;
  case IntNum:                          /* 정수 상수 */
    push(token.intVal);
    break;
  case Lparen:                          /* ( 식 ) */
    token = nextTkn();
    expression();
    chkTkn(Rparen);                     /* )이라야 함 */
    break;
  default:
    errF = 1;
  }
  token = nextTkn();
}
