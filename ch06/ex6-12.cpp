// 6.5.1 변수 선언 처리 방법

void convert()
{
  switch (토큰 종류) {
  case Var:
    varDecl();
    break;
  ...
  }
}

void varDecl()
{
  ...
  for (;;) {
    토큰 추출
    이름 중복 검사
    set_name();			     // 이름 설정
    set_aryLen();		     // (배열이면) 배열 길이 설정
    enter(tmpTb, varID);	     // 변수로 등록
    if (토큰이 ','가 아님) break;    // ,이면 변수가 계속된다.
  }
  행 끝임을 확인;
}
