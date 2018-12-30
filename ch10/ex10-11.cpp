// 10.8.2 exit에 의한 실행 종료 처리

int main(int argc, char *argv[])
{
  ...
  execute();
  return 0;			                  // 프로그램 종료
}

void execute()
{
  break_Flg = return_Flg = exit_Flg = false;
  ...
  while (Pc<=maxLine && !exit_Flg){               // exit_Flg라면 실행 종료
    statement();
  }
}

void statement()
{
  ...
  if (Pc>maxLine || exit_Flg) return;             // exit_Flg라면 문 종료
  ...
  switch (code.kind) {
    ...
  case While:
    for ( ; ; ) {
      ...
      block();
      if (break_Flg || return_Flg || exit_Flg) {  // exit_Flg라면 while 종료
	break_Flg = false; break;
      }
      ...
    }
    ...
    break;
  case For:
    ...
    for(; ; pc=top_line) {
      ...
      ++Pc; block();                              // exit_Flg라면 for 종료
      if (break_Flg || return_Flg || exit_Flg) {
	break_Flg = false; break;
      }
      ...
    }
    ...
    break;
  case Print: case Println:
    do {
      ...
      if (code.kind == String) {                  // 문자열 출력
	cout << code.text; code  nextCode();
      } else {                                    // 식 값 출력
	wkVal = get_expression();
	if (!exit_Flg) cout << wkVal;             // exit_Flg라면 출력하지 않고(주)
      }
    } while (code.kind = ',');
    ...
    break;
  case Exit:
    ...
    exit_Flg = true;		                  // exit_Flg 설정
    break;
  ...
  }
}

void block()
{
  ...                                             // exit_Flg라면 블록 종료
  while (!break_Flg && !return_Flg && !exit_Flg) {
    ...
    statement();
  }
}
