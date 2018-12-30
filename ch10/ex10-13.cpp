// 10.9.2 return에 의한 실행 종료 처리

void fncExec(int fncNbr)	// 함수 실행
{
  ...
  block();			// 함수 본체 실행
  return_Flg = false;		// 플래그 초기화
  ...
}
