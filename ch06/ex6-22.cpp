// 6.8.4 함수의 실행 시작 주소 설정

int enter(SymTbl& tb, SymKind kind)
{
  ...
  if (kind = fncId)		// 함수명이라면
    tb.adrs = get_lineNo();	// 현재 행을 주소로 설정
  else {			// 변수라면
    변수의 주소 설정
  }
  ...
}
