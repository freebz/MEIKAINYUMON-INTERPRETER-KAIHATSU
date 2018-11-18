// 6.8.3 인수 처리

for (; ; token=nextTkn()) {
  set_name();			    // 이름을 tmpTb에 넣는다
  tblNbr = enter(tmpTb, paraId);    // 인수를 등록한다
  setCode(Lvar, tblNbr);	    // 코드 [Lvar] [심볼 테이블 번호]를 생성
  ++Gtable[fncTblNbr].args;	    // 인수 개수를 +1
  if (token.kind != ',') break;	    // ,이면 인수가 계속된다
  setCode(',');			    // 내부 코드 [,]를 생성
}
