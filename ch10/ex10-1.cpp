// 10.2.1 블록 처리

void block()			                      // 블록 끝까지 문을 실행
{
  TknKind k;
  while (!break_Flg && !return_Flg && !exit_Flg) {    // 종료 조건 1
    k = lookCode(Pc);				      // 다음 시작 코드
    if (k==Elif || k==Else || k==End) break;	      // 종료 조건 2
    statement();				      // 문을 차례로 실행
  }
}
