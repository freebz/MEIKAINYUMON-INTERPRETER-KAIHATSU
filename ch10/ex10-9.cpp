void statement()
{
  ...
  case While:
    ...
    block();				       // (1) 블록 실행
    if (break_Flg || return_Flg || exit_Flg) { // (5) 중단이라면
      break_Flg = false; break;		       // (6) break_Flg 초기화
    }
    ...
    break;
  case For:
    ...
    block();			               // 블록 실행
    if (break_Flg || return_Flg || exit_Flg) { // 중단이라면
      break_Flg = false; break;
    }
    ...
    break;
 case Break:
   ...
   post_if_set(break_Flg);	               // (3) break_Flg를 세팅
   ...
   break;
   ...
 }
}

void block()
{
  TknKind k;                                   // (4) break_Flg가 참이면 종료
  while (!break_Flg && !return_Flg && !exit_Flg) {
    k = lookCode(Pc);
    if (k==Elif || k==Else || k==End) break;
    statement();                               // (2) 문 실행
  }
}
