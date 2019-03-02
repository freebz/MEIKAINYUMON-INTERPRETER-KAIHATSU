// 13.9 표준 함수 추가

// statement

void statement()
{
  ...
  case Print: case Println:
    sysFncExec(code.kind);
    ++Pc;
  ...
}


// factor
void factor()
{
  ...
  case Toint: case Input:
    sysFncExec(code.kind);
    break;
  ...
}


// sysFncExec

void sysFncExec(Tknkind kd)
{
  ...
  switch (kd) {
  case Toint:
    ...
  case Input:
    ...
  case Print: case Println:
    ...
  }
}
