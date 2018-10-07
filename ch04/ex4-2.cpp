int loopNest = 0;	 // for, while의 중첩수
bool fncDecl_F = false;  // 함수 정의 처리 중이면 참
int blkNest = 0;	 // 블록의 깊이

void convert()
{
  switch (token.kind) {
  case Func:
    fncDecl();		 // 함수 정의면 이것을 호출
    break;
  case While: case For:
    ++loopNest;		 // 루프 중첩 관리
    convert_block_set(); setCode_End();
    --loopNest;          // 루프 중첩 되돌리기
    break;
  case Break:		 // 루프 안에 아니면 오류
    if (loopNest <= 0) err_exit("잘못된 break입니다.");
    setCode(token.kind); token = nextTkn(); convert_rest();
    break;
  case Return:           // 함수 정의 안이 아니면 오류
    if (!fncDecl_F) err_exit("잘못된 return입니다.");
    setCode(token.kind); token = nextTkn(); convert_rest();
    break;
  //...
  }
}


void convert_block()     // 블록 처리
{
  //...
  ++blkNest;		 // 블록 중첩 관리
  //(블록 내부 처리)
  --blkNest;             // 블록 중첩 되돌리기
}

void fncDecl()           /* 함수 정의 */
{			 // 블록 내부라면 오류
  if(blkNest > 0) err_exit("함수 정의 위치가 바르지 않습니다.");
  fncDecl_F = true;	 // 함수 시작 플래그
  //(함수 내부 처리)
  fncDecl_F = false;     // 함수 종료
}
